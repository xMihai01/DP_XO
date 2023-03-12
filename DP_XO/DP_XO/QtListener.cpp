#include "QtListener.h"

QtListener::QtListener(IGamePtr game, QMap<QPushButton*, uint8_t>& boardSlots, QLabel* gameStateLabel)
	: m_game(game)
	, m_boardSlots(boardSlots)
    , m_gameStateLabel(gameStateLabel)
{
}

void QtListener::Update()
{

    if (m_gameStateLabel->text() != "Running") {

        m_game->NewGame();
        for (auto slot : m_boardSlots.toStdMap())
            slot.first->setText("");
    }
    m_gameStateLabel->setText("Running");


    auto board = m_game->GetBoard().GetBoard();

    for (size_t index = 0; index < boardSize * boardSize; index++) {
        for (auto slot : m_boardSlots.toStdMap()) {

            if (slot.second == index) {
                if (board[index / 3][index % 3] == Sign::X)
                    slot.first->setText("X");
                else if (board[index / 3][index % 3] == Sign::O)
                    slot.first->setText("O");

            }
        }
    }

}

void QtListener::ShowGameState()
{
    auto state = m_game->GetGameState();

    if (state == Board::BoardState::Win)
        m_gameStateLabel->setText("YOU WON!");
    else if (state == Board::BoardState::Lose)
        m_gameStateLabel->setText("YOU LOST!");
    else if (state == Board::BoardState::Draw)
        m_gameStateLabel->setText("DRAW!");
}
