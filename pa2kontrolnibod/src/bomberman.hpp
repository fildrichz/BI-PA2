#pragma once

#include "moving_block.hpp"
#include <vector>
#include <iostream>
using namespace std;

/**
 * @brief represents bomberman block in our level. Can be controlled by player, PC (todo) or nobody at all
 * if all bomberman instances controlled by players are destroyed, players lose the game
 * 
 */
class bomberman : public moving_block
{
public:
    /**
     * @brief bomberman moves in chosen direction. If he manages to find powerup block, he gains one random powerup (he does not remove it)
     * 
     * @param grid bomberman sees blocks in game in order to swap with them whe walking
     * @param collumn_target where to move in collumn
     * @param row_target where to move in row
     */
    void move(vector<vector<base_block *>> &grid, int collumn_target, int row_target) override;
    bomberman(int entry_collumn, int entry_row);

    /**
     * @brief bomberman places bomb into grid under himself, it's radius and timer are determined by placing bomberman
     * 
     * @param grid bomb placed into grid
     * @param game_bombs bombs are stashed in separate vector for easier iteration
     * @param collumn_target where placed in collumn
     * @param row_target where placed in row
     * @param placed_by who placed it, for latter point gain
     */
    void place_bomb(vector<vector<base_block *>> &grid, vector<bomb *> &game_bombs, int collumn_target, int row_target, int placed_by);

    /**
     * @brief assissting function for bombs, places down bomb with static time until explosion, not currently used
     * 
     */
    void place_small_bomb(vector<vector<base_block *>> &grid, vector<bomb *> &game_bombs, int collumn_target, int row_target, int placed_by);
    int controls, score;
    int num_placed_bombs, num_possible_bombs, bomb_timer;

private:
    bool rainbow;
    int explosion_radius;
};
