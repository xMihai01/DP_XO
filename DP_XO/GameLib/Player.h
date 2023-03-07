#pragma once

#include "IPlayer.h"
#include "Robot.h"


class Player : public IPlayer
{

public:

	Player();
	Player(const std::string& name, Sign signUsed);

	Sign GetSignUsed() const override;
	std::string GetNameUsed() const override;

	void SetName(const std::string& name) override;
	void SetSignUsed(Sign sign) override;

	//static IPlayerPtr Produce();

private:

	std::string m_name;
	Sign m_signUsed;

};

