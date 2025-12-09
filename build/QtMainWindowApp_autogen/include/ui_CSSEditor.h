/********************************************************************************
** Form generated from reading UI file 'CSSEditor.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSSEDITOR_H
#define UI_CSSEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CSSEditor
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QPlainTextEdit *cssPlainTextEdit;
    QGraphicsView *styleGraphView;

    void setupUi(QWidget *CSSEditor)
    {
        if (CSSEditor->objectName().isEmpty())
            CSSEditor->setObjectName("CSSEditor");
        CSSEditor->resize(640, 720);
        verticalLayout = new QVBoxLayout(CSSEditor);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(CSSEditor);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(6);
        cssPlainTextEdit = new QPlainTextEdit(splitter);
        cssPlainTextEdit->setObjectName("cssPlainTextEdit");
        splitter->addWidget(cssPlainTextEdit);
        styleGraphView = new QGraphicsView(splitter);
        styleGraphView->setObjectName("styleGraphView");
        styleGraphView->setMinimumSize(QSize(0, 220));
        styleGraphView->setFrameShape(QFrame::NoFrame);
        styleGraphView->setRenderHint(QPainter::Antialiasing);
        splitter->addWidget(styleGraphView);

        verticalLayout->addWidget(splitter);


        retranslateUi(CSSEditor);

        QMetaObject::connectSlotsByName(CSSEditor);
    } // setupUi

    void retranslateUi(QWidget *CSSEditor)
    {
        CSSEditor->setWindowTitle(QCoreApplication::translate("CSSEditor", "CSS Editor", nullptr));
        cssPlainTextEdit->setPlaceholderText(QCoreApplication::translate("CSSEditor", "Open a stylesheet to begin editing...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CSSEditor: public Ui_CSSEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSSEDITOR_H
