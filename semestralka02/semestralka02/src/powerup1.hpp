#pragma once
#include "powerup.hpp"

/**
 * first powerup.
 */
class powerup1 : public powerup {
public:

	/**
	 * constructor.
	 * 
	 * \param xe coordinate
	 * \param ye coordinate
	 */
	powerup1(const unsigned int xe, const unsigned int ye);

	/**
	 * increases maximum number of bombs that can be placed
	 * 
	 * \param whoWalked 
	 */
	virtual void effect(std::shared_ptr<bomberBase> whoWalked);
};