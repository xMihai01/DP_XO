#include "Game.h"

Game::Game()
{
	m_player = new Player("Player", Sign::X, true);
	m_robot = new Player("Robot", Sign::O, false);
	
	m_isGameRunning = false;
}

void Game::NewGame()
{
	Sign sign = m_player->GetSignUsed();
	bool isFirst = m_player->GetIsFirst();

	m_player->SetSignUsed(m_robot->GetSignUsed());
	m_robot->SetSignUsed(sign);

	m_player->SetIsFirst(m_robot->GetIsFirst());
	m_robot->SetIsFirst(isFirst);

	m_board.ResetBoard();


}

void Game::RunGame()
{

	m_isGameRunning = true;
	Player *currentPlayer;

	if (m_player->GetIsFirst())
		currentPlayer = m_player;
	else
		currentPlayer = m_robot;

	while (m_isGameRunning) {

		if (&currentPlayer == &m_player) {

			// Make Player choose an option from console or gui

			currentPlayer = m_robot;
		}
		else {

			while (m_board.setOption(rand()%(boardSize*boardSize), *m_robot)) {
			}

			currentPlayer = m_player;
		}

		// Check if game is finished (someone won the game)


	}

	delete currentPlayer;
}
