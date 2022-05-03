#pragma once

#include "base_block.hpp"
#include <vector>
using namespace std;

/**
 * @brief function for swapping in array of pointers
 * 
 */
void swap_places(base_block **r, base_block **s);


/**
 * @brief represents block which will generally have something under itself
 * has inbuilt move function, but it's primary use in inheritance is the under variable
 * 
 */
class moving_block : public base_block
{
public:
    virtual void move(vector<vector<base_block *>> &grid, int collumn_target, int row_target);
    virtual ~moving_block();
protected:
    base_block *under;
};


/**
 * @brief represents ghosts that will squash players by walking over them.
 * they have inbuild direction which in which they go until they hit something
 * sometimes they change their direction at will for extra fun
 * 
 */
class ghost : public moving_block
{
public:
    void move(vector<vector<base_block *>> &grid, int collumn_target, int row_target) override;
    ghost(int collumn, int row);
    int direction;
};

/**
 * @brief represents bomb placed by player. Its radius and timer are set by creator (placing bomberman)
 */
class bomb : public moving_block
{
public:
    bomb(int collumn, int row, int till_explosion, base_block *place_under, int placed_by, int entry_radius);
    /**
     * @brief periodically updates bomb's mask and finally calls explode method
     * 
     */
    bool tick();
    int who_placed, time_till_explosion, radius;

private:
    bool mega_bomb;
    int direction;
    /**
     * @brief keeps bomb's timer in check. If bomb explodes, returns one. Rest of explosion is processed in read_file 
     * 
     * @return int if bomb is supposed to explode, returns true
     */
    int explode();
};
