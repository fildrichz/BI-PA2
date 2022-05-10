#pragma once

#include "baseBlock.hpp"
#include "bomber.hpp"

class powerup : public baseBlock {

public:
	virtual void effect(std::shared_ptr<bomber> whoWalked);

};