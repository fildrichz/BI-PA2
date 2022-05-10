#include "bomb.hpp"

bool bomb::tick()
{

	timeLeft -= 1;
	if (timeLeft <= 0)
		return true;

	return false;
}

int bomb::explode(std::vector<std::vector<std::shared_ptr<baseBlock>>>& board)
{


    int current_radius = explosionSize;
    size_t saved_row, saved_col;
    saved_row = this->getX();
    saved_col = this->getY();

    int bonusScore = 1;

    for (int where = (-current_radius); where <= current_radius; where++)
    {
        if ((saved_row + where) < (board.size())) {
            board[saved_row + where][saved_col] = board[saved_row + where][saved_col]->ruin();
            bonusScore++;
        }


        if ((saved_col + where) < (board[1].size())) {
            board[saved_row + where][saved_col] = board[saved_row][saved_col + where]->ruin();
            bonusScore++;
        }

    }

	return bonusScore;
}

void bomb::bombProcess(std::vector<std::vector<std::shared_ptr<baseBlock>>>& board)
{
	if (tick())
		belongsTo->score += explode(board);

}

bomb::bomb(const unsigned int x, const unsigned int y, const int eSize, const int timer, std::shared_ptr<bomber> belongsToe):
	baseBlock(x, y, 'B'), timeLeft(timer), explosionSize(eSize), belongsTo(belongsToe)
{
}
