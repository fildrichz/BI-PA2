#pragma once

#include "baseBlock.hpp"

class bomber;

/**
 * base for powerups.
 */
class powerup : public baseBlock {
public:

	/**
	 * base for constructors
	 * 
	 * \param xe coordinate
	 * \param ye coordinate
	 * \param maske appearance
	 */
	powerup(const unsigned int xe, const unsigned int ye, const char& maske);

	/**
	 * all powerups have effect which is applied on the thing that walked on them
	 * 
	 * \param whoWalked
	 */
	virtual void effect(std::shared_ptr<bomber> whoWalked) = 0;

	/**
	 * can be destroyed by default.
	 * 
	 * \return grass
	 */
	std::shared_ptr<baseBlock> ruin();
};