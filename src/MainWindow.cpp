#include "MainWindow.h"

#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(std::make_unique<Ui::MainWindow>()) {
    setupUi();
}

void MainWindow::setupUi() {
    ui->setupUi(this);
    resize(1024, 768);

    QFile styleFile(":/styles/fancy.qss");
    if (styleFile.open(QFile::ReadOnly | QFile::Text)) {
        // Apply the bundled fancy stylesheet to the main window.
        setStyleSheet(QString::fromUtf8(styleFile.readAll()));
    }
}

void MainWindow::on_action_Quit_triggered() {
    close();
}
