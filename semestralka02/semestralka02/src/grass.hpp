#pragma once
#include "baseBlock.hpp"

/**
 * majority of space where moving blocks can move.
 */
class grass : public baseBlock, public std::enable_shared_from_this<grass> {
public:

	/**
	 * default constructor.
	 * 
	 * \param xe coordinate
	 * \param ye coordinate
	 */
	grass(const unsigned int xe, const unsigned int ye);

	/**
	 * cannot be ruined.
	 * 
	 * \return its' shared_ptr
	 */
	std::shared_ptr<baseBlock> ruin();
};