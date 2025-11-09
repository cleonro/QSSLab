#pragma once

#include <QMainWindow>
#include <memory>

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

private:
    std::unique_ptr<Ui::MainWindow> ui;
};
