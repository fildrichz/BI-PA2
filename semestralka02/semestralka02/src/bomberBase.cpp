#include "bomber.hpp"

bomberBase::bomberBase(const unsigned int x, const unsigned int y) : movingBlock(x, y), expSize(3), bombTimer(5), canPlace(1), score(0)
{
	mask = 'P';
}

bool bomberBase::placeBomb(std::vector<std::vector<std::shared_ptr<baseBlock>>> board)
{
	std::shared_ptr<bomb> newBomb = std::make_shared<bomb>(x, y, expSize, bombTimer, weak_from_this());
	newBomb->under = this->under;
	this->under = newBomb;

	return true;
}

std::shared_ptr<baseBlock> bomberBase::ruin()
{
	isActive = false;

	if (under != nullptr)
		return under->ruin();

	return std::make_shared<grass>(x, y);
}