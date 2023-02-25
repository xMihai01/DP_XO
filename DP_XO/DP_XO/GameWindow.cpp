#include "GameWindow.h"
#include "ui_GameWindow.h"
#include <qmessagebox.h>

GameWindow::GameWindow(QString username, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow),
    Game(username.toStdString())
   // game(username.toStdString())
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

}

void GameWindow::slotClicked() {
    
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());

    for (int position = 0; position < boardSlots.size(); position++) {
        if (boardSlots[position] == buttonSender && m_board.GetBoardSlotState(position) == Sign::NONE) {
            if (m_board.setOption(position, m_player)) {
				buttonSender->setText("X");
				m_turnNumber++;
                m_lastTurnPlayer = m_player;
            }
        }
    }

    CheckGameState();
    
    if (m_board.GetAvailableIndices().size() > 1 && m_gameState == Board::BoardState::Unfinished && m_turnNumber % 2 == 1) {
        uint8_t robotOption = SetOptionForRobot();
		boardSlots[robotOption]->setText("O");
        m_turnNumber++;
        m_lastTurnPlayer = m_robot;
    }
    
    CheckGameState();

    if (m_gameState == Board::BoardState::Win) 
    	QMessageBox::warning(this, "WIN", "YOU WON!");
    else if (m_gameState == Board::BoardState::Lose) 
    	QMessageBox::warning(this, "LOSE", "YOU LOST!");
    else if (m_gameState == Board::BoardState::Draw) 
    	QMessageBox::warning(this, "DRAW", "DRAW!");
    if (m_gameState != Board::BoardState::Unfinished) {
		NewGame();
		for (int i = 0; i<boardSlots.size(); i++)
			boardSlots[i]->setText("");
    }
}

GameWindow::~GameWindow()
{
   
}
