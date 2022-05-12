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
    if(canPlace < 1)
        return false;

    int current_radius = expSize;
    size_t saved_row, saved_col;
    saved_row = x;
    saved_col = y;

    for (int where = (-current_radius); where <= current_radius; where++)
    {
        if ((saved_row + where) < (board[0].size())) {
            auto b = std::dynamic_pointer_cast<bomber>(board[saved_col][saved_row + where]);
            if (b)
                if (b->isPlayer())
                    return true;
        }

        
        if ((saved_col + where) < (board.size())) {
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
    bombTimer = 6;
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