#pragma once

#include "IPlayer.h"
#include "Board.h"
#include "IGameListener.h"

using IGamePtr = std::shared_ptr<class IGame>;

class IGame {
public:

	virtual void NewGame() = 0;
	virtual void StartRound(uint8_t position) = 0;

	

	virtual Board GetBoard() = 0;
	virtual IPlayerPtr GetPlayer() = 0;
	virtual uint8_t GetTurnNumber() = 0;
	virtual Board::BoardState GetGameState() = 0;
	virtual IPlayerPtr GetRobot() = 0;
	
	virtual void AddListener(IGameListenerPtr listener) = 0;
	virtual void RemoveListener(IGameListenerPtr listener) = 0;

	virtual void NotifyAllListeners() = 0;

	virtual ~IGame() = default;

	static IGamePtr Produce();
private:
	virtual void CheckGameState() = 0;
	virtual uint8_t SetOptionForRobot() = 0;

};
