#include "moving_block.hpp"

#include <iostream>
using namespace std;
void swap_places(base_block **r, base_block **s)
{
        swap((*r)->collumn, (*s)->collumn);
        swap((*r)->row, (*s)->row);
        base_block *pSwap = *r;
        *r = *s;
        *s = pSwap;
}

 moving_block::~moving_block(){
         if(under!=NULL)
                delete under;
 }

void moving_block::move(vector<vector<base_block *>> &grid, int collumn_target, int row_target)
{
        if (grid[row_target][collumn_target]->passable)
        {
                swap_places(&under, &grid[row_target][collumn_target]);
                swap_places(&grid[row][collumn], &grid[row_target][collumn_target]);
        }
}

ghost::ghost(int entry_collumn, int entry_row)
{
        type = 'g';
        mask = 'G';
        passable = false;
        destructible = true;
        collumn = entry_collumn;
        row = entry_row;
        under = new grass(entry_row, entry_row);
        direction = 0;
}

void ghost::move(vector<vector<base_block *>> &grid, int collumn_target, int row_target)
{
        if ((grid[row_target][collumn_target]->passable) && (grid[row_target][collumn_target]->type != 'e'))
        {
                swap_places(&under, &grid[row_target][collumn_target]);
                swap_places(&grid[row][collumn], &grid[row_target][collumn_target]);
        }
        else
        {
                direction++;
                direction %= 4;
        }
}

bomb::bomb(int entry_collumn, int entry_row, int till_explosion, base_block *place_under, int placed_by, int entry_radius)
{
        type = 'e'; //explosive
        mask = '1' + till_explosion;
        passable = true;
        destructible = true;
        collumn = entry_collumn;
        row = entry_row;
        under = place_under;
        time_till_explosion = till_explosion * 900;
        who_placed = placed_by;
        radius = entry_radius;
        mega_bomb = false;
}

int bomb::explode()
{
        if (under->destructible == true)
        {
                return 1;
        }
        return 0;
}

bool bomb::tick()
{
        if (((time_till_explosion / 900) > ((time_till_explosion - 20) / 900)) && (time_till_explosion > 0))
        {
                time_till_explosion--;
                mask = '1' + (time_till_explosion / 900);
        }
        else
        {
                time_till_explosion--;
        }

        if (time_till_explosion < 0)
        {
                return true;
        }
        return false;
}