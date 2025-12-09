#include "CSSEditor.h"

#include <QColor>
#include <QFile>
#include <QFileInfo>
#include <QFont>
#include <QFontDatabase>
#include <QPlainTextEdit>
#include <QSaveFile>
#include <QTextStream>
#include <QTextOption>
#include <QStringConverter>

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
    return true;
}

void CSSEditor::setBaseStyleSheet(const QString &style) {
    baseStyleSheet = style;
    restoreBaseStyleSheet();
}

void CSSEditor::restoreBaseStyleSheet() {
    setStyleSheet(baseStyleSheet);
}
