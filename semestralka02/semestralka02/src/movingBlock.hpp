#pragma once

#include "baseBlock.hpp"
#include "powerup.hpp"

/**
 * base for all moving blocks.
 */
class movingBlock : public baseBlock {
protected:

	/** Some blocks can be relevant even after being ruined */
	bool isActive;

	/**
	 * goes somewhere.
	 * 
	 * \param board where movement happens
	 * \param direction converted to easily managable 2d vector
	 * \return true if moved, false if stayed in place
	 */
	bool go(std::vector< std::vector< std::shared_ptr<baseBlock>>>& board, const std::vector<int>& direction);

	/**
	 * goes in direction.
	 * 
	 * \param board where movement happens
	 * \param where string, difficult to manage direction
	 * \return true if moved, false if stayed in place
	 */
	bool goInDirection(std::vector< std::vector< std::shared_ptr<baseBlock>>>& board, const std::string& where);

	/**
	 * checks if move can be done.
	 * 
	 * \param board board where movement happens
	 * \param target where we are going
	 * \return true if movement can occur, false if out of bounds or similar condition
	 */
	bool checkDirectionValidity(const std::vector< std::vector< std::shared_ptr<baseBlock>>>& board, const std::vector<int>& target) const;


	/**
	 * convets string to easily managable 2d vector of direction.
	 * 
	 * \param where string direction
	 * \return 2d int array direction
	 */
	std::vector<int> getRealTarget(const std::string& where) const;

public:

	/**
	 * constructor.
	 * 
	 * \param x coordinate
	 * \param y coordinate
	 */
	movingBlock(const unsigned int x, const unsigned int y);

	/**
	 * getter.
	 * 
	 * \return if class is active
	 */
	bool active() const;

	/**
	 * purely abstract move.
	 * 
	 * \param board wher movement happens
	 * \return where moved
	 */
	virtual std::shared_ptr< baseBlock> move(std::vector< std::vector< std::shared_ptr<baseBlock>>>& board) = 0;

	/**
	 * true by default.
	 * 
	 * \return true
	 */
	virtual bool isGhost() const;

	/**
	 * false by default.
	 * 
	 * \return false
	 */
	virtual bool isPlayer() const;

	/**
	 * allows block we walked on to change values of moving block.
	 * 
	 * \param thing that we walked on
	 */
	virtual void walkedOn(std::shared_ptr< baseBlock>& thing);
};