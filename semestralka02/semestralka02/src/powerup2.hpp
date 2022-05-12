#pragma once
#include "powerup.hpp"

class powerup2: public powerup{

public:

	powerup2(const unsigned int xe, const unsigned int ye);

	virtual void effect(std::shared_ptr<bomber> whoWalked);
};
