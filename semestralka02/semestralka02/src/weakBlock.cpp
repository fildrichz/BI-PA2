#include "weakBlock.hpp"


weakBlock::weakBlock(const unsigned int x, const unsigned int y) : baseBlock(x, y, 'W')
{
}

std::shared_ptr<baseBlock> weakBlock::ruin()
{
	return std::shared_ptr<baseBlock>(new grass(this->getX(), this->getY()));
}
