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
	IPlayerPtr GetPlayer() override;
	uint8_t GetTurnNumber() override;
	void IncrementTurnNumber() override;
	void SetLastTurnPlayer(const Player& player);
	Board::BoardState GetGameState() override;
	IPlayerPtr GetRobot() override;
	
	void CheckGameState() override;
	uint8_t SetOptionForRobot() override;

	~Game() = default;



protected:

	Board m_board;
	IPlayerPtr m_player;
	IPlayerPtr m_robot;
	bool m_isPlayerLast;

	uint8_t m_turnNumber;

	Board::BoardState m_gameState;

	bool m_isGameRunning;

};

