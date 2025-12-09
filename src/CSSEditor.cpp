#include "CSSEditor.h"

#include <QColor>
#include <QFile>
#include <QFileInfo>
#include <QFont>
#include <QFontDatabase>
#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>
#include <QMarginsF>
#include <QPainter>
#include <QPlainTextEdit>
#include <QSaveFile>
#include <QTextStream>
#include <QTextOption>
#include <QStringConverter>
#include <QFrame>

#include "ui_CSSEditor.h"

CSSSyntaxHighlighter::CSSSyntaxHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent) {
    QTextCharFormat selectorFormat;
    selectorFormat.setForeground(QColor(120, 200, 255));
    selectorFormat.setFontWeight(QFont::Bold);
    rules.push_back({QRegularExpression(R"((^[\s\t]*[^\s{][^{]+)(?=\s*\{))"), selectorFormat});

    QTextCharFormat propertyFormat;
    propertyFormat.setForeground(QColor(255, 191, 128));
    rules.push_back({QRegularExpression(R"((\b[a-zA-Z-]+)(?=\s*:))"), propertyFormat});

    QTextCharFormat valueFormat;
    valueFormat.setForeground(QColor(180, 255, 180));
    rules.push_back({QRegularExpression(R"((?<=:\s*)([^;]+))"), valueFormat});

    commentFormat.setForeground(QColor(140, 140, 140));
}

void CSSSyntaxHighlighter::highlightBlock(const QString &text) {
    for (const auto &rule : rules) {
        auto it = rule.pattern.globalMatch(text);
        while (it.hasNext()) {
            const auto match = it.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }

    /* Handle multiline comments */
    setCurrentBlockState(0);

    int start = 0;
    if (previousBlockState() != 1) {
        start = text.indexOf("/*");
    } else {
        start = 0;
    }

    while (start >= 0) {
        int end = text.indexOf("*/", start);
        int length = 0;
        if (end == -1) {
            setCurrentBlockState(1);
            length = text.length() - start;
        } else {
            length = end - start + 2;
        }
        setFormat(start, length, commentFormat);
        start = text.indexOf("/*", start + length);
    }
}

CSSEditor::CSSEditor(QWidget *parent)
    : QWidget(parent),
      ui(std::make_unique<Ui::CSSEditor>()) {
    ui->setupUi(this);
    editor = ui->cssPlainTextEdit;

    if (editor) {
        editor->setWordWrapMode(QTextOption::NoWrap);
        editor->setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));
    }

    setWindowTitle(tr("CSS Editor"));
    setAttribute(Qt::WA_DeleteOnClose, false);
    setWindowFlag(Qt::Window);
    setWindowModality(Qt::NonModal);
    resize(640, 720);

    if (editor) {
        highlighter = std::make_unique<CSSSyntaxHighlighter>(editor->document());
    }
}

bool CSSEditor::loadFromFile(const QString &path) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream in(&file);
    in.setEncoding(QStringConverter::Utf8);
    editor->setPlainText(in.readAll());
    updateStyleGraph(editor->toPlainText());

    filePath = path;
    const QFileInfo info(filePath);
    setWindowTitle(tr("CSS Editor - %1").arg(info.fileName()));
    editor->document()->setModified(false);
    return true;
}

QString CSSEditor::stylesheetText() const {
    if (!editor) {
        return {};
    }
    return editor->toPlainText();
}

bool CSSEditor::isModified() const {
    return editor && editor->document()->isModified();
}

bool CSSEditor::save() {
    if (filePath.isEmpty()) {
        return false;
    }
    return saveToFile(filePath);
}

bool CSSEditor::saveToFile(const QString &path) {
    if (!editor) {
        return false;
    }

    QSaveFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);
    out << editor->toPlainText();

    if (!file.commit()) {
        return false;
    }

    filePath = path;
    const QFileInfo info(filePath);
    setWindowTitle(tr("CSS Editor - %1").arg(info.fileName()));
    editor->document()->setModified(false);
    updateStyleGraph(editor->toPlainText());
    return true;
}

