#include "Game.h"
#include <algorithm>

Game::Game(std::string username)
{
	m_player = Player(username, Sign::X, true);
	m_robot = Player("Robot", Sign::O, false);
	m_turnNumber = 0;
	
	m_isGameRunning = false;
}

void Game::NewGame()
{
	Sign sign = m_player.GetSignUsed();
	bool isFirst = m_player.GetIsFirst();

	m_player.SetSignUsed(m_robot.GetSignUsed());
	m_robot.SetSignUsed(sign);

	m_player.SetIsFirst(m_robot.GetIsFirst());
	m_robot.SetIsFirst(isFirst);

	m_board.ResetBoard();

	m_turnNumber = 0;

}

void Game::RunGame()
{

	m_isGameRunning = true;

	while (m_isGameRunning) {

		if (m_turnNumber %2 == 0) {

			// Make Player choose an option from console or gui

			m_turnNumber++;
		}
		else {

			std::unordered_set<uint8_t> availableIndices = m_board.GetAvailableIndices();
			uint8_t randomIndex = rand() % availableIndices.size();
			auto it = std::begin(availableIndices);
			std::advance(it, randomIndex);
			m_board.setOption(*it, m_robot);


			m_turnNumber++;
		}

		// Check if game is finished (someone won the game)


	}
}
