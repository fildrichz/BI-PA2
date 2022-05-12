#pragma once

#include "baseBlock.hpp"

class indestructibleBlock : public baseBlock, public std::enable_shared_from_this<indestructibleBlock> {
public:
	indestructibleBlock(const unsigned int x, const unsigned int y);
	std::shared_ptr<baseBlock> ruin() override;
};