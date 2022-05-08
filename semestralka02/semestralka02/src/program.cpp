
#include "program.hpp"
#include <iostream>


//private methods

bool program::startScreen() {

}

bool program::showLevels() {

}


bool program::loadLevel(std::string name){

}


bool program::loadGrid(){

}


bool program::loadBombers() {

}

bool program::saveResults(const int & newBest) {

}


//public methods

program::program() {

}

program::~program() {

}

bool program::run(){

	if (!startScreen()) {
		std::cout << "error has occured while starting program " << std::endl;
		return false;
	}

	int achievedScore = game.doGame();

	if (achievedScore < 0) {		 //an error has occured in game
		std::cout << "error has occured while playing game, err: " << achievedScore << std::endl;
		return false;
	}


	if (currBestScore < achievedScore)
		std::cout << "saving new best score: " << currBestScore << std::endl;

		if (!saveResults(achievedScore)) {
			std::cout << "error while saving results" << std::endl;
			return false;
			}



	return true;




}
