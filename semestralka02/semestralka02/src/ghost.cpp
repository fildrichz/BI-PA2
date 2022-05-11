#include "ghost.hpp"
#include "bomber.hpp"

void ghost::changeDirection()
{
	std::cout << "robot changing direction" << std::endl;

	if (direction == "up")
		direction = "right";
	else if (direction == "right")
		direction = "down";
	else if (direction == "down")
		direction = "left";
	else
		direction = "up";

}


bool ghost::checkFront(std::vector<std::vector<std::shared_ptr<baseBlock>>>& board)
{

	std::cout << "ghost checking front" << std::endl;

	char realDir = direction[0];
	std::vector<int> realTarget;
	realTarget.push_back(this->getX());
	realTarget.push_back(this->getY());

	switch (realDir) {
	case 'u': //up
		realTarget[1] -= 1;
		break;

	case 'd': //down
		realTarget[1] += 1;
		break;

	case 'l': //left
		realTarget[0] -= 1;
		break;

	case 'r': //right
		realTarget[0] += 1;
		break;

	default:
		return false;
	}

	if (!checkDirectionValidity(board, realTarget))
		return false;

	
	else{

		std::cout << "real target is" << realTarget[1] << " " << realTarget[0] << std::endl;

		auto a = std::dynamic_pointer_cast<bomber>(board[realTarget[1]][realTarget[0]]);

		std::cout << "casted" << std::endl;

		if(a)
			if (a->isPlayer()) {
				board[realTarget[1]][realTarget[0]] = board[realTarget[1]][realTarget[0]]->ruin();
				return true;
			}
	}
		

	return false;
	
}

ghost::ghost(const unsigned int x, const unsigned int y): movingBlock(x,y)
{
	mask = 'G';
}

std::shared_ptr<baseBlock> ghost::move(std::vector<std::vector<std::shared_ptr<baseBlock>>>& board)
{

	checkFront(board);

	if (!goInDirection(board, direction))
		changeDirection();

	return nullptr;
}

bool ghost::isPlayer() const
{
	return false;
}

bool ghost::isGhost() const
{
	return isActive;
}

std::shared_ptr<baseBlock> ghost::ruin()
{
	isActive = false;

	if (under != nullptr)
		return under->ruin();

	return std::make_shared<grass>(x, y);
}