#pragma once

#include "IPlayer.h"
#include "Board.h"

using IGamePtr = std::shared_ptr<class IGame>;

class IGame {
public:

	virtual void NewGame() = 0;
	virtual void RunGame() = 0;

	
	virtual void CheckGameState() = 0;
	virtual uint8_t SetOptionForRobot() = 0;

	virtual Board& GetBoard() = 0;
	virtual IPlayerPtr GetPlayer() = 0;
	virtual uint8_t GetTurnNumber() = 0;
	virtual void IncrementTurnNumber() = 0;
	virtual void SetLastTurnPlayer(const IPlayerPtr&) = 0;
	virtual Board::BoardState GetGameState() = 0;
	virtual IPlayerPtr GetRobot() = 0;
	
	virtual ~IGame() = default;

	static IGamePtr Produce();
};