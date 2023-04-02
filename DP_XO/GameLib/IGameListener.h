#pragma once

#include <memory>

//!  IGameListener interface
/*!
	Interface for implementing the observer design pattern.
*/
class IGameListener {

public:
	//! Pure virtual member.
	/*!
		Used for updating the board after the listener was notified.
	*/
	virtual void Update() = 0;

	//! Pure virtual member.
	/*!
		Used for showing the game state after the listener was notified.
	*/
	virtual void ShowGameState() = 0;

	//! Pure virtual destructor.
	/*!
		Used for deallocating memory for the listeners.
	*/
	virtual ~IGameListener() = default;

};

using IGameListenerPtr = std::shared_ptr<IGameListener>;
using IGameListenerWeakPtr = std::weak_ptr<IGameListener>;
