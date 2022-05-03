#include "base_block.hpp"
using namespace std;

base_block::base_block(char new_mask, int entry_collumn, int entry_row)
{
    mask = new_mask;
    type = new_mask;
    destructible = false;
    passable = false;
    collumn = entry_collumn;
    row = entry_row;
}

base_block *base_block::destruct()
{
    return new grass(collumn, row);
}

base_block::~base_block(){
}

void base_block::display(int x, int y, WINDOW *scr)
{
    char printed[2] = {mask, 0};
    mvwprintw(scr, y, x, (const char *)&printed);
    return;
}

grass::grass(int x, int y)
{
    destructible = true;
    passable = true;
    mask = ' ';
    type = 'a';
    collumn = x;
    row = y;
}

solid_wall::solid_wall(int x, int y)
{
    destructible = false;
    passable = false;
    mask = '#';
    type = 'i';
    collumn = x;
    row = y;
}

weak_wall::weak_wall(int x, int y)
{
    destructible = true;
    passable = false;
    mask = 'X';
    type = 'd';
    collumn = x;
    row = y;
}

powerup::powerup(int x, int y)
{
    destructible = false;
    passable = true;
    mask = 'P';
    type = 'p';
    collumn = x;
    row = y;
}