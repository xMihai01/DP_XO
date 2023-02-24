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
	void setOption(uint32_t option, const Player&);

private:
	std::array<std::array<Sign,boardSize>,boardSize> m_board;

};

