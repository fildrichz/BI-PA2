#pragma once

#include <memory>
#include <vector>
#include <iostream>

/**
 * base class of block for further inheritance.
 */
class baseBlock {
protected:

	/**
	 * what block looks like.
	 */
	char mask;

	/**
	 * Whether it is possible to walk trough.
	 */
	bool passable;

public:

	/**
	 * coordinates.
	 */
	unsigned int x, y;


	/**
	 * Possible another block under this block.
	 */
	std::shared_ptr<baseBlock> under;


	/**
	 * constructor of base parameters.
	 * 
	 * \param x coordinate
	 * \param y coordinate
	 * \param mask appearance
	 */
	baseBlock(const unsigned int x, const unsigned int y, const char& mask = '@');

	/**
	 * Checks whether block can be walked trough.
	 * 
	 * \return passability
	 */
	bool isPassable() const;

	/**
	 * ruins block. Usually if the block is destroyed by explosion, but it can also mean kill by ghost or other methods
	 * 
	 * \return new block in its place
	 */
	virtual std::shared_ptr<baseBlock> ruin() = 0;

	/**
	 * look.
	 * 
	 * \return block appearance
	 */
	virtual char display();

	/**
	 * makes sure inherited classes all have default destructor.
	 * 
	 */
	virtual ~baseBlock() = default;
};