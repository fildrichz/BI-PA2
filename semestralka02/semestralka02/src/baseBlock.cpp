
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

baseBlock::baseBlock(const unsigned int xe, const unsigned int ye):
	x(xe), y(ye), under(nullptr), passable(false), mask('@'), explosionDebris(false)
{
}

baseBlock::baseBlock(const unsigned int xe, const unsigned int ye, const char& maske): 
	x(xe), y(ye), under(nullptr), passable(false), mask(maske), explosionDebris(false)
{
}

std::shared_ptr<baseBlock> baseBlock::ruin()
{
	if (under != nullptr)
		return under;

	return std::shared_ptr<baseBlock>(this);
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

