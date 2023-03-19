#include "Game.h"
#include <algorithm>

Game::Game(const std::string& username)
{

	m_player = IPlayer::Produce(false, username);
	m_robot = IPlayer::Produce(true, "");
	m_turnNumber = 0;
	m_gameState = Board::BoardState::Unfinished;
	
	m_isGameRunning = false;
	m_isPlayerLast = false;
}

void Game::NewGame()
{

	/*
	Changes every variable to it's default values. Player and Robot objects are not affected by this.
	*/

	m_board.ResetBoard();

	m_isPlayerLast = false;
	m_turnNumber = 0;

	m_gameState = Board::BoardState::Unfinished;

}

void Game::StartRound(uint8_t position)
{

	/*
	Starts a new round for the current XO game. 
	The "uint8_t position" parameter represents the location where the player will place the sign on the board.
	*/

	/*
	The if block below tries to place a sign for a Player at location [position/boardSize][position%boardSize]
	If the sign was placed succesfully, then the turn number increases and the boolean value of m_isPlayerLast switches. If turn number is even, then the player places a sign, otherwise, the robot.
	*/

	if (m_board.setOption(position, m_player)) {
		m_turnNumber++;
		m_isPlayerLast = !m_isPlayerLast;
	}
	
	// Checks the current state of the game, if the game is Won, Lost or Tied, then the robot won't try to place any sign on the board

	CheckGameState();

	/*
	If there is a location available on the board, the game is not Won, Lost, Tied, and it's Robot's turn number,
	then it will set a random position for him and the turn number increases and the boolean value of m_isPlayerLast switches.
	*/

	if (m_board.GetAvailableIndices().size() > 1 && m_gameState == Board::BoardState::Unfinished && m_turnNumber % 2 == 1) {
		uint8_t robotOption = SetOptionForRobot();
		m_turnNumber++;
		m_isPlayerLast = !m_isPlayerLast;
	}

	// Checks the current state of the game again, so it can show the correct state when the Listener's ShowGameState function is called

	CheckGameState();

	// Notifies all Listeners in the vector by calling their Update and ShowGameState methods

	NotifyAllListeners();

}

Board Game::GetBoard()
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

Board::BoardState Game::GetGameState()
{
	return m_gameState;
}

IPlayerPtr Game::GetRobot()
{
	return m_robot;
}

IGamePtr IGame::Produce() {
	return std::make_shared<Game>("user");
}

void Game::CheckGameState()
{

	/*
	The function gets the current board position and changes the m_gameState if needed.
	If the m_isPlayerLast is true, and the board state is "Win", then the player won.
	If the m_isPlayerLast is false, and the board state is "Win", then the robot won.
	If the board state is "Unfinished", then the game continues.
	*/

	Board::BoardState boardState = m_board.CheckGameState();

	switch (boardState)
	{
	case Board::BoardState::Win:
		if (!m_isPlayerLast)
			m_gameState = Board::BoardState::Lose;
		else
			m_gameState = Board::BoardState::Win;
		break;
	case Board::BoardState::Draw:
		m_gameState = Board::BoardState::Draw;
		break;
	case Board::BoardState::Unfinished:
		break;
	default:
		break;
	}
}

uint8_t Game::SetOptionForRobot()
{

	/*
	The function takes a "random index" in the unordered_set of available indices and with the help of an iterator,
	it advances "random index" times and then calls the setOption function for the robot, with the first parameter being the value in the set at the location the iterator is now.
	*/

	std::unordered_set<uint8_t> availableIndices = m_board.GetAvailableIndices();
	uint8_t randomIndex = rand() % availableIndices.size();
	auto it = std::begin(availableIndices);
	std::advance(it, randomIndex);
	m_board.setOption(*it, m_robot);

	return *it;
}


void Game::AddListener(IGameListenerPtr listener)
{
	m_listeners.push_back(listener);
}

void Game::RemoveListener(IGameListenerPtr listener)
{
	for (auto it = m_listeners.begin(); it != m_listeners.end(); )
	{
		if (*it == listener)
			it = m_listeners.erase(it);
		else
			++it;
	}
}

void Game::NotifyAllListeners()
{

	for (auto obs : m_listeners) {
		obs->Update();
		obs->ShowGameState();
	}
}
