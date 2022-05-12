#pragma once
#include "baseBlock.hpp"
#include "grass.hpp"

/**
 * weak block.
 */
class weakBlock : public baseBlock {
public:

	/**
	 * constructor.
	 * 
	 * \param x coordinate
	 * \param y coordinate
	 */
	weakBlock(const unsigned int x, const unsigned int y);

	/**
	 * instantly turns into grass when hit, but cannot be passed trough.
	 * 
	 * \return 
	 */
	std::shared_ptr<baseBlock> ruin();
};