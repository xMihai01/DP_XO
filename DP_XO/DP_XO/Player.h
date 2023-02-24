#pragma once
#include <iostream>
#include "Sign.h"

class Player
{

public:

	Player(std::string name);
	Player(std::string name, Sign signUsed, bool isFirst);
	void PlaceSignOnBoard();

private:

	std::string m_name;
	Sign m_signUsed;
	bool m_isFirst;


};

