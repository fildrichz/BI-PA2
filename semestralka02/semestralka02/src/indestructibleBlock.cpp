#include "indestructibleBlock.hpp"

indestructibleBlock::indestructibleBlock(const unsigned int x, const unsigned int y) : baseBlock(x, y, '#')
{
}

std::shared_ptr<baseBlock> indestructibleBlock::ruin()
{
	return shared_from_this();
}