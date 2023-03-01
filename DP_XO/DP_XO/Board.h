#pragma once
#include <array>
#include <cstdint>
#include "IPlayer.h"
#include <unordered_set>

class Board
{
public:
	static const uint8_t boardSize = 3;

	enum class BoardState {
		Win,
		Lose,
		Draw,
		Unfinished
	};
public:
	Board();
	void ResetBoard();
	std::array<std::array<Sign, boardSize>, boardSize> GetBoard();
	std::unordered_set<uint8_t> GetAvailableIndices() const;
	BoardState CheckGameState();
	bool setOption(uint8_t option, IPlayerPtr player);

	Sign GetBoardSlotState(int position) const;

private:
	std::array<std::array<Sign,boardSize>,boardSize> m_board;
	std::unordered_set<uint8_t> m_availableIndices;
};

