#pragma once

#include <fstream>
#include <vector>
#include <iostream>

#include "baseBlock.hpp"
#include "movingBlock.hpp"
#include "bomb.hpp"
#include "bomber.hpp"
#include "grass.hpp"
#include "sturdyBlock.hpp"
#include "indestructibleBlock.hpp"

class game {

	std::vector< std::vector< std::shared_ptr<baseBlock>>> board;
	std::vector< std::shared_ptr< movingBlock >> movingBlocks;
	std::vector< std::shared_ptr< bomb >> bombs;
	//std::vector< std::shared_ptr< bomber >> bombers;

	unsigned int numOfActivePlayers;


	std::shared_ptr<baseBlock> create(const char& entry, const int& collumn, const int& row);

	void load_screen();

	bool shouldContinue() const;

	int gameCleanUp();


public:


	game();

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


};