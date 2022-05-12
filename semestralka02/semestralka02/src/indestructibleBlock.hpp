#pragma once

#include "baseBlock.hpp"

/**
 * cannot be destroyed, but also cannot be passed trough.
 */
class indestructibleBlock : public baseBlock, public std::enable_shared_from_this<indestructibleBlock> {
public:

	/**
	 * constructor.
	 * 
	 * \param x coordinate
	 * \param y coordinate
	 */
	indestructibleBlock(const unsigned int x, const unsigned int y);

	/**
	 * cannot be ruined.
	 * 
	 * \return itself
	 */
	std::shared_ptr<baseBlock> ruin() override;
};