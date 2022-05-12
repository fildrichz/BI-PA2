#pragma once

#include "movingBlock.hpp"

class ghost : public movingBlock, public std::enable_shared_from_this<ghost> {
protected:
	std::string direction;

	void changeDirection();

	bool checkFront(std::vector< std::vector< std::shared_ptr<baseBlock>>>& board);

public:
	ghost(const unsigned int x, const unsigned int y);

	virtual std::shared_ptr< baseBlock> move(std::vector< std::vector< std::shared_ptr<baseBlock>>>& board) override;

	bool isPlayer() const override;

	bool isGhost() const override;

	std::shared_ptr<baseBlock> ruin();
};