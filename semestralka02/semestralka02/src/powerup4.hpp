#pragma once
#include "powerup.hpp"

class powerup4: public powerup{

public:

	powerup4(const unsigned int xe, const unsigned int ye);

	virtual void effect(std::shared_ptr<bomber> whoWalked);
};
