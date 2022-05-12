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
		return shared_from_this();
	}

	return std::shared_ptr<baseBlock>(new grass(x, y));
}
