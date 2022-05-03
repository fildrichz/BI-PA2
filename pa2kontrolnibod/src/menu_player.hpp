#pragma once

#define num_models 8
#define num_players 4
#define num_controls 4

#include <string>
#include <iostream>
using namespace std;

//player attributes, printed in collumn in main menu
extern const string player_attributes[3];

/**
 * @brief string values represented by numbers inside menu_player instance
 * 
 */
extern const string player_variables[2][8];


/**
 * @brief 
 * represents players in starting menu. Keeps track of their controls and models.
 * many functions reference colours. This has been changed to models, because I was pretty sure our terminal does not support colours
 * and changing models was the next best thing
 */
class menu_player
{
public:
   menu_player();
   menu_player(const unsigned int instance_colour, const unsigned int instance_player);
   /**
     * @brief safely swaps instance's colour/model
     * 
     * @param direction true = move forward, false = move backward
     */
   void colour_swap(const bool direction);

   /**
     * @brief safely swaps instance's ccontrols
     * 
     * @param direction true = move forward, false = move backward
     */
   void controls_swap(const bool direction);

   int get_colour() const;

   int get_player_controls() const;

   /**
     * @brief returns correct value of row of current menu_player instance
     * 
     * @param row 
     */
   string row_output(int collumn, int row);
   /**
     * @brief swaps menu_player variables' values based on input in menu (which row cursor is currently on)
     * 
     * @param row 
     */
   void row_modification(int row);

private:
   int colour, player_controls;

   /**
     * @brief function for safely determining entry's shifted value. Value loops around at 0 and max_number. 
     * Function does not modify any of its entries, only returns value based on them
     * 
     * @param direction direction of swap
     * @param variable variable to be swapped
     * @param max_number ceiling of swapped value
     * @return int value shifted
     */
   int safeswap(const bool direction, const int variable, const int max_number);
};
