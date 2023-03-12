#pragma once

#include "IGame.h"
#include "ConsoleListener.h"

class ConsoleWindow
{
public:

	ConsoleWindow();

	void RunWindow();

	~ConsoleWindow();

private:

	

private:

	IGamePtr m_game;
	IGameListenerPtr m_consoleListener;


};

