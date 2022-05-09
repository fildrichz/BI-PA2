#pragma once

#include "baseBlock.hpp"
#include "grass.hpp"

class sturdyBlock : public baseBlock {

protected:
	int lives;

public:
	sturdyBlock(const unsigned int x, const unsigned int y);
	std::shared_ptr<baseBlock> ruin() override;
};
