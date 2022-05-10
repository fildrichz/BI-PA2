#include "sturdyBlock.hpp"

sturdyBlock::sturdyBlock(const unsigned int x, const unsigned int y): baseBlock(x, y, 'X')
{
	lives = 2;
}

std::shared_ptr<baseBlock> sturdyBlock::ruin()
{
	lives -= 1;
	if (lives > 0) {
		mask = 'x';
		return std::shared_ptr<baseBlock>(this);
	}

	return std::shared_ptr<baseBlock>(new grass(this->getX(), this->getY()));
}
