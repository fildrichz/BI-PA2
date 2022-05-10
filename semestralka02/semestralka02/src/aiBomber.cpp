#include "aiBomber.hpp"


void aiBomber::changeDirection()
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


bool aiBomber::checkForPlayer(std::vector<std::vector<std::shared_ptr<baseBlock>>>& board)
{
    int current_radius = expSize;
    size_t saved_row, saved_col;
    saved_row = this->getX();
    saved_col = this->getY();

    std::cout << "checking for player " << saved_row << " " <<saved_col << std::endl;

    for (int where = (-current_radius); where <= current_radius; where++)
    {

        std::cout << "where: " << where << std::endl;
        std::cout << "row: " << (saved_row + where) << std::endl;
        if ((saved_row + where) < (board.size())) {
            std::cout << "checking row" << std::endl;
            auto b = std::dynamic_pointer_cast<bomber>(board[saved_col][saved_row + where]);
            if (b)
                if (b->isPlayer())
                    return true;
        }

        

        std::cout << "col: " << (saved_col + where) << std::endl;
        if ((saved_col + where) < (board[0].size())) {
            std::cout << "checking col" << saved_row << " "<< (saved_col + where) << board[saved_row][saved_col + where]->display() << std::endl;
            auto a = std::dynamic_pointer_cast<bomber>(board[saved_col + where][saved_row]);
            if (a)
                if(a->isPlayer())
                    return true;
        }

        
    }

    return false;

}



aiBomber::aiBomber(const unsigned int x, const unsigned int y): bomber(x,y)
{
    mask = 'R';
    bombTimer = 4;
    playerName = "aiBomber";
    direction = "up";
}

std::shared_ptr<baseBlock> aiBomber::move(std::vector<std::vector<std::shared_ptr<baseBlock>>>& board)
{


    if (!goInDirection(board, direction))
        changeDirection();
        
    if (checkForPlayer(board)) {
        placeBomb(board);
        return this->under;
    }


	return nullptr;
}




bool aiBomber::isPlayer() const
{
	return false;
}

bool aiBomber::isGhost() const
{
	return isActive;
}