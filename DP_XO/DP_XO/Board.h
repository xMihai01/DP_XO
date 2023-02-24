#pragma once
#include "Sign.h"
#include <array>
#include <cstdint>
#include "Player.h"
#include <unordered_set>

#define boardSize 3

class Board
{
public:
	Board();
	void ResetBoard();
	std::array<std::array<Sign, boardSize>, boardSize> GetBoard();
	std::unordered_set<uint8_t> GetAvailableIndices() const;
	bool setOption(uint32_t option, const Player& player);

private:
	std::array<std::array<Sign,boardSize>,boardSize> m_board;
	std::unordered_set<uint8_t> m_availableIndices;
};

