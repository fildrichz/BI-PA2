#pragma once

#include "movingBlock.hpp"
#include <string>

class bomber: public movingBlock{

	unsigned int score;
	std::string playerName;

public:

	virtual bool placeBomb(std::vector< std::vector< std::shared_ptr<baseBlock>>> board, std::vector< std::shared_ptr< bomb >> bombs);


	/**
	 * Loads bombers based on level and player input. Player gets to choose Which mode the robots in level will be using
	 * They can either be controlled by player, not move at all, or be controlled by computer
	 *
	 * \return False if any bomber failed to load, else True
	 */
	virtual bool loadBomber();



};
