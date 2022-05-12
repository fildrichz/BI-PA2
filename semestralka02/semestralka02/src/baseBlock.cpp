
#include "baseBlock.hpp"

bool baseBlock::debrisCheck() 
{
	if (explosionDebris) {
		explosionDebris = false;
		return true;
	}

	return false;
}


baseBlock::baseBlock(const unsigned int xe, const unsigned int ye, const char& maske) :
	explosionDebris(false), mask(maske), passable(false), x(xe), y(ye), under(nullptr)
{
}



char baseBlock::display() 
{
	if (debrisCheck())
		return '+';

	return mask;
}

bool baseBlock::isPassable() const {
	return passable;
}

