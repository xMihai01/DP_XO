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

private:

	Board m_board;
	Player m_player;
	Player m_robot;
	uint8_t m_turnNumber;

	bool m_isGameRunning;

};

