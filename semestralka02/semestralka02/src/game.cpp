
#include "game.hpp"

std::shared_ptr<baseBlock> create(const char& entry, const int& collumn, const int& row)
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

int game::doGame() {

};



bool game::loadGrid(std::ifstream& f) {



};

bool game::loadBombers(std::ifstream& f) {

};
