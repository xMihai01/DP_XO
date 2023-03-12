#include "ConsoleWindow.h"

ConsoleWindow::ConsoleWindow()
{

	m_game = IGame::Produce();
	m_consoleListener = std::make_shared<ConsoleListener>(m_game);
	m_game->AddListener(m_consoleListener);
}

void ConsoleWindow::RunWindow()
{

	int position;

	std::cout << "- - -		1 2 3\n";
	std::cout << "- - -		4 5 6\n";
	std::cout << "- - -		7 8 9\n\n";


	while (true) {
		std::cout << "Position: ";
		std::cin >> position;

		if (position <= 9 && position > 0)
			m_game->StartRound(position-1);
		else
			std::cout << "Invalid position! (1-9)\n";

	}

}

ConsoleWindow::~ConsoleWindow()
{

	m_game->RemoveListener(m_consoleListener);

}
