#pragma once
#include <iostream>
#include "Sign.h"

class Player
{

public:

	Player();
	Player(std::string name, Sign signUsed, bool isFirst);
	void PlaceSignOnBoard();
	Sign GetSignUsed() const;

private:

	std::string m_name;
	Sign m_signUsed;
	bool m_isFirst;


};

