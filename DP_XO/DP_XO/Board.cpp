#include "Board.h"

Board::Board()
{
	for (size_t i = 0; i < boardSize; ++i)
		for (size_t j = 0; j < boardSize; ++j)
			m_board[i][j] = Sign::NONE;
}

std::array<std::array<Sign,boardSize >,boardSize > Board::GetBoard()
{
	return m_board;
}

bool Board::setOption(uint32_t option, const Player& player)
{
	if (option > 8)return;
	if (m_board[option / boardSize][option % boardSize] == Sign::NONE) {
		m_board[option / boardSize][option & boardSize] = player.GetSignUsed();
		return true;
	}

	return false;
}

void Board::ResetBoard()
{
	for (size_t i = 0; i < boardSize; ++i)
		for (size_t j = 0; j < boardSize; ++j)
			m_board[i][j] = Sign::NONE;
}
