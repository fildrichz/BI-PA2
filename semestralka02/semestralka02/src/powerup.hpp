#pragma once

#include "baseBlock.hpp"
#include "bomber.hpp"

class powerup : public baseBlock {

	virtual void effect(std::shared_ptr<bomber> whoWalked);

};