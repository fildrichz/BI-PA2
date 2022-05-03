#pragma once

using namespace std;
//#include "main_menu.cpp"
/**
 * @brief main menu of our application. Basis of everything, player can operate it by pressing arrow keys, ENTER and ESCAPE buttons
 * variables made in this function are later passed down to read_file instance and used during course of the game
 * 
 * @return true main menu is reloaded
 * @return false player chose to exit the game by pressing ESC button in main menu
 */
bool main_menu();