#pragma once

#include "movingBlock.hpp"
#include <string>
#include "bomb.hpp"

class bomber: public movingBlock{


protected:
	std::string playerName;

public:

	int expSize;
	int bombTimer;

	unsigned int score;

	bomber(const unsigned int x, const unsigned int y);

	virtual std::string getName() const;

	virtual bool placeBomb(std::vector< std::vector< std::shared_ptr<baseBlock>>> board);

	virtual bool isPlayer() const override;

	virtual std::shared_ptr< baseBlock> move(std::vector< std::vector< std::shared_ptr<baseBlock>>>& board) override;

};
