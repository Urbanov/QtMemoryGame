#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>
#include "gameboard.h"
#include "view.h"
#include "settingswindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SettingsWindow* settings = new SettingsWindow(this);
    GameBoard* board = new GameBoard(this);
    View* view = new View;
    view->setScene(board);
    ui->verticalLayout->addWidget(view);

    connect(ui->actionNewGame, &QAction::triggered, board, &GameBoard::newGame);
    connect(ui->actionSettings, &QAction::triggered, settings, &SettingsWindow::show);
    connect(settings, &SettingsWindow::sizeSettingChanged, board, &GameBoard::setSize);
    connect(board, &GameBoard::sceneRectChanged, view, [=](){ view->resizeEvent(nullptr); });
}

MainWindow::~MainWindow()
{
    delete ui;
}
