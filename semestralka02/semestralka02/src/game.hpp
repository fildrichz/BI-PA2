#pragma once

#include <fstream>
#include "baseBlock.hpp"

class game {

public:

	/**
	 * Runs game after it is loaded.
	 * 
	 * \return Highest score attained by player in this instance of game
	 */
	int doGame();


	/**
	 * Attemts to load grid into game instance.
	 *
	 * \return False if failed to load grid, else True
	 */
	bool loadGrid(std::ifstream& f);


	/**
	 * Loads bombers based on level and player input. Player gets to choose Which mode the robots in level will be using
	 * They can either be controlled by player, not move at all, or be controlled by computer
	 *
	 * \return False if any bomber failed to load, else True
	 */
	bool loadBombers(std::ifstream& f);


};