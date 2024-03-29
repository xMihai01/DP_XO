#include "Board.h"

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

bool Board::setOption(uint8_t option, IPlayerPtr player)
{
    
    /*
    The function tries to set a sign on a board at a specified location for a given player
    The parameter option represents the location where the sign will be placed on the board.
    The location on the board is defined as [option/boardSize][option%boardSize]
    If the option is lower or equal to 8 and the current location is empty (Sign::NONE),
    then the given player's sign is placed at that location. After that, the option is erased from the availableIndices set.

    If the function returns false, then the location where the game is trying to place a sign is not available.
    */

	if (option > 8)return false;
	if (m_board[option / boardSize][option % boardSize] == Sign::NONE) {
		m_board[option / boardSize][option % boardSize] = player->GetSignUsed();

		m_availableIndices.erase(option);
		return true;
	}
    
	return false;
}

Sign Board::GetBoardSlotState(int position) const
{
    return m_board[position / boardSize][position % boardSize];
}


std::unordered_set<uint8_t> Board::GetAvailableIndices() const {
	return m_availableIndices;
}

Board::BoardState Board::CheckGameState()
{
     // Check rows and columns
    for (int i = 0; i < boardSize; i++) {
        if ((m_board[i][0] != Sign::NONE) && (m_board[i][0] == m_board[i][1])) {
            bool win = true;
            for (int j = 1; j < boardSize; j++) {
                if (m_board[i][j] != m_board[i][0]) {
                    win = false;
                    break;
                }
            }
            if (win) {
                return BoardState::Win;
            }
        }
        if ((m_board[0][i] != Sign::NONE) && (m_board[0][i] == m_board[1][i])) {
            bool win = true;
            for (int j = 1; j < boardSize; j++) {
                if (m_board[j][i] != m_board[0][i]) {
                    win = false;
                    break;
                }
            }
            if (win) {
                return BoardState::Win;
            }
        }
    }

    // Check diagonals
    bool win = true;
    for (int i = 1; i < boardSize; i++) {
        if (m_board[i][i] != m_board[0][0] || m_board[i][i] == Sign::NONE) {
            win = false;
            break;
        }
    }
    if (win && m_board[0][0] != Sign::NONE) {
        return BoardState::Win;
    }

    win = true;
    for (int i = 1; i < boardSize; i++) {
        if (m_board[i][boardSize - i - 1] != m_board[0][boardSize - 1] || m_board[i][boardSize - i - 1] == Sign::NONE) {
            win = false;
            break;
        }
    }
    if (win && m_board[0][boardSize - 1] != Sign::NONE) {
        return BoardState::Win;
    }

    // Check if there are any empty cells left
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (m_board[i][j] == Sign::NONE) {
                return BoardState::Unfinished;
            }
        }
    }

    // If we get here, the game is a tie
    return BoardState::Draw;
}

void Board::ResetBoard()
{

    /*
    Sets every element of the board to Sign::None (meaning that the location at the current element is available)
    and deletes every element of the m_availableIndices set and inserts back every number from 0, to boardSize^2 - 1
    */

	for (size_t i = 0; i < boardSize; ++i)
		for (size_t j = 0; j < boardSize; ++j)
			m_board[i][j] = Sign::NONE;
    m_availableIndices.clear();
	for (size_t i = 0; i < boardSize * boardSize; ++i)
		m_availableIndices.insert(i);
}
