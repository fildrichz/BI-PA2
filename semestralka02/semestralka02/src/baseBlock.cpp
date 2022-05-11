
#include "baseBlock.hpp"

bool baseBlock::debrisCheck() 
{
	if (explosionDebris) {
		explosionDebris = false;
		return true;
	}

	return false;
}

unsigned int baseBlock::getX() const
{
	return x;
}

unsigned int baseBlock::getY() const
{
	return y;
}


baseBlock::baseBlock(const unsigned int xe, const unsigned int ye, const char& maske) :
	explosionDebris(false), mask(maske), passable(false), x(xe), y(ye), under(nullptr)
{
}

std::shared_ptr<baseBlock> baseBlock::ruin()
{
	std::cout << "ruining" << std::endl;

	if (under != nullptr)
		return under->ruin();

	return shared_from_this();
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

