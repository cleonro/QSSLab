#include "MainWindow.h"

#include "CSSEditor.h"

#include <QColor>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QFileSystemModel>
#include <QMessageBox>
#include <QQuaternion>
#include <QSizePolicy>
#include <QStringConverter>
#include <QTextStream>
#include <QTimer>
#include <QVector>
#include <QVector3D>
#include <QVBoxLayout>
#include <cmath>

#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DExtras/QOrbitCameraController>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QTorusMesh>
#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DRender/QCamera>
#include <Qt3DRender/QPointLight>

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
    baseStyleSheet = styleSheet();

    setupQt3DViewport();
}

void MainWindow::on_action_Quit_triggered() {
    close();
}

void MainWindow::on_action_Open_triggered() {
    const QString filter = tr("Stylesheets (*.css *.qss);;All Files (*)");
    const QString filePath = QFileDialog::getOpenFileName(this, tr("Open Stylesheet"), QString(), filter);
    if (filePath.isEmpty()) {
        return;
    }

    if (!cssEditor) {
        cssEditor = std::make_unique<CSSEditor>(this);
        cssEditor->setBaseStyleSheet(baseStyleSheet);
    }

    if (!cssEditor->loadFromFile(filePath)) {
        QMessageBox::warning(this,
                             tr("Open Stylesheet"),
                             tr("Unable to open %1").arg(QFileInfo(filePath).fileName()));
        return;
    }

    applyStylesheetFromEditor();
    updateFileSystemWatch(filePath);

    cssEditor->show();
    cssEditor->raise();
    cssEditor->activateWindow();
}

void MainWindow::on_action_Save_triggered() {
    if (!cssEditor) {
        QMessageBox::information(this, tr("Save Stylesheet"), tr("Open a stylesheet before saving."));
        return;
    }

    if (cssEditor->currentFilePath().isEmpty()) {
        on_action_Save_As_triggered();
        return;
    }

    if (!cssEditor->save()) {
        QMessageBox::warning(this,
                             tr("Save Stylesheet"),
                             tr("Unable to save %1").arg(QFileInfo(cssEditor->currentFilePath()).fileName()));
        return;
    }

    applyStylesheetFromEditor();
    updateFileSystemWatch(cssEditor->currentFilePath());
}

void MainWindow::on_action_Save_As_triggered() {
    if (!cssEditor) {
        QMessageBox::information(this, tr("Save Stylesheet As"), tr("Open a stylesheet before saving."));
        return;
    }

    const QString filter = tr("Stylesheets (*.css *.qss);;All Files (*)");
    const QString startDir = cssEditor->currentFilePath();
    const QString filePath =
        QFileDialog::getSaveFileName(this, tr("Save Stylesheet As"), startDir, filter);

    if (filePath.isEmpty()) {
        return;
    }

    if (!cssEditor->saveToFile(filePath)) {
        QMessageBox::warning(this,
                             tr("Save Stylesheet As"),
                             tr("Unable to save %1").arg(QFileInfo(filePath).fileName()));
        return;
    }

    applyStylesheetFromEditor();
    updateFileSystemWatch(cssEditor->currentFilePath());
}

void MainWindow::applyStylesheetFromEditor() {
    if (!cssEditor) {
        return;
    }
    applyStylesheetText(cssEditor->stylesheetText());
}

