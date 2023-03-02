#pragma once
#include <string>
#include <memory>
#include "Sign.h"

using IPlayerPtr = std::shared_ptr<class IPlayer>;

class IPlayer {

public:

	virtual Sign GetSignUsed() const = 0;
	virtual std::string GetNameUsed() const = 0;

	virtual void SetName(const std::string& name) = 0;
	virtual void SetSignUsed(Sign sign) = 0;

	virtual ~IPlayer() = default;

	static IPlayerPtr Produce(bool isRobot, const std::string& username);

};