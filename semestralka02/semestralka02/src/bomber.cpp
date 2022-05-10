#include "bomber.hpp"


bomber::bomber(const unsigned int x, const unsigned int y): movingBlock(x,y), expSize(3), bombTimer(3), score(0)
{
	/*
	* 	std::cout << "enter bomber name: ";
	std::cin >> playerName;
	*/
	
	//todo;

	mask = 'P';
}


std::string bomber::getName() const
{
	return playerName;
}

bool bomber::placeBomb(std::vector<std::vector<std::shared_ptr<baseBlock>>> board)
{

	std::shared_ptr<bomb> newBomb = std::shared_ptr<bomb>(new bomb(this->getX(), this->getY(), expSize, bombTimer, std::shared_ptr<bomber>(this)));


	std::shared_ptr<baseBlock> temp = this->under;
	this->under = newBomb;
	newBomb->under = temp;

	return true;
}


bool bomber::isPlayer() const
{
	return isActive;
}

std::shared_ptr<baseBlock> bomber::move(std::vector<std::vector<std::shared_ptr<baseBlock>>>& board)
{

	std::string command;
	std::cout << "give robot " << getName() << " orders" << std::endl;

	std::cin >> command;

	if(!goInDirection(board, command))
		if (command == "bomb") {
			placeBomb(board);
			return this->under;
		}


	std::shared_ptr<powerup> tempUnder = std::dynamic_pointer_cast<powerup>(under);
	if (tempUnder) {
		tempUnder->effect(std::shared_ptr<bomber>(this));
		under = std::shared_ptr<baseBlock>(new grass(getX(), getY()));
	}

			
	return nullptr;
}

