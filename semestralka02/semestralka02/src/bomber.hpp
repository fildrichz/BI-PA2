#pragma once

#include <string>

#include "movingBlock.hpp"
#include "bomb.hpp"
#include "powerup.hpp"
#include "grass.hpp"

class bomber : public std::enable_shared_from_this<bomber>, public movingBlock {
protected:
	bool bombBuffer;

public:
	std::string playerName;

	int expSize, bombTimer, canPlace;

	unsigned int score;

	bomber(const unsigned int x, const unsigned int y);

	virtual std::string getName() const;

	virtual bool placeBomb(std::vector< std::vector< std::shared_ptr<baseBlock>>> board);

	virtual bool isPlayer() const; //override;

	virtual std::shared_ptr< baseBlock> move(std::vector< std::vector< std::shared_ptr<baseBlock>>>& board); //override;

	std::shared_ptr<baseBlock> ruin();
};