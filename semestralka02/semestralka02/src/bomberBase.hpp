#pragma once

#include <string>

#include "movingBlock.hpp"
#include "bomb.hpp"
#include "powerup.hpp"
#include "grass.hpp"

/**
 * Bomberman class, by default guided by player.
 */
class bomberBase : public std::enable_shared_from_this<bomberBase>, public movingBlock {

public:

	/**
	 * name of player playing.
	 */
	std::string playerName;

	/**
	 * all things concerning explosion placement.
	 */
	int expSize, bombTimer, canPlace;

	/**
	 * resulting score.
	 */
	unsigned int score;

	/**
	 * bomberman constructor.
	 *
	 * \param x coordinate
	 * \param y coordinate
	 */
	bomberBase(const unsigned int x, const unsigned int y);

	/**
	 * places bomb in grid under bomberman.
	 *
	 * \param board where it is placed
	 * \return bomb that has been placed
	 */
	virtual bool placeBomb(std::vector< std::vector< std::shared_ptr<baseBlock>>> board);

	/**
	 * ruins this bomber.
	 *
	 * \return new block in its place
	 */
	std::shared_ptr<baseBlock> ruin();
};