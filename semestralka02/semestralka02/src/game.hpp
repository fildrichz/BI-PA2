#pragma once

#include <fstream>
#include <vector>
#include <iostream>

#include "baseBlock.hpp"
#include "movingBlock.hpp"
#include "bomb.hpp"
#include "bomber.hpp"

class game {

	std::vector< std::vector< std::shared_ptr<baseBlock>>> board;
	std::vector< std::shared_ptr< movingBlock >> movingBlocks;
	std::vector< std::shared_ptr< bomb >> bombs;
	//std::vector< std::shared_ptr< bomber >> bombers;

	unsigned int numOfActivePlayers;


	std::shared_ptr<baseBlock> create(const char& entry, const int& collumn, const int& row);

	void load_screen();


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