#pragma once
#include "powerup.hpp"

/**
* second powerup.
*/
class powerup2: public powerup{

public:

	/**
	* constructor.
	* 
	* \param xe coordinate
	* \param ye coordinate
	*/
	powerup2(const unsigned int xe, const unsigned int ye);

	/**
	* increases explosion radius
	*
	* \param whoWalked
	*/
	virtual void effect(std::shared_ptr<bomber> whoWalked);
};
