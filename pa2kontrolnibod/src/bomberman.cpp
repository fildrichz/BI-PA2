
#include "bomberman.hpp"

bomberman::bomberman(int entry_collumn, int entry_row)
{
    destructible = true;
    passable = false;
    mask = 'B';
    type = 'b';
    destructible = true;
    collumn = entry_collumn;
    row = entry_row;
    under = new grass(entry_row, entry_row);
    score = 0;
    num_possible_bombs = 1;
    num_placed_bombs = 0;
    bomb_timer = 3;
    rainbow = false;
    explosion_radius = 2;
}

void bomberman::move(vector<vector<base_block *>> &grid, int collumn_target, int row_target)
{

    if (rainbow)
    {
        mask++;
        if (mask == 'Z')
        {
            mask = 'A';
        }
    }

    if (grid[row_target][collumn_target]->passable)
    {
        score++;
        swap_places(&under, &grid[row_target][collumn_target]);
        swap_places(&grid[row][collumn], &grid[row_target][collumn_target]);
        if (under->type == 'p')
        {
            switch (score % 6)
            {
            case 0:
                score += 20;
                break;
            case 1:
                num_possible_bombs++;
                break;
            case 2:
                bomb_timer++;
                break;
            case 3:
                bomb_timer--;
                if (bomb_timer < 2)
                {
                    bomb_timer = 2;
                }
                break;
            case 4:
                rainbow = !rainbow;
                break;
            case 5:
                explosion_radius++;
                break;

            default:
                score += 20;
                break;
            }
        }
    }
}

void bomberman::place_bomb(vector<vector<base_block *>> &grid, vector<bomb *> &game_bombs, int collumn_target, int row_target, int placed_by)
{
    if (num_possible_bombs > num_placed_bombs)
    {
        num_placed_bombs++;
        bomb *current_placed = new bomb(collumn_target, row_target, bomb_timer, under, placed_by, explosion_radius);
        game_bombs.push_back(current_placed);
        under = current_placed;
    }
}

void bomberman::place_small_bomb(vector<vector<base_block *>> &grid, vector<bomb *> &game_bombs, int collumn_target, int row_target, int placed_by)
{

    num_placed_bombs++;
    bomb *current_placed = new bomb(collumn_target, row_target, 1, under, placed_by, explosion_radius);
    game_bombs.push_back(current_placed);
    under = current_placed;
}
