#pragma once
#include <iostream>
#include "Sign.h"

class Player
{

public:

	Player();
	Player(const std::string& name, Sign signUsed, bool isFirst);

	Sign GetSignUsed() const;
	std::string GetNameUsed() const;
	bool GetIsFirst() const;

	void SetName(const std::string& name);
	void SetSignUsed(Sign sign);
	void SetIsFirst(bool isFirst);

private:

	std::string m_name;
	Sign m_signUsed;
	bool m_isFirst;


};

