#include "Game.h"
#include <algorithm>
#include <qdebug.h>

Game::Game(const std::string& username)
{

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

void Game::StartRound(uint8_t position)
{

	if (m_board.setOption(position, m_player)) {
		m_turnNumber++;
		m_isPlayerLast = !m_isPlayerLast;
	}

	CheckGameState();

	if (m_board.GetAvailableIndices().size() > 1 && m_gameState == Board::BoardState::Unfinished && m_turnNumber % 2 == 1) {
		uint8_t robotOption = SetOptionForRobot();
		m_turnNumber++;
		m_isPlayerLast = !m_isPlayerLast;
	}

	CheckGameState();

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

void Game::SetLastTurnPlayer(const IPlayerPtr& player)
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

