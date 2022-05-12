#include "powerup4.hpp"
#include "bomber.hpp"

powerup4::powerup4(const unsigned int xe, const unsigned int ye): powerup(xe, ye, 'e')
{
}

void powerup4::effect(std::shared_ptr<bomber> whoWalked)
{
	whoWalked->bombTimer += 1;
	std::cout << "Increased explosion timer!" << std::endl;
	return;

}

