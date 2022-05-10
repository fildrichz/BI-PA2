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

    std::cout << "checking for player" << std::endl;

    for (int where = (-current_radius); where <= current_radius; where++)
    {
        if ((saved_row + where) < (board.size())) 
            if (std::dynamic_pointer_cast<bomber>(board[saved_row + where][saved_col])->isPlayer())
                return true;
        


        if ((saved_col + where) < (board[0].size())) 
            if (std::dynamic_pointer_cast<bomber>(board[saved_row][saved_col + where])->isPlayer())
                return true;
        
    }

    return false;

}



aiBomber::aiBomber(const unsigned int x, const unsigned int y): bomber(x,y)
{
    mask = 'R';
    bombTimer = 4;
    playerName = "aiBomber";
}

std::shared_ptr<baseBlock> aiBomber::move(std::vector<std::vector<std::shared_ptr<baseBlock>>>& board)
{


    while (!goInDirection(board, direction))
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