void CSSEditor::setBaseStyleSheet(const QString &style) {
    baseStyleSheet = style;
    restoreBaseStyleSheet();
}

void CSSEditor::restoreBaseStyleSheet() {
    setStyleSheet(baseStyleSheet);
}

QHash<QString, QSet<QString>> CSSEditor::extractColorUsage(const QString &css) const {
    QHash<QString, QSet<QString>> colorToSelectors;

    // Basic block parser: selectors { body }
    const QRegularExpression blockRegex(R"(([^{}]+)\{([^{}]*)\})",
                                       QRegularExpression::DotMatchesEverythingOption);
    const QRegularExpression colorRegex(
        R"((#(?:[0-9a-fA-F]{3,8}))|(rgba?\([^)]*\))|(hsla?\([^)]*\))|(hsv[a]?\([^)]*\))|(q(?:linear|radial|conical)gradient\([^)]*\))|(gradient\([^)]*\)))",
        QRegularExpression::CaseInsensitiveOption);
    const QRegularExpression valueRegex(R"(:\s*([^;]+))",
                                        QRegularExpression::DotMatchesEverythingOption);

    auto blockIt = blockRegex.globalMatch(css);
    while (blockIt.hasNext()) {
        const auto match = blockIt.next();
        const QString selectorsText = match.captured(1);
        const QString body = match.captured(2);

        QStringList selectors = selectorsText.split(',', Qt::SkipEmptyParts);
        for (QString &sel : selectors) {
            sel = sel.trimmed();
        }

        QStringList foundColors;

        // Explicit color patterns (#hex, rgb/rgba, hsl/hsla, gradients).
        auto colorIt = colorRegex.globalMatch(body);
        while (colorIt.hasNext()) {
            const auto colorMatch = colorIt.next();
            foundColors.append(colorMatch.captured(0).trimmed());
        }

        // Fallback for named colors in property values.
        auto valueIt = valueRegex.globalMatch(body);
        while (valueIt.hasNext()) {
            const QString valueText = valueIt.next().captured(1);
            const QStringList tokens = valueText.split(QRegularExpression(R"([,\s]+)"),
                                                       Qt::SkipEmptyParts);
            for (const QString &token : tokens) {
                const QString trimmed = token.trimmed();
                if (trimmed.isEmpty()) {
                    continue;
                }
                const QColor namedColor(trimmed);
                if (namedColor.isValid() && !foundColors.contains(trimmed, Qt::CaseInsensitive)) {
                    foundColors.append(trimmed);
                }
            }
        }

        for (const QString &colorValue : foundColors) {
            for (const QString &selector : selectors) {
                if (!selector.isEmpty()) {
                    colorToSelectors[colorValue].insert(selector);
                }
            }
        }
    }

    return colorToSelectors;
}

QBrush CSSEditor::buildBrushForStyle(const QString &value) const {
    const QString trimmed = value.trimmed();
    QColor solidColor(trimmed);
    if (solidColor.isValid() && !trimmed.startsWith("gradient", Qt::CaseInsensitive)) {
        return QBrush(solidColor);
    }

    // Render a small frame with the style value as background to capture gradients.
    const QSize previewSize(140, 50);
    QFrame frame;
    frame.setStyleSheet(QString("QFrame { background: %1; border-radius: 6px; }").arg(trimmed));
    frame.resize(previewSize);

    QPixmap pixmap(previewSize);
    pixmap.fill(Qt::transparent);
    frame.render(&pixmap);

    return QBrush(pixmap);
}

