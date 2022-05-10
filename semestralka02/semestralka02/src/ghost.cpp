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

	char realDir = direction[0];
	std::vector<int> realTarget;
	realTarget.push_back(this->getX());
	realTarget.push_back(this->getY());

	switch (realDir) {
	case 'u':
		realTarget[1] += 1;
		break;

	case 'd':
		realTarget[1] -= 1;
		break;

	case 'l':
		realTarget[0] -= 1;
		break;

	case 'e':
		realTarget[0] += 1;
		break;

	default:
		return false;
	}

	if (!checkDirectionValidity(board, realTarget))
		return false;

	
	if (std::dynamic_pointer_cast<bomber>(board[direction[0]][direction[1]])->isPlayer()) {
		board[direction[0]][direction[1]] = board[direction[0]][direction[1]]->ruin();
		return true;
	}
		

	return false;
	
}

ghost::ghost(const unsigned int x, const unsigned int y): movingBlock(x,y)
{
	mask = 'G';
}

std::shared_ptr<baseBlock> ghost::move(std::vector<std::vector<std::shared_ptr<baseBlock>>>& board)
{
	while (!goInDirection(board, direction))
		changeDirection();

	checkFront(board);

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