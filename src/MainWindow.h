#pragma once

#include "CSSEditor.h"

#include <memory>

#include <QMainWindow>
#include <Qt3DExtras/Qt3DWindow>

#include "ui_MainWindow.h"

class CSSEditor;

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

private:
    std::unique_ptr<Ui::MainWindow> ui;
    std::unique_ptr<Qt3DExtras::Qt3DWindow> qt3dWindow;
    std::unique_ptr<CSSEditor> cssEditor;

    void setupQt3DViewport();
};
