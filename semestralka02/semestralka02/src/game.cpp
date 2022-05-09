
#include "game.hpp"

std::shared_ptr<baseBlock> game::create(const char& entry, const int& collumn, const int& row)
{
    switch (entry) //character from file
    {
        /**
         * .
    case 'a':
        return new grass(collumn, row);

    case 'p':
        return new powerup(collumn, row);

    case 'i':
        return new solid_wall(collumn, row);

    case 'd':
        return new weak_wall(collumn, row);

    case 'b':
        return new bomberman(collumn, row);

    case 's':
        return new semi_destructible_block(collumn, row);
         * 
         * \param entry
         * \param collumn
         * \param row
         * \return 
         */

    case 'b':
        return std::make_shared<baseBlock>(baseBlock(collumn, row));


    default:
        return std::make_shared<baseBlock>(baseBlock(collumn, row));
    }
}

void game::load_screen()
{
    int collumn = 0;
    int row;



    for (std::vector< std::shared_ptr<baseBlock>> entire_row : board)
    {
        row = 0;
        for (std::shared_ptr<baseBlock> single : entire_row)
        {
            single->display();
            row++;
        }

        std::cout << std::endl;
        collumn++;
    }

    std::cout << "current game state" << std::endl;

}



bool game::loadGrid(std::ifstream& f) {

    std::string line;
    size_t row = 1;
    size_t collumn = 0;
    while (getline(f, line))
    {
        std::vector< std::shared_ptr<baseBlock>> newrow;
        newrow.push_back(create('i', 0, row));
        for (collumn = 0; collumn < line.length(); collumn++)
        {
            std::shared_ptr<baseBlock> created = create(line[collumn], collumn + 1, row);
            newrow.push_back(created);
        }

        newrow.push_back(create('i', (line.length() + 1), row));
        board.push_back(newrow);
        row++;
    }

    collumn = 0;
    std::vector< std::shared_ptr<baseBlock>> newrow;
    for (const auto & block : board[0])
    {
        collumn++;
        newrow.push_back(create('i', block->getX(), 0));
    }
    board.insert(board.begin(), newrow);

    collumn = 0;
    std::vector< std::shared_ptr<baseBlock>> anotherrow;
    for (const auto & block : board[0])
    {
        collumn++;
        anotherrow.push_back(create('i', block->getX(), row));
    }
    board.push_back(anotherrow);


};


game::game(): numOfActivePlayers(0) {
}


bool game::shouldContinue() const {
    unsigned int countPlayers = 0;
    unsigned int countGhosts = 0;

    for (auto& object : movingBlocks) {
        if (object->isGhost())
            countGhosts++;
        if (object->isPlayer())
            countPlayers++;
    }

    if (countPlayers == 0)
        return false;

    if (countPlayers == 1 && countGhosts == 0)
        return false;

    return true;
}

int game::gameCleanUp() {

    for (auto& object : movingBlocks) {
        if (object->isPlayer())
            std::cout << "player " << std::dynamic_pointer_cast<bomber>(object)->getName() << " has won!" << std::endl;
            std::cout << "their score is " << std::dynamic_pointer_cast<bomber>(object)->score << std::endl;
            return  std::dynamic_pointer_cast<bomber>(object)->score;
    }
    
    std::cout << "The ghosts havw won!" << std::endl;
    return 0;
}

int game::doGame() {

    while (shouldContinue()) {

        std::cout << "bomb actions" << std::endl;

        for (auto& bomb : bombs) {
            bomb->bombProcess(board);
        }

        load_screen();
        std::cout << "after bomb actions" << std::endl;


        std::cout << "moving blocks" << std::endl;

        for (auto & movingblock : movingBlocks) {
            movingblock->move();
            load_screen();
        }

    }

    return gameCleanUp();

};
