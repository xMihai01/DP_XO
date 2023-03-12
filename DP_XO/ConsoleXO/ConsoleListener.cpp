#include "ConsoleListener.h"

ConsoleListener::ConsoleListener(IGamePtr game)
	: m_game(game)
{
}

void ConsoleListener::Update()
{

    auto board = m_game->GetBoard().GetBoard();

    for (size_t index = 0; index < boardSize * boardSize; index++) {
        
        if (board[index / 3][index % 3] == Sign::X)
            std::cout << "X ";
        else if (board[index / 3][index % 3] == Sign::O)
            std::cout << "O ";
        else
            std::cout << "- ";
        
        if (index % boardSize == 2)
            std::cout << "\n";
    }

    std::cout << "\n\n";
}

void ConsoleListener::ShowGameState()
{

    auto state = m_game->GetGameState();

    if (state == Board::BoardState::Win)
        std::cout << "You won!\n";
    else if (state == Board::BoardState::Lose)
        std::cout << "You lost!\n";
    else if (state == Board::BoardState::Draw)
        std::cout << "Draw!\n";

    if (state != Board::BoardState::Unfinished)
          m_game->NewGame();

}
