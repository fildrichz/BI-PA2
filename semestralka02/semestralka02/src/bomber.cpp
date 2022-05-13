#include "bomber.hpp"


bomber::bomber(const unsigned int x, const unsigned int y) : bomberBase(x,y)
{
	mask = 'P';
}

std::shared_ptr<baseBlock> bomber::move(std::vector<std::vector<std::shared_ptr<baseBlock>>>& board)
{
	std::string command;
	std::cout << "give robot " << playerName << " orders" << std::endl;

	std::cin >> command;

	if (command == "")
		throw std::runtime_error("unexpected blank input");

	if (!goInDirection(board, command))
		if ((command == "bomb") && (canPlace > 0)) {
			canPlace -= 1;
			placeBomb(board);
			return this->under;
		}

	std::shared_ptr<powerup> tempUnder = std::dynamic_pointer_cast<powerup>(under);
	if (tempUnder) {
		tempUnder->effect(std::dynamic_pointer_cast<bomber>(shared_from_this()));
		under = std::shared_ptr<baseBlock>(new grass(x, y));
	}

	return nullptr;
}


bool bomber::isPlayer() const
{
	return isActive;
}