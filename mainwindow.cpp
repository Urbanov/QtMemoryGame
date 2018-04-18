#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>
#include "gameboard.h"
#include "view.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GameBoard* board = new GameBoard(10, 7);
    View* view = new View;
    view->setScene(board);
    ui->verticalLayout->addWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}
