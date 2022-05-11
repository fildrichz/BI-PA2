#pragma once

#include "baseBlock.hpp"

class bomber;

class powerup : public baseBlock, std::enable_shared_from_this<powerup> {

public:
	virtual void effect(std::shared_ptr<bomber> whoWalked);

};