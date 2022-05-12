#include "powerup3.hpp"
#include "bomber.hpp"

powerup3::powerup3(const unsigned int xe, const unsigned int ye): powerup(xe, ye, 'a')
{
}

void powerup3::effect(std::shared_ptr<bomber> whoWalked)
{
	whoWalked->canPlace += 1;
	std::cout << "Increased number of bombs!" << std::endl;
	return;

}

