#include "powerup2.hpp"
#include "bomberBase.hpp"

powerup2::powerup2(const unsigned int xe, const unsigned int ye): powerup(xe, ye, 'r')
{
}

void powerup2::effect(std::shared_ptr<bomberBase> whoWalked)
{
	whoWalked->expSize += 1;
	std::cout << "Increased explosion radius!" << std::endl;
	return;

}

