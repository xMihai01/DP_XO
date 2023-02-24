#pragma once

#include "Player.h"
#include "Sign.h"
#include "Board.h"

class Game
{
public:

	enum class GameState {
		RUNNING,
		WON,
		LOST,
		DRAW
	};

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
	uint8_t m_turnNumber;
	GameState m_gameState;

	bool m_isGameRunning;

};

