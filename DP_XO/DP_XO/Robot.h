#pragma once
#include "IPlayer.h"

class Robot : public IPlayer
{

public:

	Robot();

	Sign GetSignUsed() const override;
	std::string GetNameUsed() const override;

	void SetName(const std::string& name) override;
	void SetSignUsed(Sign sign) override;

	//static IPlayerPtr Produce();

private:

	std::string m_name;
	Sign m_signUsed;

};

