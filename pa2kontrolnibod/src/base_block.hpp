#pragma once
#include <vector>
#include <ncurses.h>
#include <string>
using namespace std;


/**
 * @brief represents a base for blocks of my Bomberman game
 * 
 */
class base_block
{
public:
    base_block() = default;
    base_block(char new_mask, int collumn, int row);
    virtual base_block *destruct();
    virtual ~base_block();

    /**
     * @brief displays base_block's mask at x/y coordinates, at screen which was given as parameter
     * 
     * @param x row value
     * @param y collumn value
     * @param scr where to display
     */
    void display(int x, int y, WINDOW *scr);
    char type;
    bool passable, destructible;
    int collumn, row;
    char mask;

protected:
};


/**
 * @brief consists majority of blocks player will be walking on.
 * 
 */
class grass : public base_block
{
public:
    grass(int x, int y);
};
/**
 * @brief can't be walked on or destroyed
 * 
 */
class solid_wall : public base_block
{
public:
    solid_wall(int x, int y);
};

/**
 * @brief can be destroyed
 * 
 */
class weak_wall : public base_block
{
public:
    weak_wall(int x, int y);
};


/**
 * @brief when walked upon, grants player one of 6 random powerups(random as in based on modulo of player's current score)
 * for easier showcase stays on ground after walked on, cannot be destroyed
 * 
 */
class powerup : public base_block
{
public:
    powerup(int x, int y);
};
