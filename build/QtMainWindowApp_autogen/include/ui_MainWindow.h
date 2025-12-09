/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Quit;
    QAction *action_Open;
    QAction *action_Save;
    QAction *action_Save_As;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *heroTitleLabel;
    QLabel *heroSubtitleLabel;
    QSplitter *mainContentSplitter;
    QWidget *interactionPanel;
    QVBoxLayout *interactionLayout;
    QGroupBox *buttonsGroup;
    QHBoxLayout *horizontalLayout;
    QPushButton *primaryButton;
    QPushButton *secondaryButton;
    QPushButton *disabledButton;
    QGroupBox *inputGroup;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *emailLabel;
    QLineEdit *emailLineEdit;
    QLabel *notesLabel;
    QPlainTextEdit *notesPlainTextEdit;
    QGroupBox *selectionGroup;
    QVBoxLayout *selectionLayout;
    QLabel *selectionHintLabel;
    QHBoxLayout *selectionOptionsLayout;
    QGroupBox *radioOptionsGroup;
    QVBoxLayout *radioLayout;
    QRadioButton *radioStudio;
    QRadioButton *radioLive;
    QRadioButton *radioAmbient;
    QGroupBox *checkOptionsGroup;
    QVBoxLayout *checkLayout;
    QCheckBox *gridCheckBox;
    QCheckBox *contrastCheckBox;
    QCheckBox *motionCheckBox;
    QSpacerItem *interactionSpacer;
    QGroupBox *qt3dPreviewGroup;
    QVBoxLayout *qt3dPreviewLayout;
    QLabel *qt3dDescriptionLabel;
    QWidget *qt3dPlaceholderWidget;
    QWidget *insightsPanel;
    QVBoxLayout *insightsLayout;
    QGroupBox *dataViewsGroup;
    QVBoxLayout *dataLayout;
    QFormLayout *comboFormLayout;
    QLabel *themeLabel;
    QComboBox *themeComboBox;
    QLabel *accentLabel;
    QComboBox *accentComboBox;
    QTreeWidget *navigationTreeWidget;
    QListWidget *variantListWidget;
    QGroupBox *scrollShowcaseGroup;
    QVBoxLayout *verticalLayoutInner;
    QLabel *scrollHintLabel;
    QScrollArea *previewScrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *scrollAreaLayout;
    QTextEdit *longTextEdit;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Edit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1719, 1190);
        action_Quit = new QAction(MainWindow);
        action_Quit->setObjectName("action_Quit");
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName("action_Open");
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName("action_Save");
        action_Save_As = new QAction(MainWindow);
        action_Save_As->setObjectName("action_Save_As");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(18);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(24, 24, 24, 24);
        heroTitleLabel = new QLabel(centralwidget);
        heroTitleLabel->setObjectName("heroTitleLabel");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(heroTitleLabel->sizePolicy().hasHeightForWidth());
        heroTitleLabel->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(heroTitleLabel);

        heroSubtitleLabel = new QLabel(centralwidget);
        heroSubtitleLabel->setObjectName("heroSubtitleLabel");
        sizePolicy.setHeightForWidth(heroSubtitleLabel->sizePolicy().hasHeightForWidth());
        heroSubtitleLabel->setSizePolicy(sizePolicy);
        heroSubtitleLabel->setWordWrap(true);

        verticalLayout->addWidget(heroSubtitleLabel);

        mainContentSplitter = new QSplitter(centralwidget);
        mainContentSplitter->setObjectName("mainContentSplitter");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mainContentSplitter->sizePolicy().hasHeightForWidth());
        mainContentSplitter->setSizePolicy(sizePolicy1);
        mainContentSplitter->setOrientation(Qt::Orientation::Horizontal);
        mainContentSplitter->setHandleWidth(10);
        interactionPanel = new QWidget(mainContentSplitter);
        interactionPanel->setObjectName("interactionPanel");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(interactionPanel->sizePolicy().hasHeightForWidth());
        interactionPanel->setSizePolicy(sizePolicy2);
        interactionLayout = new QVBoxLayout(interactionPanel);
        interactionLayout->setSpacing(16);
        interactionLayout->setObjectName("interactionLayout");
        interactionLayout->setContentsMargins(0, 0, 0, 0);
        buttonsGroup = new QGroupBox(interactionPanel);
        buttonsGroup->setObjectName("buttonsGroup");
        horizontalLayout = new QHBoxLayout(buttonsGroup);
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(16, 16, 16, 16);
        primaryButton = new QPushButton(buttonsGroup);
        primaryButton->setObjectName("primaryButton");

        horizontalLayout->addWidget(primaryButton);

        secondaryButton = new QPushButton(buttonsGroup);
        secondaryButton->setObjectName("secondaryButton");

        horizontalLayout->addWidget(secondaryButton);

        disabledButton = new QPushButton(buttonsGroup);
        disabledButton->setObjectName("disabledButton");
        disabledButton->setEnabled(false);

        horizontalLayout->addWidget(disabledButton);


        interactionLayout->addWidget(buttonsGroup);

        inputGroup = new QGroupBox(interactionPanel);
        inputGroup->setObjectName("inputGroup");
        formLayout = new QFormLayout(inputGroup);
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignmentFlag::AlignLeading);
        formLayout->setFormAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        formLayout->setHorizontalSpacing(16);
        formLayout->setVerticalSpacing(12);
        nameLabel = new QLabel(inputGroup);
        nameLabel->setObjectName("nameLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, nameLabel);

        nameLineEdit = new QLineEdit(inputGroup);
        nameLineEdit->setObjectName("nameLineEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, nameLineEdit);

        emailLabel = new QLabel(inputGroup);
        emailLabel->setObjectName("emailLabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, emailLabel);

        emailLineEdit = new QLineEdit(inputGroup);
        emailLineEdit->setObjectName("emailLineEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, emailLineEdit);

        notesLabel = new QLabel(inputGroup);
        notesLabel->setObjectName("notesLabel");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, notesLabel);

        notesPlainTextEdit = new QPlainTextEdit(inputGroup);
        notesPlainTextEdit->setObjectName("notesPlainTextEdit");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, notesPlainTextEdit);


        interactionLayout->addWidget(inputGroup);

        selectionGroup = new QGroupBox(interactionPanel);
        selectionGroup->setObjectName("selectionGroup");
        selectionLayout = new QVBoxLayout(selectionGroup);
        selectionLayout->setSpacing(12);
        selectionLayout->setObjectName("selectionLayout");
        selectionLayout->setContentsMargins(16, 16, 16, 16);
        selectionHintLabel = new QLabel(selectionGroup);
        selectionHintLabel->setObjectName("selectionHintLabel");
        selectionHintLabel->setWordWrap(true);

        selectionLayout->addWidget(selectionHintLabel);

        selectionOptionsLayout = new QHBoxLayout();
        selectionOptionsLayout->setSpacing(16);
        selectionOptionsLayout->setObjectName("selectionOptionsLayout");
        radioOptionsGroup = new QGroupBox(selectionGroup);
        radioOptionsGroup->setObjectName("radioOptionsGroup");
        radioLayout = new QVBoxLayout(radioOptionsGroup);
        radioLayout->setSpacing(8);
        radioLayout->setObjectName("radioLayout");
        radioStudio = new QRadioButton(radioOptionsGroup);
        radioStudio->setObjectName("radioStudio");
        radioStudio->setChecked(true);

        radioLayout->addWidget(radioStudio);

        radioLive = new QRadioButton(radioOptionsGroup);
        radioLive->setObjectName("radioLive");

        radioLayout->addWidget(radioLive);

        radioAmbient = new QRadioButton(radioOptionsGroup);
        radioAmbient->setObjectName("radioAmbient");

        radioLayout->addWidget(radioAmbient);


        selectionOptionsLayout->addWidget(radioOptionsGroup);

        checkOptionsGroup = new QGroupBox(selectionGroup);
        checkOptionsGroup->setObjectName("checkOptionsGroup");
        checkLayout = new QVBoxLayout(checkOptionsGroup);
        checkLayout->setSpacing(8);
        checkLayout->setObjectName("checkLayout");
        gridCheckBox = new QCheckBox(checkOptionsGroup);
        gridCheckBox->setObjectName("gridCheckBox");
        gridCheckBox->setChecked(true);

        checkLayout->addWidget(gridCheckBox);

        contrastCheckBox = new QCheckBox(checkOptionsGroup);
        contrastCheckBox->setObjectName("contrastCheckBox");

        checkLayout->addWidget(contrastCheckBox);

        motionCheckBox = new QCheckBox(checkOptionsGroup);
        motionCheckBox->setObjectName("motionCheckBox");

        checkLayout->addWidget(motionCheckBox);


        selectionOptionsLayout->addWidget(checkOptionsGroup);


        selectionLayout->addLayout(selectionOptionsLayout);


        interactionLayout->addWidget(selectionGroup);

        interactionSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        interactionLayout->addItem(interactionSpacer);

        mainContentSplitter->addWidget(interactionPanel);
        qt3dPreviewGroup = new QGroupBox(mainContentSplitter);
        qt3dPreviewGroup->setObjectName("qt3dPreviewGroup");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(qt3dPreviewGroup->sizePolicy().hasHeightForWidth());
        qt3dPreviewGroup->setSizePolicy(sizePolicy3);
        qt3dPreviewGroup->setMinimumSize(QSize(520, 420));
        qt3dPreviewLayout = new QVBoxLayout(qt3dPreviewGroup);
        qt3dPreviewLayout->setSpacing(12);
        qt3dPreviewLayout->setObjectName("qt3dPreviewLayout");
        qt3dPreviewLayout->setContentsMargins(16, 16, 16, 16);
        qt3dDescriptionLabel = new QLabel(qt3dPreviewGroup);
        qt3dDescriptionLabel->setObjectName("qt3dDescriptionLabel");
        qt3dDescriptionLabel->setWordWrap(true);

        qt3dPreviewLayout->addWidget(qt3dDescriptionLabel);

        qt3dPlaceholderWidget = new QWidget(qt3dPreviewGroup);
        qt3dPlaceholderWidget->setObjectName("qt3dPlaceholderWidget");
        sizePolicy3.setHeightForWidth(qt3dPlaceholderWidget->sizePolicy().hasHeightForWidth());
        qt3dPlaceholderWidget->setSizePolicy(sizePolicy3);
        qt3dPlaceholderWidget->setMinimumSize(QSize(480, 360));

        qt3dPreviewLayout->addWidget(qt3dPlaceholderWidget);

        mainContentSplitter->addWidget(qt3dPreviewGroup);
        insightsPanel = new QWidget(mainContentSplitter);
        insightsPanel->setObjectName("insightsPanel");
        sizePolicy2.setHeightForWidth(insightsPanel->sizePolicy().hasHeightForWidth());
        insightsPanel->setSizePolicy(sizePolicy2);
        insightsLayout = new QVBoxLayout(insightsPanel);
        insightsLayout->setSpacing(16);
        insightsLayout->setObjectName("insightsLayout");
        insightsLayout->setContentsMargins(0, 0, 0, 0);
        dataViewsGroup = new QGroupBox(insightsPanel);
        dataViewsGroup->setObjectName("dataViewsGroup");
        dataLayout = new QVBoxLayout(dataViewsGroup);
        dataLayout->setSpacing(14);
        dataLayout->setObjectName("dataLayout");
        dataLayout->setContentsMargins(16, 16, 16, 16);
        comboFormLayout = new QFormLayout();
        comboFormLayout->setObjectName("comboFormLayout");
        comboFormLayout->setHorizontalSpacing(16);
        comboFormLayout->setVerticalSpacing(10);
        themeLabel = new QLabel(dataViewsGroup);
        themeLabel->setObjectName("themeLabel");

        comboFormLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, themeLabel);

        themeComboBox = new QComboBox(dataViewsGroup);
        themeComboBox->addItem(QString());
        themeComboBox->addItem(QString());
        themeComboBox->addItem(QString());
        themeComboBox->setObjectName("themeComboBox");

        comboFormLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, themeComboBox);

        accentLabel = new QLabel(dataViewsGroup);
        accentLabel->setObjectName("accentLabel");

        comboFormLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, accentLabel);

        accentComboBox = new QComboBox(dataViewsGroup);
        accentComboBox->addItem(QString());
        accentComboBox->addItem(QString());
        accentComboBox->addItem(QString());
        accentComboBox->setObjectName("accentComboBox");
        accentComboBox->setEditable(true);

        comboFormLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, accentComboBox);


        dataLayout->addLayout(comboFormLayout);

        navigationTreeWidget = new QTreeWidget(dataViewsGroup);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(navigationTreeWidget);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(navigationTreeWidget);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        navigationTreeWidget->setObjectName("navigationTreeWidget");
        navigationTreeWidget->setHeaderHidden(false);

        dataLayout->addWidget(navigationTreeWidget);

        variantListWidget = new QListWidget(dataViewsGroup);
        new QListWidgetItem(variantListWidget);
        new QListWidgetItem(variantListWidget);
        new QListWidgetItem(variantListWidget);
        new QListWidgetItem(variantListWidget);
        variantListWidget->setObjectName("variantListWidget");
        variantListWidget->setSelectionMode(QAbstractItemView::SelectionMode::MultiSelection);

        dataLayout->addWidget(variantListWidget);


        insightsLayout->addWidget(dataViewsGroup);

        scrollShowcaseGroup = new QGroupBox(insightsPanel);
        scrollShowcaseGroup->setObjectName("scrollShowcaseGroup");
        verticalLayoutInner = new QVBoxLayout(scrollShowcaseGroup);
        verticalLayoutInner->setObjectName("verticalLayoutInner");
        verticalLayoutInner->setContentsMargins(16, 16, 16, 16);
        scrollHintLabel = new QLabel(scrollShowcaseGroup);
        scrollHintLabel->setObjectName("scrollHintLabel");

        verticalLayoutInner->addWidget(scrollHintLabel);

        previewScrollArea = new QScrollArea(scrollShowcaseGroup);
        previewScrollArea->setObjectName("previewScrollArea");
        previewScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 394, 386));
        scrollAreaLayout = new QVBoxLayout(scrollAreaWidgetContents);
        scrollAreaLayout->setSpacing(8);
        scrollAreaLayout->setObjectName("scrollAreaLayout");
        scrollAreaLayout->setContentsMargins(0, 0, 0, 0);
        longTextEdit = new QTextEdit(scrollAreaWidgetContents);
        longTextEdit->setObjectName("longTextEdit");
        longTextEdit->setReadOnly(true);

        scrollAreaLayout->addWidget(longTextEdit);

        previewScrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayoutInner->addWidget(previewScrollArea);


        insightsLayout->addWidget(scrollShowcaseGroup);

        mainContentSplitter->addWidget(insightsPanel);

        verticalLayout->addWidget(mainContentSplitter);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1719, 23));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName("menu_File");
        menu_Edit = new QMenu(menuBar);
        menu_Edit->setObjectName("menu_Edit");
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Edit->menuAction());
        menu_File->addAction(action_Open);
        menu_File->addAction(action_Save);
        menu_File->addAction(action_Save_As);
        menu_File->addAction(action_Quit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Qt Main Window", nullptr));
        action_Quit->setText(QCoreApplication::translate("MainWindow", "&Quit", nullptr));
        action_Open->setText(QCoreApplication::translate("MainWindow", "&Open...", nullptr));
        action_Save->setText(QCoreApplication::translate("MainWindow", "&Save", nullptr));
        action_Save_As->setText(QCoreApplication::translate("MainWindow", "Save &As...", nullptr));
#if QT_CONFIG(tooltip)
        centralwidget->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        heroTitleLabel->setText(QCoreApplication::translate("MainWindow", "Midnight Aurora Interface Sampler", nullptr));
        heroSubtitleLabel->setText(QCoreApplication::translate("MainWindow", "Interact with the controls below to preview the gradients, typography, and interaction states defined by the stylesheet.", nullptr));
        buttonsGroup->setTitle(QCoreApplication::translate("MainWindow", "Buttons & Actions", nullptr));
#if QT_CONFIG(tooltip)
        primaryButton->setToolTip(QCoreApplication::translate("MainWindow", "Hover to see the glowing accent and press effect.", nullptr));
#endif // QT_CONFIG(tooltip)
        primaryButton->setText(QCoreApplication::translate("MainWindow", "Primary Action", nullptr));
#if QT_CONFIG(tooltip)
        secondaryButton->setToolTip(QCoreApplication::translate("MainWindow", "Buttons inherit the same gradient palette.", nullptr));
#endif // QT_CONFIG(tooltip)
        secondaryButton->setText(QCoreApplication::translate("MainWindow", "Secondary", nullptr));
        disabledButton->setText(QCoreApplication::translate("MainWindow", "Disabled State", nullptr));
        inputGroup->setTitle(QCoreApplication::translate("MainWindow", "Form Inputs", nullptr));
        nameLabel->setText(QCoreApplication::translate("MainWindow", "Full name", nullptr));
        nameLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter your name", nullptr));
        emailLabel->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        emailLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "name@example.com", nullptr));
        notesLabel->setText(QCoreApplication::translate("MainWindow", "Notes", nullptr));
        notesPlainTextEdit->setPlainText(QCoreApplication::translate("MainWindow", "Weekly status: gradients, hover states, and scrollbars are ready for review.", nullptr));
        selectionGroup->setTitle(QCoreApplication::translate("MainWindow", "Selection Controls", nullptr));
        selectionHintLabel->setText(QCoreApplication::translate("MainWindow", "Toggle between presentation modes and opt-in to contextual tips.", nullptr));
        radioOptionsGroup->setTitle(QCoreApplication::translate("MainWindow", "Experience Mode", nullptr));
        radioStudio->setText(QCoreApplication::translate("MainWindow", "Studio Spotlight", nullptr));
        radioLive->setText(QCoreApplication::translate("MainWindow", "Live Preview", nullptr));
        radioAmbient->setText(QCoreApplication::translate("MainWindow", "Ambient Loop", nullptr));
        checkOptionsGroup->setTitle(QCoreApplication::translate("MainWindow", "Overlays", nullptr));
        gridCheckBox->setText(QCoreApplication::translate("MainWindow", "Guides & grid", nullptr));
        contrastCheckBox->setText(QCoreApplication::translate("MainWindow", "Contrast warnings", nullptr));
        motionCheckBox->setText(QCoreApplication::translate("MainWindow", "Reduced motion", nullptr));
        qt3dPreviewGroup->setTitle(QCoreApplication::translate("MainWindow", "Immersive 3D Preview", nullptr));
        qt3dDescriptionLabel->setText(QCoreApplication::translate("MainWindow", "A panoramic Qt 3D viewport anchors the experience by continuously animating a glowing torus.", nullptr));
        dataViewsGroup->setTitle(QCoreApplication::translate("MainWindow", "Data & Navigation", nullptr));
        themeLabel->setText(QCoreApplication::translate("MainWindow", "Theme preset", nullptr));
        themeComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Obsidian Drift", nullptr));
        themeComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Lumina Frost", nullptr));
        themeComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Solar Verge", nullptr));

        accentLabel->setText(QCoreApplication::translate("MainWindow", "Accent palette", nullptr));
        accentComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Emerald Pulse", nullptr));
        accentComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Spectrum Tide", nullptr));
        accentComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Nebula Ember", nullptr));

        QTreeWidgetItem *___qtreewidgetitem = navigationTreeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "State", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "Section", nullptr));

        const bool __sortingEnabled = navigationTreeWidget->isSortingEnabled();
        navigationTreeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = navigationTreeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(1, QCoreApplication::translate("MainWindow", "Online", nullptr));
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("MainWindow", "Dashboards", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(1, QCoreApplication::translate("MainWindow", "Synced", nullptr));
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("MainWindow", "Insights", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(1, QCoreApplication::translate("MainWindow", "Pending", nullptr));
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("MainWindow", "Alerts", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = navigationTreeWidget->topLevelItem(1);
        ___qtreewidgetitem4->setText(1, QCoreApplication::translate("MainWindow", "Offline", nullptr));
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("MainWindow", "Collections", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem4->child(0);
        ___qtreewidgetitem5->setText(1, QCoreApplication::translate("MainWindow", "Pinned", nullptr));
        ___qtreewidgetitem5->setText(0, QCoreApplication::translate("MainWindow", "Favorites", nullptr));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem4->child(1);
        ___qtreewidgetitem6->setText(1, QCoreApplication::translate("MainWindow", "Cold", nullptr));
        ___qtreewidgetitem6->setText(0, QCoreApplication::translate("MainWindow", "Archive", nullptr));
        navigationTreeWidget->setSortingEnabled(__sortingEnabled);


        const bool __sortingEnabled1 = variantListWidget->isSortingEnabled();
        variantListWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = variantListWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "Minimal HUD", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = variantListWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "Glyph Overlay", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = variantListWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "Pulse Beacons", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = variantListWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("MainWindow", "Zen Flow", nullptr));
        variantListWidget->setSortingEnabled(__sortingEnabled1);

        scrollShowcaseGroup->setTitle(QCoreApplication::translate("MainWindow", "Scrollable Content", nullptr));
        scrollHintLabel->setText(QCoreApplication::translate("MainWindow", "Use the scrollbar to preview the custom handle and hover colors.", nullptr));
        longTextEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Fira Sans'; font-size:13px;\">Aurora gradients wash across the navigation panels.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Fira Sans'; font-size:13px;\">Buttons glow subtly when hovered and compress on press.</span></p>\n"
"<p style=\" margin-top"
                        ":12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Fira Sans'; font-size:13px;\">Inputs feature translucent backgrounds with vibrant selection.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Fira Sans'; font-size:13px;\">Scrollbars adopt smooth pill handles to keep the look cohesive.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Fira Sans'; font-size:13px;\">Tooltips keep the same palette with crisp borders.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Fira Sans'; font-size:13px;\">Status messages sit on a diffused glass panel along the bottom.</span></p>\n"
"<p style=\" margin-to"
                        "p:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Fira Sans'; font-size:13px;\">Experiment with the controls to see every state in action.</span></p></body></html>", nullptr));
        menu_File->setTitle(QCoreApplication::translate("MainWindow", "&File", nullptr));
        menu_Edit->setTitle(QCoreApplication::translate("MainWindow", "&Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
