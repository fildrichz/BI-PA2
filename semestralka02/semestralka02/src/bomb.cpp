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

    std::cout << "bomb exploding" << std::endl;

    int current_radius = explosionSize;
    size_t saved_row, saved_col;
    saved_row = this->getX();
    saved_col = this->getY();

    int bonusScore = 1;

    for (int where = (-current_radius); where <= current_radius; where++)
    {

        std::cout << "where: " << where << std::endl;
        std::cout << "row: " << (saved_row + where) << std::endl;
        std::cout << "col: " << (saved_col + where) << std::endl;

        std::cout << " shouldnt change " << board.size() << " " << board[0].size() << std::endl;


        if ((saved_row + where) < (board[0].size())) {
            std::cout << "checking row" << std::endl;
            board[saved_col][saved_row + where] = board[saved_col][saved_row + where]->ruin();
            bonusScore++;
        }

        if(where!=0)
            if ((saved_col + where) < (board.size())) {
                std::cout << "checking col" << std::endl;
                board[saved_col + where][saved_row] = board[saved_col + where][saved_row]->ruin();
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
char bomb::display()
{
    //char retval = timeLeft;
    //std::cout << "time left is: " << timeLeft << std::endl;
    return (char)('0' + timeLeft);
}

