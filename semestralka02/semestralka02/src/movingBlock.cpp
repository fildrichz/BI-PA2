#include "movingBlock.hpp"
#include "grass.hpp"

movingBlock::movingBlock(const unsigned int x, const unsigned int y) : baseBlock(x, y), isActive(true)
{
	under = std::shared_ptr<grass>(new grass(x, y));
}

bool movingBlock::checkDirectionValidity(const std::vector<std::vector<std::shared_ptr<baseBlock>>>& board, const std::vector<int>& target) const
{
	if (target[0] < 0)
		return false;

	if (target[1] < 0)
		return false;

	if (target[0] >= int(board[0].size()))
		return false;

	if (target[1] >= int(board.size()))
		return false;

	std::cout << "move is valid" << std::endl;
	return true;
}

bool movingBlock::active() const
{
	return isActive;
}

std::vector<int> movingBlock::getRealTarget(const std::string& where) const
{
	char realDir = where[0];
	std::vector<int> realTarget;
	realTarget.push_back(x);
	realTarget.push_back(y);

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
		return realTarget;
	}
	return realTarget;
}

bool movingBlock::goInDirection(std::vector<std::vector<std::shared_ptr<baseBlock>>>& board, const std::string& where)
{
	std::vector<int>  realTarget = getRealTarget(where);

	if (!checkDirectionValidity(board, realTarget))
		return false;

	return go(board, realTarget);
}

bool movingBlock::go(std::vector< std::vector< std::shared_ptr<baseBlock>>>& board, const std::vector<int>& target)
{
	if (!board[target[1]][target[0]]->isPassable()) {
		return false;
	}
	else {
		std::swap(board[target[1]][target[0]], under);
		std::swap(board[target[1]][target[0]], board[this->y][this->x]);

		this->x = target[0];
		this->y = target[1];
	}
	return true;
}

bool movingBlock::isGhost() const
{
	return false;
}

bool movingBlock::isPlayer() const
{
	return false;
}

void movingBlock::walkedOn(std::shared_ptr<baseBlock>& thing)
{
}