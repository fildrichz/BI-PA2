#pragma once
#include "baseBlock.hpp"
#include "grass.hpp"

class weakBlock: public baseBlock{

public:
	weakBlock(const unsigned int x, const unsigned int y);

	std::shared_ptr<baseBlock> ruin();

};
