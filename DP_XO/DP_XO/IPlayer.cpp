#include "IPlayer.h"


#include "Player.h"
#include "Robot.h"

IPlayerPtr IPlayer::Produce(bool isRobot, const std::string& username = "")
{
	if (isRobot)
		return std::make_shared<Robot>();
	else
		return std::make_shared<Player>(username, Sign::X);
	
}
