

#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#include <ncurses.h>
#include "main_menu.hpp"
#include "menu_player.hpp"
#include "level_menu.hpp"
#include "read_file.hpp"
using namespace ::std;

/**
 * @brief main function, keeping track of user's commands and running functions based on them accordingly
 * 
 * @return true when main menu should continue after it's actions (programs resumes from it's default starting state)
 * @return false - user used EXIT command, main loop ends, program ends
 */
bool main_menu()
{
    initscr(); // initialize Ncurses
    noecho();
    cbreak();
    curs_set(0);

    /**
     * constructs new window with parameters based on our current terminal size
     */
    WINDOW *w;
    w = newwin(12, 120, 0, 0);
    box(w, 0, 0);

    /**
     *  array of 4 players is created, default player is controlled by robot, except player 1 who is controlled by wasd
     */
    bool continuation = true, exit = false;
    int player;
    int highlight = 0;
    menu_player menu_players[4];
    for (int i = 0; i < 4; i++)
    {
        for (int y = 0; y < i; y++)
        {
            menu_players[i].colour_swap(true);
        }
    }
    menu_players[0].controls_swap(false);
    menu_players[0].controls_swap(false);
    menu_players[0].controls_swap(false);

    refresh();
    wrefresh(w);

    keypad(w, true);

    mvwprintw(w, 1, 55, "BOMBERMAN!");
    mvwprintw(w, 6, 5, "Welcome to the Bomberman game. Use ARROWS to move around the screen and select variables you would like");
    mvwprintw(w, 7, 5, "to change before starting the game.");
    mvwprintw(w, 8, 5, "You may press SPACE to change selected player attribute.");
    mvwprintw(w, 9, 5, "Once you are satisfied with the game's settings, you may press ENTER in order to continue to level selection.");
    mvwprintw(w, 10, 5, "Press ESC button to exit the game.");

    while (continuation)
    {
        for (int collumn = 0; collumn < 4; collumn++)
        {
            for (int i = 0; i < 3; i++)
            {
                if ((i + collumn * 3) == highlight)
                {
                    wattron(w, A_REVERSE);
                }
                mvwprintw(w, i + 2, 1 + (collumn * 30), player_attributes[i].c_str());
                wattroff(w, A_REVERSE);
                mvwprintw(w, i + 2, 15 + (collumn * 30), "              ");
                mvwprintw(w, i + 2, 15 + (collumn * 30), menu_players[collumn].row_output(collumn, i).c_str());
            }
        }

        player = wgetch(w);

        switch (player)
        {
        case KEY_UP:
            highlight--;
            if (highlight == -1)
            {
                highlight = 0;
                break;
            }
            break;

        case KEY_LEFT:
            highlight -= 3;
            if (highlight < 0)
            {
                highlight += 3;
                break;
            }

            break;

        case KEY_DOWN:
            highlight++;
            if (highlight >= 12)
            {
                highlight = 11;
                break;
            }

            break;

        case KEY_RIGHT:
            highlight += 3;
            if (highlight >= 12)
            {
                highlight -= 3;
                break;
            }

            break;

        default:
            break;
        }

        /**
         *if backspace is pressed, menu_player instaces change accordingly co selested row/collumn
         */
        if (player == 32)
        {
            menu_players[highlight / 3].row_modification(highlight % 3);
        }

        /**
         *menu ends when enter is pressed
         */
        if (player == 10)
        {
            continuation = false;
        }

        /**
         * escape is pressed, Program ends here
         */
        if (player == 27)
        {
            continuation = false;
            exit = true;
        }
    }

    werase(w);
    refresh();
    wrefresh(w);
    delwin(w);
    //endwin();

    if (exit)
    {
        endwin();
        return false;
    }

    int chosen_level = 1;
    chosen_level = level_choice_window();
    if (chosen_level == 0)
    {
        endwin();
        cout << "no acessible levels" << endl
             << flush;
        return false;
    }
    else
    {
        //todo
        //game_window(menu_players,chosen_level);
        //cout << "jedu wokring content " << endl << flush;
        //usleep(1000000);

        working_contents *content = new working_contents(chosen_level, menu_players);
        content->run_game();
        delete (content);
        endwin();
        return true;
    }

    return true;
}