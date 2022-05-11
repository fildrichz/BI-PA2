
#include "movingBlock.hpp"
#include "grass.hpp"

void swap_places(std::shared_ptr<baseBlock>& r, std::shared_ptr<baseBlock>&  s)
{
	std::swap(r->x, s->x);
	std::swap(r->y, s->y);
	swap(r, s);
}

movingBlock::movingBlock(const unsigned int x, const unsigned int y): baseBlock(x,y), isActive(true)
{
	under = std::shared_ptr<grass>(new grass(x, y));
}


bool movingBlock::checkDirectionValidity(const std::vector<std::vector<std::shared_ptr<baseBlock>>>& board, const std::vector<int>& target) const
{
	if(target[0]<0)
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

bool movingBlock::go(std::vector< std::vector< std::shared_ptr<baseBlock>>> & board, const std::vector<int>& target)
{

	//std::cout << "trying to go to: " << target[0] << target[1] << " which is "<< board[target[0]][target[1]]->display() << std::endl;


	if (!board[target[1]][target[0]]->isPassable()) {
		std::cout << "was not passable" << std::endl;
		return false;
	}
	else {
		//std::cout << "is passable" << std::endl;

		std::cout << "moving coordinates are "<< this->getX() << " " << this->getY() << std::endl;

		/**
		 * .
				std::swap(this->x, board[target[0]][target[1]]->x);
		std::cout << "first swap" << std::endl;

		std::swap(this->y, board[target[0]][target[1]]->y);
		std::cout << "second swap" << std::endl;
		 */


		//std::cout << "trying to go to: " << target[0] << target[1] << " which is " << board[target[0]][target[1]]->display() << std::endl;

		//std::cout << "moving coordinates are "<< this->getX() << " " << this->getY() << std::endl;

		//std::cout << "under is: " << under->display() << std::endl;

		//std::cout << "trying to go to: " << target[0] << target[1] << " which is " << board[target[0]][target[1]]->display() << std::endl;

		std::swap(board[target[1]][target[0]], under);

		//std::cout << "trying to go to: " << target[0] << target[1] << " which is " << board[target[0]][target[1]]->display() << std::endl;
		//board[target[0]][target[1]].swap(board[target[this->x]][target[this->y]]);
		//this->under.swap(board[target[0]][target[1]]->under);
		std::swap(board[target[1]][target[0]], board[this->y][this->x]);

		this->x = target[0];
		this->y = target[1];

		std::cout << "went to: " << target[0] << target[1] << " which is " << board[target[1]][target[0]]->display() << std::endl;

		std::cout << "moving coordinates are " << this->getX() << " " << this->getY() << std::endl;

		//std::cout << "trying to go to: " << target[0] << target[1] << " which is " << board[target[0]][target[1]]->display() << std::endl;

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