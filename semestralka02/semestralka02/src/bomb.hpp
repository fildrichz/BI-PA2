#pragma once

#include "baseBlock.hpp"
#include "bomber.hpp"

class bomber;

/**
 * represents bomb.
 */
class bomb : public baseBlock, public std::enable_shared_from_this<bomb> {
protected:

	/**
	 * till explosion.
	 */
	int timeLeft;

	/**
	 * size of explosion.
	 */
	int explosionSize;


	/**
	 * who placed bomb.
	 */
	std::weak_ptr<bomber> belongsTo;

	/**
	 * represents bomb tick.
	 * 
	 * \return if reached zero
	 */
	bool tick();

	/**
	 * bomb explodes, ruining everything in its radius, including itself.
	 * 
	 * \param board where explosion happens
	 * \return score added to bomb owner
	 */
	int explode(std::vector< std::vector< std::shared_ptr<baseBlock>>>& board);

public:

	/**
	 * constructor.
	 * 
	 * \param x coordinate
	 * \param y coordinate
	 * \param eSize radius of explosion
	 * \param timer number of ticks to explosion
	 * \param belongsTo who placed bomb
	 */
	bomb(const unsigned int x, const unsigned int y, const int eSize, const int timer, std::weak_ptr<bomber> belongsTo);

	/**
	 * handles all things bomb concerned, such as ticking, explosions and so on.
	 * 
	 * \param board where it happens
	 */
	void bombProcess(std::vector< std::vector< std::shared_ptr<baseBlock>>>& board);

	/**
	 * displays bomb.
	 * 
	 * \return number of ticks left
	 */
	virtual char display();

	/**
	 * ruins bomb.
	 * 
	 * \return 
	 */
	std::shared_ptr<baseBlock> ruin();
};