void CSSEditor::updateStyleGraph(const QString &css) {
    if (!ui || !ui->styleGraphView) {
        return;
    }

    if (!graphScene) {
        graphScene = std::make_unique<QGraphicsScene>(this);
    }

    graphScene->clear();
    ui->styleGraphView->setScene(graphScene.get());

    const auto colorUsage = extractColorUsage(css);
    if (colorUsage.isEmpty()) {
        graphScene->addSimpleText(tr("No colors or gradients detected."));
        return;
    }

    // Collect selectors to lay out on the right side.
    QSet<QString> selectorSet;
    for (auto it = colorUsage.constBegin(); it != colorUsage.constEnd(); ++it) {
        selectorSet.unite(it.value());
    }
    const QList<QString> selectors = selectorSet.values();
    const QList<QString> colors = colorUsage.keys();

    const double colorX = 0.0;
    const double selectorX = 360.0;
    const double colorSpacing = 80.0;
    const double selectorSpacing = 60.0;
    const QSizeF colorNodeSize(180.0, 60.0);
    const QSizeF selectorNodeSize(180.0, 40.0);

    QHash<QString, QPointF> colorCenters;
    QHash<QString, QPointF> selectorCenters;

    int colorIndex = 0;
    for (const QString &color : colors) {
        const double y = colorIndex * colorSpacing;
        const QRectF rect(colorX, y, colorNodeSize.width(), colorNodeSize.height());
        const QBrush brush = buildBrushForStyle(color);
        auto *rectItem = graphScene->addRect(rect, QPen(QColor(40, 40, 40)), brush);
        rectItem->setToolTip(color);

        auto *label = new QGraphicsSimpleTextItem(color, rectItem);
        label->setBrush(QColor(0, 0, 0));
        label->setPos(8.0, 8.0);

        const QRectF labelRect = label->boundingRect().marginsAdded(QMarginsF(6.0, 4.0, 6.0, 4.0));
        auto *labelBg = new QGraphicsRectItem(labelRect, rectItem);
        labelBg->setBrush(QColor(255, 255, 255, 255));
        labelBg->setPen(Qt::NoPen);
        labelBg->setPos(label->pos());
        label->setZValue(1.0);

        colorCenters.insert(color, rect.center());
        ++colorIndex;
    }

    int selectorIndex = 0;
    for (const QString &selector : selectors) {
        const double y = selectorIndex * selectorSpacing;
        const QRectF rect(selectorX, y, selectorNodeSize.width(), selectorNodeSize.height());
        auto *rectItem = graphScene->addRect(rect,
                                             QPen(QColor(60, 60, 80)),
                                             QBrush(QColor(245, 245, 250)));
        rectItem->setToolTip(selector);

        const QString labelText = simplifySelectorLabel(selector);
        auto *label = new QGraphicsSimpleTextItem(labelText, rectItem);
        label->setBrush(QColor(20, 20, 30));
        label->setPos(8.0, 8.0);

        selectorCenters.insert(selector, rect.center());
        ++selectorIndex;
    }

    QPen edgePen(QColor(90, 90, 120));
    edgePen.setWidthF(1.4);
    edgePen.setCosmetic(true);

    for (auto it = colorUsage.constBegin(); it != colorUsage.constEnd(); ++it) {
        const QPointF source = colorCenters.value(it.key());
        for (const QString &selector : it.value()) {
            const QPointF target = selectorCenters.value(selector);
            graphScene->addLine(QLineF(source, target), edgePen);
        }
    }

    graphScene->setSceneRect(graphScene->itemsBoundingRect().marginsAdded(QMarginsF(20, 20, 20, 20)));
}

QString CSSEditor::simplifySelectorLabel(const QString &selector) const {
    QString label = selector.trimmed();
    // Drop pseudo states, subcontrols, ids, classes, and descendant combinators.
    const int cut = label.indexOf(QRegularExpression(R"([:#.\s])"));
    if (cut > 0) {
        label = label.left(cut);
    }
    if (label.isEmpty()) {
        // Fallback to first token.
        label = selector.section(QRegularExpression(R"(\s+)"), 0, 0);
    }
    return label;
}
