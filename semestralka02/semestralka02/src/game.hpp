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
#include "ghost.hpp"
#include "aiBomber.hpp"
#include "weakBlock.hpp"
#include "powerup1.hpp"
#include "powerup2.hpp"
#include "powerup3.hpp"
#include "powerup4.hpp"


/**
 *  game instance.
 */
class game {
	std::vector< std::vector< std::shared_ptr<baseBlock>>> board;
	std::vector< std::shared_ptr< movingBlock >> movingBlocks;
	std::vector< std::shared_ptr< bomb >> bombs;
	//std::vector< std::shared_ptr< bomber >> bombers;

	unsigned int numOfActivePlayers;

	/**
	 * creates new block at coordinates.
	 * 
	 * \param entry type of block
	 * \param collumn coordinate
	 * \param row coordinate 
	 * \return shared_ptr to new block pointer
	 */
	std::shared_ptr<baseBlock> create(const char& entry, const int& collumn, const int& row);


	/**
	 * shows current game state.
	 * 
	 */
	void load_screen();

	/**
	 * determines if game should continue or end.
	 * 
	 * \return true, unless all players are dead, or one is remaining and all ghosts have been eliminated
	 */
	bool shouldContinue() const;

	/**
	 * cleans up after game.
	 * 
	 * \return 
	 */
	int gameCleanUp();

public:

	/**
	 * constructor.
	 * 
	 */
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


	/**
	 * doesnt really do anything, im adding it just to be safe.
	 * 
	 */
	~game() {
		board.clear();
		movingBlocks.clear();
		bombs.clear();
	}
};