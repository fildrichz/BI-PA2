#pragma once

#include "baseBlock.hpp"
#include "grass.hpp"

/**
 * sturdy block.
 */
class sturdyBlock : public baseBlock, public std::enable_shared_from_this<sturdyBlock> {
protected:
	/**
	 * number of lives until it crumbles.
	 */
	int lives;

public:

	/**
	 * constructor.
	 * 
	 * \param x coordinate
	 * \param y coordinate
	 */
	sturdyBlock(const unsigned int x, const unsigned int y);

	/**
	 * takes a while to crumble. Sturdy rock only weakens when ruined and changes mask, then crumbles into grass when lives are depleted
	 * 
	 * \return itself or new shared_ptr of grass when lives are depleted
	 */
	std::shared_ptr<baseBlock> ruin();
};