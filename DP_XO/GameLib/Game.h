#pragma once
#include "IGame.h"


class Game : public IGame
{
public:

	Game() = default;
	Game(const std::string& username);

	void NewGame() override;
	void StartRound(uint8_t position) override;

	Board GetBoard() override;
	IPlayerPtr GetPlayer() override;
	uint8_t GetTurnNumber() override;
	Board::BoardState GetGameState() override;
	IPlayerPtr GetRobot() override;
	
	void AddListener(IGameListenerPtr listener) override;
	void RemoveListener(IGameListenerPtr listener) override;

	void NotifyAllListeners() override;

	~Game() = default;
private:
	void CheckGameState() override;
	uint8_t SetOptionForRobot() override;




protected:

	Board m_board;
	IPlayerPtr m_player;
	IPlayerPtr m_robot;
	bool m_isPlayerLast;

	uint8_t m_turnNumber;

	Board::BoardState m_gameState;

	bool m_isGameRunning;

	std::vector<IGameListenerPtr> m_listeners;

};

