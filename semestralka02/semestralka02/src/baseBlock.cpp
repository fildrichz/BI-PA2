
#include "baseBlock.hpp"


baseBlock::baseBlock(const unsigned int xe, const unsigned int ye, const char& maske) :
	mask(maske), passable(false), x(xe), y(ye), under(nullptr)
{
}



char baseBlock::display() 
{
	return mask;
}

bool baseBlock::isPassable() const {
	return passable;
}

