#pragma once
#include "powerup.hpp"

class powerup1 : public powerup {
public:

	powerup1(const unsigned int xe, const unsigned int ye);

	virtual void effect(std::shared_ptr<bomber> whoWalked);
};