
#include "movingBlock.hpp"


void swap_places(std::shared_ptr<baseBlock>& r, std::shared_ptr<baseBlock>&  s)
{
	std::swap(r->x, s->x);
	std::swap(r->y, s->y);
	swap(r, s);
}

movingBlock::movingBlock(const unsigned int x, const unsigned int y): baseBlock(x,y), isActive(true)
{
}


bool movingBlock::checkDirectionValidity(const std::vector<std::vector<std::shared_ptr<baseBlock>>>& board, const std::vector<int>& target) const
{
	if(target[0]<0)
		return false;

	if (target[1] < 0)
		return false;

	if (target[0] >= board[0].size())
		return false;

	if (target[1] >= board.size())
		return false;

	return true;

}

bool movingBlock::active() const
{
	return isActive;
}

bool movingBlock::goInDirection(std::vector<std::vector<std::shared_ptr<baseBlock>>>& board, const std::string& where)
{

	char realDir = where[0];
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

	return go(board, realTarget);
}

bool movingBlock::go(std::vector< std::vector< std::shared_ptr<baseBlock>>> & board, const std::vector<int>& target)
{
	if(!board[target[0]][target[1]]->isPassable())
		return false;
	else {

		std::swap(this->x, board[target[0]][target[1]]->x);
		std::swap(this->y, board[target[0]][target[1]]->y);

		std::swap(board[target[0]][target[1]], board[this->x][this->y]->under);
		//board[target[0]][target[1]].swap(board[target[this->x]][target[this->y]]);
		//this->under.swap(board[target[0]][target[1]]->under);
		std::swap(board[target[0]][target[1]], board[this->x][this->y]);

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


std::shared_ptr<baseBlock> movingBlock::ruin()
{
	isActive = false;

	if (under != nullptr)
		return under;

	return std::shared_ptr<baseBlock>(this);
}

void movingBlock::walkedOn(std::shared_ptr<baseBlock>& thing)
{
}