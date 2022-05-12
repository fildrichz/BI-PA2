#include "grass.hpp"


grass::grass(const unsigned int xe, const unsigned int ye): baseBlock(xe, ye, '_')
{
	passable = true;
}

std::shared_ptr<baseBlock> grass::ruin()
{
	return shared_from_this();
}