#pragma once

#include "IPlayer.h"

class Player : public IPlayer
{

public:

	Player();
	Player(const std::string& name, Sign signUsed);

	Sign GetSignUsed() const override;
	std::string GetNameUsed() const override;

	void SetName(const std::string& name) override;
	void SetSignUsed(Sign sign) override;

private:

	std::string m_name;
	Sign m_signUsed;

};

