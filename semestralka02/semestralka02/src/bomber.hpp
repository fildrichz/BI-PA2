#pragma once

#include "movingBlock.hpp"
#include <string>
#include "bomb.hpp"
#include "powerup.hpp"
#include "grass.hpp"

class bomber: public movingBlock{

public:
	std::string playerName;

	int expSize;
	int bombTimer;

	unsigned int score;

	bomber(const unsigned int x, const unsigned int y);

	virtual std::string getName() const;

	virtual bool placeBomb(std::vector< std::vector< std::shared_ptr<baseBlock>>> board);

	virtual bool isPlayer() const override;

	virtual std::shared_ptr< baseBlock> move(std::vector< std::vector< std::shared_ptr<baseBlock>>>& board) override;

};
