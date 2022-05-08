#pragma once

#include "game.hpp"
#include <string>
#include <fstream>
#include <iostream>

class program {

	/*
	Manages life of whole program
	*/
	std::string fileNameLevel;
	game game;
	int currBestScore;


	/**
	 * Starting screen shown to player.
	 * 
	 * \return False if screen fails to load, other than that True
	 */
	bool startScreen();


	/**
	 * Loads levels in level directory.
	 * 
	 * \return False in case no levels found, other than that True
	 */
	bool showLevels();


	/**
	 * Attemts to load level based on its name.
	 * 
	 * \param name, name of the level
	 * \return False if any part failed to load, else True
	 */
	bool loadLevel();






	/**
	 * Method called after game is finished.
	 * Can save achieved results if if should
	 * 
	 * \return False if fails to save for any reason, else True
	 */
	bool saveResults(const int& newBest);

public:


	program();

	~program();

	/**
	 * Managing method of all the parts of program.
	 * Checks if parts are running properly, in case of failure stops the program and cleans up
	 * 
	 * \return True if program ran its course without issues, False if program had to stop unexpectedly
	 */
	bool run();
};