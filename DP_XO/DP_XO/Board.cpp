#include "Board.h"
#include "Sign.h"

Board::Board()
{
	for (size_t i = 0; i < boardSize; ++i)
		for (size_t j = 0; j < boardSize; ++j)
			m_board[i][j] = Sign::NONE;
	for (size_t i = 0; i < boardSize * boardSize; ++i)
		m_availableIndices.insert(i);
}

std::array<std::array<Sign,boardSize >,boardSize > Board::GetBoard()
{
	return m_board;
}

bool Board::setOption(uint32_t option, const Player& player)
{
	if (option > 8)return false;
	if (m_board[option / boardSize][option % boardSize] == Sign::NONE) {
		m_board[option / boardSize][option & boardSize] = player.GetSignUsed();
		m_availableIndices.erase(option);
		return true;
	}

	return false;
}


std::unordered_set<uint8_t> Board::GetAvailableIndices() const {
	return m_availableIndices;
}

void Board::ResetBoard()
{
	for (size_t i = 0; i < boardSize; ++i)
		for (size_t j = 0; j < boardSize; ++j)
			m_board[i][j] = Sign::NONE;
	for (size_t i = 0; i < boardSize * boardSize; ++i)
		m_availableIndices.insert(i);
}
