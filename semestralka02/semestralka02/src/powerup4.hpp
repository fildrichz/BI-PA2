#pragma once
#include "powerup.hpp"

/**
* fourth powerup.
*/
class powerup4: public powerup{

public:

	/**
	 * constructor.
	 *
	 * \param xe coordinate
	 * \param ye coordinate
	 */
	powerup4(const unsigned int xe, const unsigned int ye);

	/**
	*  increases number of bomb ticks
	*
	* \param whoWalked
	*/
	virtual void effect(std::shared_ptr<bomber> whoWalked);
};
