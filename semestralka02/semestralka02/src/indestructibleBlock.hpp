#pragma once

#include "baseBlock.hpp"

class indestructibleBlock : public baseBlock {

public:
	indestructibleBlock(const unsigned int x, const unsigned int y);
	std::shared_ptr<baseBlock> ruin() override;
};
