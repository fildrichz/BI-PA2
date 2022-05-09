#pragma once

#include <memory>
#include <vector>

class baseBlock {
	unsigned int x, y;
	std::shared_ptr<baseBlock> under;

	bool passable;
	char mask;

	bool explosionDebris;

	void debrisCheck() const;

public:

	unsigned int getX() const;
	unsigned int getY() const;

	baseBlock(const unsigned int x, const unsigned int y);
	baseBlock(const unsigned int x, const unsigned int y, std::shared_ptr<baseBlock>& under);


	virtual std::shared_ptr<baseBlock> ruined();

	virtual char display() const;



};
