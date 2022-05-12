#include "powerup.hpp"
#include "grass.hpp"



powerup::powerup(const unsigned int xe, const unsigned int ye, const char& maske): baseBlock(xe,ye, maske)
{
	passable = true;
}


std::shared_ptr<baseBlock> powerup::ruin()
{
	return std::make_shared<grass>(x, y);
}