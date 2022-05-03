//#pragma once

#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace ::std;

/**
 * @brief attempts to read from file
 * 
 * @return int upon sucessful access to file returns 1, else returns 0
 */
int read_test()
{
    cout << "spustila se" << endl
         << flush;

    ifstream f("./examples/level1");

    if (f.is_open())
    {
        cout << f.rdbuf() << flush;
        cout << "dostala se" << endl
             << flush;
        return 0;
    }
    else
    {
        return 1;
    }
    return 1;
}

/**
 * @brief finds out accessible levels in examples
 * 
 * @return int - greatest number accesible levels by finding one after another 
 */
int number_of_levels()
{
    for (int i = 1; i < 20; i++)
    {
        string level = "./examples/level";
        level += to_string(i);
        ifstream f(level);
        if (!f.is_open())
        {
            return (i);
        }
    }
    return 20;
}
/**
 * @brief window listing levels available to player. 
 * User can move using up/down using arrows on keyboard. 
 * Current chosen level is highlighted. User confirms his choice by pressing ENTER
 * 
 * @return int represents id of level chosen by user. If case of return value = 0 there were no available levels to choose from and game will not start
 */
int level_choice_window()
{
    int num_levels = number_of_levels();

    //no available levels
    if (num_levels == 0)
    {
        return 0;
    }
    //initscr(); // initialize Ncurses
    noecho();
    cbreak();
    curs_set(0);
    int highlight = 1;
    int key;
    WINDOW *ch;
    ch = newwin(num_levels + 3, 35, 0, 0);
    box(ch, 0, 0);
    refresh();
    wrefresh(ch);
    keypad(ch, true);

    mvwprintw(ch, 1, 1, "Levels:");
    mvwprintw(ch, num_levels + 1, 1, "Select level by pressing ENTER");
    while (true)
    {
        for (int collumn = 1; collumn < num_levels; collumn++)
        {
            if ((collumn) == highlight)
            {
                wattron(ch, A_REVERSE);
            }
            mvwprintw(ch, collumn + 1, 1, "level");
            mvwprintw(ch, collumn + 1, 7, to_string(collumn).c_str());
            wattroff(ch, A_REVERSE);
        }

        key = wgetch(ch);

        switch (key)
        {
        case KEY_UP:
            highlight--;
            if (highlight == 0)
            {
                highlight = 1;
                break;
            }

            break;

        case KEY_DOWN:
            highlight++;
            if (highlight >= (num_levels))
            {
                highlight = (num_levels - 1);
                break;
            }
            break;

        default:
            break;
        }
        if (key == 10)
        {
            werase(ch);
            refresh();
            wrefresh(ch);
            delwin(ch);
            //endwin();
            return highlight;
        }
    }
    werase(ch);
    refresh();
    wrefresh(ch);
    delwin(ch);
    //endwin();
}
