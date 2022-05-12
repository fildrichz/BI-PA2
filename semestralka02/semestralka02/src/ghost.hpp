#pragma once

#include "movingBlock.hpp"

/**
 * represents classic bomberman ghost which eliminates bomber by walking over it. Guided by computer
 */
class ghost : public movingBlock, public std::enable_shared_from_this<ghost> {
protected:
	std::string direction;

	/**
	 * changes direction.
	 * 
	 */
	void changeDirection();

	/**
	 * checks if there is a bomberman in front.
	 * 
	 * \param board where game is played
	 * \return true if there is one, else false
	 */
	bool checkFront(std::vector< std::vector< std::shared_ptr<baseBlock>>>& board);

public:

	/**
	 * constructor.
	 * 
	 * \param x coordinate
	 * \param y coordinate
	 */
	ghost(const unsigned int x, const unsigned int y);

	/**
	 * move, handling everything from movement to player detection and removal. Is handled by computer
	 * 
	 * \param board
	 * \return 
	 */
	virtual std::shared_ptr< baseBlock> move(std::vector< std::vector< std::shared_ptr<baseBlock>>>& board) override;

	/**
	 * ghost is never player.
	 * 
	 * \return false
	 */
	bool isPlayer() const override;

	/**
	 * ghost is always ghost(as in AI, there are other things that can be ghosts not named explicitly ghost).
	 * 
	 * \return 
	 */
	bool isGhost() const override;

	/**
	 * ruins ghost.
	 * 
	 * \return block underneath
	 */
	std::shared_ptr<baseBlock> ruin();
};