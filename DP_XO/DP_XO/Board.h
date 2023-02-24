#pragma once
#include "Sign.h"
#include <array>
#include <cstdint>
#include "Player.h"

#define boardSize 3

class Board
{
public:
	Board();
	std::array<std::array<Sign, boardSize>, boardSize> GetBoard();
	bool setOption(uint32_t option, const Player& player);
	void ResetBoard();

private:
	std::array<std::array<Sign,boardSize>,boardSize> m_board;

};

