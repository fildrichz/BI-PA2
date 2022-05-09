#pragma once

#include <memory>
#include <vector>

class baseBlock {
	unsigned int x, y;
	bool explosionDebris;


protected:

	char mask;
	bool passable;
	bool debrisCheck();

public:

	std::shared_ptr<baseBlock> under;

	unsigned int getX() const;
	unsigned int getY() const;

	baseBlock(const unsigned int x, const unsigned int y);
	baseBlock(const unsigned int x, const unsigned int y, const char & mask);


	virtual std::shared_ptr<baseBlock> ruin();

	virtual char display() const;



};