void MainWindow::setupQt3DViewport() {
    if (!ui->qt3dPlaceholderWidget) {
        return;
    }

    qt3dWindow = std::make_unique<Qt3DExtras::Qt3DWindow>();
    auto *view = qt3dWindow.get();

    view->defaultFrameGraph()->setClearColor(QColor(7, 7, 20));

    auto *rootEntity = new Qt3DCore::QEntity;

    auto *torusEntity = new Qt3DCore::QEntity(rootEntity);
    auto *torusMesh = new Qt3DExtras::QTorusMesh();
    torusMesh->setRings(96);
    torusMesh->setSlices(32);
    torusMesh->setRadius(1.4f);
    torusMesh->setMinorRadius(0.35f);

    auto *torusTransform = new Qt3DCore::QTransform();
    torusTransform->setScale(3.2f);

    auto *torusMaterial = new Qt3DExtras::QPhongMaterial();
    torusMaterial->setDiffuse(QColor(90, 180, 255));
    torusMaterial->setSpecular(QColor(255, 140, 210));

    torusEntity->addComponent(torusMesh);
    torusEntity->addComponent(torusTransform);
    torusEntity->addComponent(torusMaterial);

    auto *lightEntity = new Qt3DCore::QEntity(rootEntity);
    auto *pointLight = new Qt3DRender::QPointLight(lightEntity);
    pointLight->setColor(QColor(255, 255, 255));
    pointLight->setIntensity(1.25f);

    auto *lightTransform = new Qt3DCore::QTransform();
    lightTransform->setTranslation(QVector3D(20.f, 20.f, 20.f));

    lightEntity->addComponent(pointLight);
    lightEntity->addComponent(lightTransform);

    auto *camera = view->camera();
    camera->lens()->setPerspectiveProjection(45.f, 16.f / 9.f, 0.1f, 1000.f);
    camera->setPosition(QVector3D(0.f, 0.f, 18.f));
    camera->setViewCenter(QVector3D(0.f, 0.f, 0.f));
    camera->setUpVector(QVector3D(0.f, 1.f, 0.f));

    auto *cameraController = new Qt3DExtras::QOrbitCameraController(rootEntity);
    cameraController->setCamera(camera);
    cameraController->setLinearSpeed(50.f);
    cameraController->setLookSpeed(180.f);

    view->setRootEntity(rootEntity);

    auto *container = QWidget::createWindowContainer(view, this);
    container->setMinimumSize(320, 220);
    container->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    container->setFocusPolicy(Qt::StrongFocus);

    auto *placeholderLayout = new QVBoxLayout(ui->qt3dPlaceholderWidget);
    placeholderLayout->setContentsMargins(0, 0, 0, 0);
    placeholderLayout->addWidget(container);

    auto *rotationTimer = new QTimer(container);
    rotationTimer->setInterval(16);

    QObject::connect(rotationTimer, &QTimer::timeout, container, [torusTransform]() {
        static float angle = 0.0f;
        angle = std::fmod(angle + 1.0f, 360.0f);
        const QQuaternion rotationY = QQuaternion::fromAxisAndAngle(QVector3D(0.f, 1.f, 0.f), angle);
        const QQuaternion rotationX = QQuaternion::fromAxisAndAngle(QVector3D(1.f, 0.2f, 0.f), angle * 0.5f);
        torusTransform->setRotation(rotationY * rotationX);
    });

    rotationTimer->start();
}

void MainWindow::applyStylesheetText(const QString &css) {
    setStyleSheet(css);
    if (cssEditor) {
        cssEditor->restoreBaseStyleSheet();
    }
}

bool MainWindow::applyStylesheetFromDisk(const QString &path) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream in(&file);
    in.setEncoding(QStringConverter::Utf8);
    applyStylesheetText(in.readAll());
    return true;
}

void MainWindow::setupFileSystemWatcher() {
    if (fileSystemModel) {
        return;
    }

    fileSystemModel = std::make_unique<QFileSystemModel>();
    fileSystemModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    fileSystemModel->setReadOnly(true);

    QObject::connect(fileSystemModel.get(),
                     &QFileSystemModel::dataChanged,
                     this,
                     [this](const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles) {
                         Q_UNUSED(roles);
                         handleFileSystemDataChanged(topLeft, bottomRight);
                     });

    QObject::connect(fileSystemModel.get(),
                     &QFileSystemModel::directoryLoaded,
                     this,
                     [this](const QString &) {
                         assignWatchedFileIndex();
                     });
}

void MainWindow::updateFileSystemWatch(const QString &filePath) {
    if (filePath.isEmpty()) {
        watchedFileIndex = QPersistentModelIndex();
        pendingWatchedFilePath.clear();
        return;
    }

    setupFileSystemWatcher();

    const QFileInfo info(filePath);
    pendingWatchedFilePath = info.absoluteFilePath();
    fileSystemModel->setRootPath(info.absolutePath());
    assignWatchedFileIndex();
}

void MainWindow::assignWatchedFileIndex() {
    if (pendingWatchedFilePath.isEmpty() || !fileSystemModel) {
        return;
    }

    const QModelIndex index = fileSystemModel->index(pendingWatchedFilePath);
    if (index.isValid()) {
        watchedFileIndex = QPersistentModelIndex(index);
        pendingWatchedFilePath.clear();
    }
}

void MainWindow::handleFileSystemDataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight) {
    if (!watchedFileIndex.isValid()) {
        return;
    }

    if (topLeft.model() != watchedFileIndex.model()) {
        return;
    }

    if (watchedFileIndex.parent() != topLeft.parent()) {
        return;
    }

    const int row = watchedFileIndex.row();
    if (row < topLeft.row() || row > bottomRight.row()) {
        return;
    }

    reloadWatchedStylesheet();
}

void MainWindow::reloadWatchedStylesheet() {
    if (!cssEditor) {
        return;
    }

    const QString path = cssEditor->currentFilePath();
    if (path.isEmpty()) {
        return;
    }

    if (!cssEditor->isModified()) {
        if (cssEditor->loadFromFile(path)) {
            applyStylesheetFromEditor();
        }
    } else {
        applyStylesheetFromDisk(path);
    }
}
