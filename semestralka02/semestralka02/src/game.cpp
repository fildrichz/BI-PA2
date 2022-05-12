
#include "game.hpp"

std::shared_ptr<baseBlock> game::create(const char& entry, const int& collumn, const int& row)
{


    switch (entry){
        case 'B': {

            std::string choice;

            std::cout << "Player or robot? ";
            std::cin >> choice;

            if (choice == "player") {
                std::string pName;
                std::cout << "Choose player name: ";
                std::cin >> pName;
                auto temp = std::make_shared<bomber>(collumn, row);
                temp->playerName = pName;
                movingBlocks.push_back(temp);
                //temp->under = std::shared_ptr<grass>(new grass(collumn, row));

                return temp;
            }
            else {
                std::cout << "Created robot" << std::endl;
                auto robot = std::make_shared<aiBomber>(collumn, row);
                movingBlocks.push_back(robot);

                //robot->under = std::shared_ptr<grass>(new grass(collumn, row));
                return robot;
            }



            }


        case 'G':{
            auto newG = std::make_shared<ghost>(collumn, row);
            movingBlocks.push_back(newG);
            return newG;
        }

        case 'X':
            return std::make_shared<sturdyBlock>(collumn, row);

        case ' ':
            return std::make_shared<grass>(collumn, row);

        case '#':
            return std::make_shared<indestructibleBlock>(collumn, row);

        case 'W':
            return std::make_shared<weakBlock>(collumn, row);

        case 'b':
            return std::make_shared<powerup1>(collumn, row);

        case 'r':
            return std::make_shared<powerup2>(collumn, row);

        case 'a':
            return std::make_shared<powerup3>(collumn, row);

        case 't':
            return std::make_shared<powerup4>(collumn, row);

        default:
            return std::make_shared<grass>(collumn, row);
    }
}

void game::load_screen()
{
    int collumn = 0;
    int row;



    for (std::vector< std::shared_ptr<baseBlock>> &entire_row : board)
    {
        //std::cout << "row:";
        row = 0;
        for (std::shared_ptr<baseBlock> &single : entire_row)
        {
            //std::cout << "a";
            std::cout<< single->display();
            //std::cout << single->getX() << single->getY();
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
        std::cout << "got line: " << line << std::endl;

        std::vector< std::shared_ptr<baseBlock>> newrow;
        newrow.push_back(create('#', 0, row));
        for (collumn = 0; collumn < line.length(); collumn++)
        {
            std::shared_ptr<baseBlock> created = create(line[collumn], collumn + 1, row);
            newrow.push_back(created);
        }

        newrow.push_back(create('#', (line.length() + 1), row));
        board.push_back(newrow);
        row++;
    }

    collumn = 0;
    std::vector< std::shared_ptr<baseBlock>> newrow;
    for (const auto & block : board[0])
    {
        collumn++;
        newrow.push_back(create('#', block->getX(), 0));
    }
    board.insert(board.begin(), newrow);

    collumn = 0;
    std::vector< std::shared_ptr<baseBlock>> anotherrow;
    for (const auto & block : board[0])
    {
        collumn++;
        anotherrow.push_back(create('#', block->getX(), row));
    }
    board.push_back(anotherrow);

    return true;
}


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
        if (object->isPlayer()) {
            std::cout << "player " << std::dynamic_pointer_cast<bomber>(object)->getName() << " has won!" << std::endl;
            std::cout << "their score is " << std::dynamic_pointer_cast<bomber>(object)->score << std::endl;
            return  std::dynamic_pointer_cast<bomber>(object)->score;
        }

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
        //std::cout << "after bomb actions" << std::endl;


        std::cout << "moving blocks" << std::endl;

        //static int counter = 0;

        for (auto & movingblock : movingBlocks) {
            if (movingblock->active()) {

                //if (counter++ == 2)
                    //throw 15;

                auto a = movingblock->move(board);



                if (std::dynamic_pointer_cast<bomb>(a) != nullptr)
                {
                    std::cout << "adding bomb" << std::endl;
                    bombs.push_back(std::dynamic_pointer_cast<bomb>(a));

                }

                load_screen();
            }

        }

    }

    return gameCleanUp();

}
