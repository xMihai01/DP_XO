#include "GameWindow.h"
#include "ui_GameWindow.h"
#include <qmessagebox.h>

GameWindow::GameWindow(QString username, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    
    connect(ui->slot1, SIGNAL(clicked()), SLOT(slotClicked()));
    connect(ui->slot2, SIGNAL(clicked()), SLOT(slotClicked()));
    connect(ui->slot3, SIGNAL(clicked()), SLOT(slotClicked()));
    connect(ui->slot4, SIGNAL(clicked()), SLOT(slotClicked()));
    connect(ui->slot5, SIGNAL(clicked()), SLOT(slotClicked()));
    connect(ui->slot6, SIGNAL(clicked()), SLOT(slotClicked()));
    connect(ui->slot7, SIGNAL(clicked()), SLOT(slotClicked()));
    connect(ui->slot8, SIGNAL(clicked()), SLOT(slotClicked()));
    connect(ui->slot9, SIGNAL(clicked()), SLOT(slotClicked()));

    boardSlots.insert(ui->slot1, 0);
    boardSlots.insert(ui->slot2, 1);
    boardSlots.insert(ui->slot3, 2);
    boardSlots.insert(ui->slot4, 3);
    boardSlots.insert(ui->slot5, 4);
    boardSlots.insert(ui->slot6, 5);
    boardSlots.insert(ui->slot7, 6);
    boardSlots.insert(ui->slot8, 7);
    boardSlots.insert(ui->slot9, 8);


    game = IGame::Produce();
    qtListener = std::make_shared<QtListener>(game, boardSlots, ui->gameState_label);
    
    game->AddListener(qtListener);

}

void GameWindow::slotClicked() {
    
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());

    game->StartRound(boardSlots[buttonSender]);


}

GameWindow::~GameWindow()
{
    game->RemoveListener(qtListener);
}
