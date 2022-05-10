#include "bomber.hpp"

std::string bomber::getName() const
{
	return playerName;
}

bool bomber::placeBomb(std::vector<std::vector<std::shared_ptr<baseBlock>>> board)
{

	std::shared_ptr<bomb> newBomb = std::make_shared<bomb>(bomb(this->getX(), this->getY(), expSize, bombTimer, std::make_shared<bomber>(this)));


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
			


	return nullptr;
}