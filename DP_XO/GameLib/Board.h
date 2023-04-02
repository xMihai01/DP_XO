#pragma once
#include <array>
#include <cstdint>
#include "IPlayer.h"
#include <unordered_set>

#define boardSize 3

//!  Board class
/*!
	A class used to store the dimension, matrix of a game board. The game board contains signs(X/O). This class is used
	for making moves on the board as well as returning states of the game.
*/
class Board
{
public:

	/** An enum type.
	 *  This is used for storing the state of the game.
	 */
	enum class BoardState {
		Win, /**< If the game is won */
		Lose, /**< If the game is lost */
		Draw, /**< If the game is a tie */
		Unfinished /**< If the game is not yet finished */
	};
public:
	//! Board default constructor.
	/*!
	  This constructor initializez all the elements of the board matrix with the sign "None" and
	  adds all the indices of the matrix to the available indices set.
	*/
	Board();

	//! Void function used for resetting the board to the initial state.
	/*!
	*/
	void ResetBoard();

	//! Member funcion used to return the matrix of the board with all the curent signs assigned to each position.
	/*!
	  \return The game board and the current signs assigned to each position.
	*/
	std::array<std::array<Sign, boardSize>, boardSize> GetBoard();

	//! Member function used to return the unordered set off all the available (unassigned) spots on the game board.
	/*!
	  \return Unordered set of available indices
	*/
	std::unordered_set<uint8_t> GetAvailableIndices() const;

	//! Member function returning the state of the game after checking the board signs.
	/*!
	  \return State of the board (Win/Lose etc.)
	*/
	BoardState CheckGameState();

	//! Member function used for making a move in the game board.
	/*!
	  \param option an unsigned int meaning the position on the board that the player wants to put a sign on.
	  \param s a player pointer, used for pointing to the player that made the move.
	  \return Whether or not the player managed to make a valid move on the board
	*/
	bool setOption(uint8_t option, IPlayerPtr player);

	//! Member function used for return the sign on the board at a specified position
	/*!
	  \param position integer, a board position to be checked
	  \return The sign located at the position parameter on the board.
	  \sa QTstyle_Test(), ~QTstyle_Test(), testMeToo() and publicVar()
	*/
	Sign GetBoardSlotState(int position) const;

private:
	std::array<std::array<Sign,boardSize>,boardSize> m_board; /*!<  A matrix of a chosen boardSize^2, storing Signs (X or O) */
	std::unordered_set<uint8_t> m_availableIndices; /*!< An unordered set containing all the indices in the board that are empty */
};

