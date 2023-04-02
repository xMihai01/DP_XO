#pragma once

#include "IPlayer.h"
#include "Board.h"
#include "IGameListener.h"

using IGamePtr = std::shared_ptr<class IGame>;

//!  IGame interface
/*!
	Interface for the TicTacToe game.
*/
class IGame {
public:

	//! Pure virtual member. 
	/*!
		This function should start a new game.
	*/
	virtual void NewGame() = 0;

	//! Pure virtual member. 
	/*!
		This function starts a new round.
	*/
	virtual void StartRound(uint8_t position) = 0;

	//! Pure virtual member. 
	/*!
		This function returns the board assigned to the current game.
		\return A Board class object
	*/

	virtual Board GetBoard() = 0;

	//! Pure virtual member. 
	/*!
		This function returns a player pointer to the player that is currently playing the game.
		\return A player pointer to the current player.
	*/
	virtual IPlayerPtr GetPlayer() = 0;

	//! Pure virtual member. 
	/*!
		This function returns the number of moves played at the current moment.
		\return Number of current turns.
	*/
	virtual uint8_t GetTurnNumber() = 0;

	//! Pure virtual member. 
	/*!
		This function returns the state of the game at the current moment (Win/Lose/Draw etc.)
		\return BoardState enum containing the state of the game.
	*/
	virtual Board::BoardState GetGameState() = 0;

	//! Pure virtual member. 
	/*!
		This function returns the robot player pointer.
		\return Player pointer pointing to the robot player.
	*/
	virtual IPlayerPtr GetRobot() = 0;
	
	//! Pure virtual member. 
	/*!
		This function adds a listener to the listeners list.
		\param listener An IGameListener pointer to add.
	*/
	virtual void AddListener(IGameListenerPtr listener) = 0;

	//! Pure virtual member. 
	/*!
		This function removes a certain listener from the listeners list.
		\param listener An IGameListener pointer to remove.
	*/
	virtual void RemoveListener(IGameListenerPtr listener) = 0;

	//! Pure virtual member. 
	/*!
		This function removes a certain listener from the listeners list.
		\param listener An IGameListener pointer to remove.
	*/
	virtual void NotifyAllListeners() = 0;

	//! Virtual destructor.
	/*!
		Used to deallocate all the memory used in a game.
	*/
	virtual ~IGame() = default;

	//! Static member. 
	/*!
		Creates a shared pointer to a game instance.
		\return A game pointer
	*/
	static IGamePtr Produce();

	//! Pure virtual member. 
	/*!
		Updates the game state private member ( Win/Lose etc.)
	*/
	virtual void CheckGameState() = 0;

	//! Pure virtual member. 
	/*!
		Sets a random move for the robot player.
		\return The position at which the robot randomly placed a sign.
	*/
	virtual uint8_t SetOptionForRobot() = 0;

};
