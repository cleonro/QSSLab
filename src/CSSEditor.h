#pragma once

#include <memory>

#include <QPlainTextEdit>
#include <QRegularExpression>
#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QString>
#include <QVector>
#include <QWidget>

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

private:
    void setupEditor();

    QPlainTextEdit *editor = nullptr;
    std::unique_ptr<CSSSyntaxHighlighter> highlighter;
    QString filePath;
};
