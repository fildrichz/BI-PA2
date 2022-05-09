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
		return std::make_shared<baseBlock>(this);
	}

	return std::make_shared<baseBlock>(grass(this->getX(), this->getY()));
}
