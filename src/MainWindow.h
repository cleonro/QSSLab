#pragma once

#include <memory>

#include "CSSEditor.h"

#include <QFileSystemModel>
#include <QMainWindow>
#include <QModelIndex>
#include <QPersistentModelIndex>
#include <QString>
#include <Qt3DExtras/Qt3DWindow>

#include "ui_MainWindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;

    void setupUi();

private slots:
    void on_action_Quit_triggered();
    void on_action_Open_triggered();
    void on_action_Save_triggered();
    void on_action_Save_As_triggered();

private:
    std::unique_ptr<Ui::MainWindow> ui;
    std::unique_ptr<Qt3DExtras::Qt3DWindow> qt3dWindow;
    std::unique_ptr<CSSEditor> cssEditor;
    std::unique_ptr<QFileSystemModel> fileSystemModel;
    QPersistentModelIndex watchedFileIndex;
    QString baseStyleSheet;
    QString pendingWatchedFilePath;

    void setupQt3DViewport();
    void applyStylesheetFromEditor();
    void applyStylesheetText(const QString &css);
    bool applyStylesheetFromDisk(const QString &path);
    void setupFileSystemWatcher();
    void updateFileSystemWatch(const QString &filePath);
    void assignWatchedFileIndex();
    void handleFileSystemDataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight);
    void reloadWatchedStylesheet();
};
