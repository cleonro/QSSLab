#pragma once

#include <memory>

#include "ui_CSSEditor.h"

#include <QBrush>
#include <QGraphicsScene>
#include <QHash>
#include <QPlainTextEdit>
#include <QRegularExpression>
#include <QSet>
#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QString>
#include <QVector>
#include <QWidget>

namespace Ui {
class CSSEditor;
}

class CSSSyntaxHighlighter : public QSyntaxHighlighter {
    Q_OBJECT

public:
    explicit CSSSyntaxHighlighter(QTextDocument *parent = nullptr);

protected:
    void highlightBlock(const QString &text) override;

private:
    struct HighlightRule {
        QRegularExpression pattern;
        QTextCharFormat format;
    };

    QVector<HighlightRule> rules;
    QTextCharFormat commentFormat;
};

class CSSEditor : public QWidget {
    Q_OBJECT

public:
    explicit CSSEditor(QWidget *parent = nullptr);

    bool loadFromFile(const QString &path);
    QString currentFilePath() const { return filePath; }
    QString stylesheetText() const;
    bool isModified() const;
    bool save();
    bool saveToFile(const QString &path);
    void setBaseStyleSheet(const QString &style);
    void restoreBaseStyleSheet();

    void updateStyleGraph(const QString &css);

private:
    std::unique_ptr<Ui::CSSEditor> ui;
    QPlainTextEdit *editor = nullptr;
    std::unique_ptr<CSSSyntaxHighlighter> highlighter;
    std::unique_ptr<QGraphicsScene> graphScene;
    QString filePath;
    QString baseStyleSheet;

    QHash<QString, QSet<QString>> extractColorUsage(const QString &css) const;
    QBrush buildBrushForStyle(const QString &value) const;
    QString simplifySelectorLabel(const QString &selector) const;
};
