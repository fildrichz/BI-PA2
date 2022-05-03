#include "menu_player.hpp"

const string player_attributes[3] = {"player number", "model", "controls"};

const string player_variables[2][8]{
    {"A", "B", "C", "D", "E", "F", "G", "H"},
    {"computer", "WASD", "Arrows", "none"}};

menu_player::menu_player()
{
    colour = 0;
    player_controls = 0;
}

//advanced constructor, makes new instance with entry values representing model and controls
menu_player::menu_player(const unsigned int instance_colour, const unsigned int instance_player)
{
    unsigned int temp_colour = 0;
    unsigned int temp_player = 0;
    colour = 0;
    player_controls = 0;
    while (temp_colour < instance_colour)
    {
        temp_colour++;
        colour_swap(1);
    }
    while (temp_player < instance_player)
    {
        temp_player++;
        controls_swap(1);
    }
}

void menu_player::colour_swap(const bool direction)
{
    colour = safeswap(direction, colour, (num_models - 1));
    return;
}

void menu_player::controls_swap(const bool direction)
{
    player_controls = safeswap(direction, player_controls, (num_controls - 1));
    return;
}

int menu_player::get_colour() const
{
    return colour;
}

int menu_player::get_player_controls() const
{
    return player_controls;
}

string menu_player::row_output(int collumn, int row)
{
    switch (row)
    {
    case (0):
        return to_string(collumn + 1);
        break;

    case (1):
        return player_variables[0][get_colour()];
        break;

    case (2):
        return player_variables[1][get_player_controls()];
        break;
    default:
        return "error";
        break;
    }

    return "passed";
}

void menu_player::row_modification(int row)
{
    switch (row)
    {
    case (1):
        colour_swap(true);
        break;

    case (2):
        controls_swap(false);
        break;
    default:
        return;
        break;
    }

    return;
}

int menu_player::safeswap(const bool direction, const int variable, const int max_number)
{
    int return_value = variable;
    if (direction)
    {
        return_value++;
        if (return_value > (max_number))
        {
            return_value = 0;
        }
        return return_value;
    }
    return_value--;
    if (return_value < 0)
    {
        return_value = max_number;
    }
    return return_value;
}
