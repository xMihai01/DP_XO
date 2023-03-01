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

    boardSlots.push_back(ui->slot1);
    boardSlots.push_back(ui->slot2);
    boardSlots.push_back(ui->slot3);
    boardSlots.push_back(ui->slot4);
    boardSlots.push_back(ui->slot5);
    boardSlots.push_back(ui->slot6);
    boardSlots.push_back(ui->slot7);
    boardSlots.push_back(ui->slot8);
    boardSlots.push_back(ui->slot9);
    game = IGame::Produce();

}

void GameWindow::slotClicked() {
    
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());

    for (int position = 0; position < boardSlots.size(); position++) {
        if (boardSlots[position] == buttonSender && game->GetBoard().GetBoardSlotState(position) == Sign::NONE) {
            if (game->GetBoard().setOption(position, game->GetPlayer())) {
				buttonSender->setText("X");
                game->IncrementTurnNumber();
                game->SetLastTurnPlayer(game->GetPlayer());
            }
        }
    }

    game->CheckGameState();
    
    if (game->GetBoard().GetAvailableIndices().size() > 1 && game->GetGameState() == Board::BoardState::Unfinished && game->GetTurnNumber() % 2 == 1) {
        uint8_t robotOption = game->SetOptionForRobot();
		boardSlots[robotOption]->setText("O");
        game->IncrementTurnNumber();
        game->SetLastTurnPlayer(game->GetRobot());
    }
    
    game->CheckGameState();

    if (game->GetGameState() == Board::BoardState::Win)
    	QMessageBox::warning(this, "WIN", "YOU WON!");
    else if (game->GetGameState() == Board::BoardState::Lose) 
    	QMessageBox::warning(this, "LOSE", "YOU LOST!");
    else if (game->GetGameState() == Board::BoardState::Draw) 
    	QMessageBox::warning(this, "DRAW", "DRAW!");
    if (game->GetGameState() != Board::BoardState::Unfinished) {
		game->NewGame();
		for (int i = 0; i<boardSlots.size(); i++)
			boardSlots[i]->setText("");
    }
}

GameWindow::~GameWindow()
{
   
}
