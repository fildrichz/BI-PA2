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

        std::cout << " shouldnt change "   << board[0].size() << " " << board.size() << std::endl;

        if (where != 0) {
            if ((saved_row + where) < (board[0].size())) {
                std::cout << "checking row " << (saved_row + where) << " " << saved_col << board[saved_col][saved_row + where]->display() << std::endl;
                board[saved_col][saved_row + where] = board[saved_col][saved_row + where]->ruin();
                std::cout << "after ruination is " << board[saved_col][saved_row + where]->display() << std::endl;
                bonusScore++;
            }
        }


        if(where!=0)
            if ((saved_col + where) < (board.size())) {
                std::cout << "checking col" << saved_row << " " << (saved_col + where) << board[saved_col + where][saved_row]->display() << std::endl;
                board[saved_col + where][saved_row] = board[saved_col + where][saved_row]->ruin();
                std::cout << "after ruination is " << board[saved_col + where][saved_row]->display() << std::endl;
                bonusScore++;
            }

        std::cout << "did thing" << std::endl;
    }

    std::cout << "printing board" << std::endl;
    for (unsigned int x = 0; x < board.size(); x++) {
        for (unsigned int y = 0; y < board[x].size(); y++) {
            std::cout << board[x][y]->display();
        }
        std::cout << std::endl;

    }

    board[saved_col][saved_row] = board[saved_col][saved_row]->ruin();
    
    

    std::cout << "explosion ended" << std::endl;
	return bonusScore;
}

void bomb::bombProcess(std::vector<std::vector<std::shared_ptr<baseBlock>>>& board)
{
    /*
        if (board[y][x]==shared_from_this())
        if(tick())
		    belongsTo->score += explode(board);
    */

    if (tick()) {
        belongsTo->score += explode(board);
    }
		

}

bomb::bomb(const unsigned int x, const unsigned int y, const int eSize, const int timer, std::shared_ptr<bomber> belongsToe):
	baseBlock(x, y, 'B'), timeLeft(timer), explosionSize(eSize), belongsTo(belongsToe)
{
    passable = false;
}
char bomb::display()
{
    //char retval = timeLeft;
    //std::cout << "time left is: " << timeLeft << std::endl;
    return (char)('0' + timeLeft);
}

std::shared_ptr<baseBlock> bomb::ruin()
{
    timeLeft = -2;
    belongsTo->canPlace += 1;

    if (under != nullptr)
        return under->ruin();

    return std::make_shared<grass>(x, y);
}
