#include "powerup1.hpp"
#include "bomberBase.hpp"

powerup1::powerup1(const unsigned int xe, const unsigned int ye) : powerup(xe, ye, 'b')
{
}

void powerup1::effect(std::shared_ptr<bomberBase> whoWalked)
{
	whoWalked->playerName = "Mysterio";
	std::cout << "changed player name!" << std::endl;
	return;
}