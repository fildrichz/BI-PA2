#pragma once

#include "baseBlock.hpp"

class bomber;

class powerup : public baseBlock {

public:
	virtual void effect(std::shared_ptr<bomber> whoWalked);

};