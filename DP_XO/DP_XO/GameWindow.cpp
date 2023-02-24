#include "GameWindow.h"
#include "ui_GameWindow.h"

GameWindow::GameWindow(QString username, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow),
    game(username.toStdString())
{
    ui->setupUi(this);
}

GameWindow::~GameWindow()
{
   
}
