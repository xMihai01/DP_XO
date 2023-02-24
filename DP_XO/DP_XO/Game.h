#pragma once

#include "Player.h"
#include "Sign.h"
#include "Board.h"

class Game
{

public:

	Game();

	void NewGame();
	void RunGame();

private:

	Board m_board;
	Player *m_player;
	Player *m_robot;

	bool m_isGameRunning;

};

