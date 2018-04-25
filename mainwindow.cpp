#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>
#include "gameboard.h"
#include "view.h"
#include "settingswindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMessageBox* msg = new QMessageBox(this);
    SettingsWindow* settings = new SettingsWindow(this);
    GameBoard* board = new GameBoard(settings->get(), this);
    View* view = new View;
    view->setScene(board);
    ui->verticalLayout->addWidget(view);

    connect(ui->actionNewGame, &QAction::triggered, board, &GameBoard::resetGame);
    connect(ui->actionSettings, &QAction::triggered, settings, &SettingsWindow::show);
    connect(board, &GameBoard::sceneRectChanged, view, [=]() { view->resizeEvent(nullptr); });
    connect(board, &GameBoard::gameEnded, this, [=](int time) {
        msg->setText("Time: " + QString::number(time) + " seconds");
        msg->exec();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
