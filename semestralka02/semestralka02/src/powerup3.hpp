#pragma once
#include "powerup.hpp"

class powerup3: public powerup{

public:

	powerup3(const unsigned int xe, const unsigned int ye);

	virtual void effect(std::shared_ptr<bomber> whoWalked);
};
