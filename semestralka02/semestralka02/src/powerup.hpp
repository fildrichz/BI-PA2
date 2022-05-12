#pragma once

#include "baseBlock.hpp"

class bomber;

class powerup : public baseBlock {
public:

	powerup(const unsigned int xe, const unsigned int ye, const char& maske);

	virtual void effect(std::shared_ptr<bomber> whoWalked) = 0;

	std::shared_ptr<baseBlock> ruin();
};