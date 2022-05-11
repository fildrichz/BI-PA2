#pragma once

#include <memory>
#include <vector>
#include <iostream>

class baseBlock {

	bool explosionDebris;


protected:

	char mask;
	bool passable;
	bool debrisCheck();

public:


	unsigned int x, y;

	std::shared_ptr<baseBlock> under;

	unsigned int getX() const;
	unsigned int getY() const;

	baseBlock(const unsigned int x, const unsigned int y, const char & mask = '@');

	bool isPassable() const;


	virtual std::shared_ptr<baseBlock> ruin() = 0;

	virtual char display();

	virtual ~baseBlock() = default;



};
