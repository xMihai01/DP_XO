#pragma once
#include "IGame.h"


class Game : public IGame
{
public:

	Game() = default;
	Game(std::string username);

	void NewGame() override;
	void RunGame() override;

	Board& GetBoard() override;
	Player GetPlayer() override;
	uint8_t GetTurnNumber() override;
	void IncrementTurnNumber() override;
	void SetLastTurnPlayer(const Player& player);
	Board::BoardState GetGameState() override;
	Player GetRobot() override;
	
	void CheckGameState() override;
	uint8_t SetOptionForRobot() override;

	~Game() = default;



protected:

	Board m_board;
	Player m_player;
	Player m_robot;
	Player m_lastTurnPlayer;
	uint8_t m_turnNumber;
	Board::BoardState m_gameState;

	bool m_isGameRunning;

};

