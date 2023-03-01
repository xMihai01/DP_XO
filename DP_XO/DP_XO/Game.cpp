#include "Game.h"
#include <algorithm>
#include <qdebug.h>

Game::Game(std::string username)
{
	//m_player = Player(username, Sign::X);
	//m_robot = Player("Robot", Sign::O);
	m_player = IPlayer::Produce(false, username);
	m_robot = IPlayer::Produce(true, "");
	m_turnNumber = 0;
	m_gameState = Board::BoardState::Unfinished;
	
	m_isGameRunning = false;
}

void Game::NewGame()
{

	m_board.ResetBoard();

	m_isPlayerLast = true;
	m_turnNumber = 0;

	m_gameState = Board::BoardState::Unfinished;

}

void Game::RunGame()
{

	m_isGameRunning = true;
	m_isPlayerLast = true;

	while (m_isGameRunning) {

		if (m_turnNumber %2 == 0) {

			// Make Player choose an option from console or gui

		}
		else {

			uint8_t randomOption = SetOptionForRobot();
			m_board.setOption(randomOption, m_robot);
		
		}

		m_isPlayerLast = !m_isPlayerLast;

		m_turnNumber++;

		CheckGameState();
		//if(m_gameState )
		// Check if game is finished (someone won the game)


	}
}

Board& Game::GetBoard()
{
	return m_board;
}

IPlayerPtr Game::GetPlayer()
{
	return m_player;
}

uint8_t Game::GetTurnNumber()
{
	return m_turnNumber;
}

void Game::IncrementTurnNumber()
{
	m_turnNumber++;
}

void Game::SetLastTurnPlayer(const Player& player)
{
	m_isPlayerLast = !m_isPlayerLast;
}

Board::BoardState Game::GetGameState()
{
	return m_gameState;
}

IPlayerPtr Game::GetRobot()
{
	return m_robot;
}

IGamePtr IGame::Produce() {
	return std::make_shared<Game>();
}

void Game::CheckGameState()
{
	Board::BoardState boardState = m_board.CheckGameState();

	switch (boardState)
	{
	case Board::BoardState::Win:
		if (!m_isPlayerLast)
			m_gameState = Board::BoardState::Lose;
		else
			m_gameState = Board::BoardState::Win;
		m_board.ResetBoard();
		break;
	case Board::BoardState::Draw:
		m_gameState = Board::BoardState::Draw;
		m_board.ResetBoard();
		break;
	case Board::BoardState::Unfinished:
		break;
	default:
		break;
	}
}

uint8_t Game::SetOptionForRobot()
{
	std::unordered_set<uint8_t> availableIndices = m_board.GetAvailableIndices();
	uint8_t randomIndex = rand() % availableIndices.size();
	auto it = std::begin(availableIndices);
	std::advance(it, randomIndex);
	m_board.setOption(*it, m_robot);

	return *it;
}

