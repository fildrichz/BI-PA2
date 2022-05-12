#include "bomb.hpp"

bool bomb::tick()
{
	timeLeft -= 1;
	if (timeLeft == 0)
		return true;

	return false;
}

int bomb::explode(std::vector<std::vector<std::shared_ptr<baseBlock>>>& board)
{
	int current_radius = explosionSize;
	size_t saved_row, saved_col;
	saved_row = x;
	saved_col = y;

	int bonusScore = 1;

	for (int where = (-current_radius); where <= current_radius; where++)
	{
		if (where != 0)
			if ((saved_row + where) < (board[0].size())) {
				board[saved_col][saved_row + where] = board[saved_col][saved_row + where]->ruin();
				bonusScore++;
			}

		if (where != 0)
			if ((saved_col + where) < (board.size())) {
				board[saved_col + where][saved_row] = board[saved_col + where][saved_row]->ruin();
				bonusScore++;
			}
	}

	board[saved_col][saved_row] = board[saved_col][saved_row]->ruin();

	return bonusScore;
}

void bomb::bombProcess(std::vector<std::vector<std::shared_ptr<baseBlock>>>& board)
{
	if (tick())
		if(auto tempSharedPtr = belongsTo.lock())
			tempSharedPtr->score += explode(board);
}

bomb::bomb(const unsigned int x, const unsigned int y, const int eSize, const int timer, std::weak_ptr<bomber> belongsToe) :
	baseBlock(x, y, 'B'), timeLeft(timer), explosionSize(eSize), belongsTo(belongsToe)
{
	passable = false;
}
char bomb::display()
{
	return (char)('0' + timeLeft);
}

std::shared_ptr<baseBlock> bomb::ruin()
{
	timeLeft = -2;
	if (auto tempSharedPtr = belongsTo.lock())
		tempSharedPtr->canPlace += 1;
	//belongsTo->canPlace += 1;

	if (under != nullptr)
		return under->ruin();

	return std::make_shared<grass>(x, y);
}