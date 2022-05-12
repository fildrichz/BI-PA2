#include "powerup2.hpp"
#include "bomber.hpp"

powerup2::powerup2(const unsigned int xe, const unsigned int ye): powerup(xe, ye, 'r')
{
}

void powerup2::effect(std::shared_ptr<bomber> whoWalked)
{
	whoWalked->expSize += 1;
	std::cout << "Increased explosion radius!" << std::endl;
	return;

}

