
#include "program.hpp"

//private methods

bool program::startScreen() {
	std::cout << "Welcome to BOMBERMAN!" << std::endl;
	std::cout << "Choose which level you would like to play: " << std::endl;

	if (!showLevels()) {
		return false;
	}

	if (!loadLevel()) {
		return false;
	}

	std::cout << "level loaded" << std::endl;
}

bool program::showLevels() {

	int i = 1;

	for (i; i < 20; i++)
	{
		std::string level = "./levels/level";
		level += std::to_string(i);
		std::ifstream f(level);
		if (!f.is_open())
			break;
		
		std::cout << "level " << i << " available" << std::endl;
	}

	if (i == 1) {
		std::cout << "no levels available" << std::endl;
		return false;
	}

	return true;
}


bool program::loadLevel(){
	
	int userLvl;

	std::cout << "Index of level you would like to play? ";

	std::cin >> userLvl;
	
	fileNameLevel += std::to_string(userLvl);

	std::ifstream f(fileNameLevel);


	if (!f.is_open())
	{
		std::cout << "could not open file stream" << std::endl;
		return false;
	}


	if (!game.loadGrid(f))
	{
		if (f.is_open())
			f.close();

		std::cout << "failed to load grid" << std::endl;
		return false;
	}

	if (!game.loadBombers(f))
	{
		if (f.is_open())
			f.close();
		
		std::cout << "failed to load bombers" << std::endl;
		return false;
	}

	std::cout << "level loaded sucessfully" << std::endl;
	if (f.is_open())
		f.close();
	
	return true;

}

bool program::saveResults(const int & newBest) {

}


//public methods

program::program(): fileNameLevel("./levels/level"), currBestScore(0) {
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
