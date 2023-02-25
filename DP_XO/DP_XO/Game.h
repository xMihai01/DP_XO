#pragma once

#include "Player.h"
#include "Sign.h"
#include "Board.h"

class Game
{
public:

	Game(std::string username);

	void NewGame();
	void RunGame();

	
	void CheckGameState();
	uint8_t SetOptionForRobot();

protected:

	Board m_board;
	Player m_player;
	Player m_robot;
	Player m_lastTurnPlayer;
	uint8_t m_turnNumber;
	Board::BoardState m_gameState;

	bool m_isGameRunning;

};

