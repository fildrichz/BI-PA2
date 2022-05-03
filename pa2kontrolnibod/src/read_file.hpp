#pragma once

#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "menu_player.hpp"
#include <ncurses.h>
#include <vector>
#include "base_block.hpp"
#include "bomberman.hpp"
#include <set>

using namespace std;

/**
 * @brief factory for creation of base_block children (pointers)
 * returns pointer to new base_block based on input char (usually same as created block's mask)
 * used when loading new level from file
 * 
 * @param entry char from entry file, usually same as created block's mask
 * @return  returns new base_block* which can be then stored in  vector of polymorphic vectors
 */
base_block *create(char *entry, int collumn, int row);


/**
 * @brief represents out game instance
 * should have probably been singleton, since only one is created troughout the application at a single time
 * 
 */
class working_contents
{
public:
    /**
     * @brief Construct a new working contents object
     * 
     * @param level loads level based on this from examples directory
     * @param players_from_menu players instance, loaded players in game blocks are filled out based on it
     */
    working_contents(int level, menu_player players_from_menu[4]);
    void load_players(menu_player players[4]);

    /**
     * @brief runs main game loop
     * 
     */
    void run_game();

    /**
     * @brief makes moves based on keyboard presses
     * multitouch supported (good for multiplayer on same keyboard)
     * 
     */
    void execute_command(wchar_t command);

    /**
     * @brief similar to execute_command, only based on internal clock
     * 
     */
    void computer_move();

    /**
     * @brief handles all bombs. If bomb timer reaches zero, bomb_ticks() will handle surounding block destruction
     */
    void bombs_tick();

    /**
     * @brief reloads working_contents' screen and updates it
     * 
     */
    void load_screen();

    /**
     * @brief free all remaining blocks at end of program
     * 
     */
    void free_blocks();

private:

    /**
     * @brief determines whether game's ending conditions are met
     * 
     * @return true players won or lost, game ends here
     * @return false game should continue
     */
    bool game_should_run();

    /**
     * @brief path to file from which we loaded, later we will update it with new score
     * 
     */
    string path;
    WINDOW *game_window;
    bool score_changed, players_won;
    char high_score_mask;
    int high_score;
    vector<vector<base_block *>> blocks;
    vector<ghost *> ghosts;
    vector<bomberman *> bombermen_all;
    vector<bomb *> bombs;
};