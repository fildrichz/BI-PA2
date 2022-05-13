#pragma once
#include "powerup.hpp"
#include "bomberBase.hpp"

/**
* third powerup.
*/
class powerup3: public powerup{

public:

	/**
	* constructor.
	*
	* \param xe coordinate
	* \param ye coordinate
	*/
	powerup3(const unsigned int xe, const unsigned int ye);

	/**
	* changes bomber's name to mysterio.
	*
	* \param whoWalked
	*/
	virtual void effect(std::shared_ptr<bomberBase> whoWalked);
};
