

#include "read_file.hpp"

using namespace std;

void working_contents::load_screen()
{
    int collumn = 0;
    int row;
    for (vector<base_block *> entire_row : blocks)
    {
        row = 0;
        for (base_block *single : entire_row)
        {
            single->display(row + 1, collumn + 1, game_window);
            row++;
        }
        collumn++;
    }
    refresh();
    wrefresh(game_window);
    return;
}

void change_score(string file, long score)
{

    char target[21] = {0};
    std::sprintf(target, "%020ld", score);

    std::fstream fs(file, std::fstream::in | std::fstream::out);
    if (fs.is_open())
    {

        for (int i = 0; i < (int)(sizeof(target) - 1); i++)
        {
            fs.put(target[i]);
            fs.seekp(fs.tellp());
        }

        fs.close();
    }
    else
    {
        std::cout << "Failed to open" << '\n';
    }
}

base_block *create(char entry, int collumn, int row)
{
    switch (entry)
    {

    case 'g':
        return new ghost(collumn, row);
    case 'a':
        return new grass(collumn, row);
    case 'p':
        return new powerup(collumn, row);
    case 'i':
        return new solid_wall(collumn, row);
    case 'd':
        return new weak_wall(collumn, row);
    case 'b':
        return new bomberman(collumn, row);

    default:
        return new base_block(entry, collumn, row);
    }
}

void working_contents::free_blocks()
{

    for (auto &row : blocks)
    {
        for (auto &content : row)
        {
            delete content;
        }
    }

    ghosts.clear();

    bombermen_all.clear();
}

working_contents::working_contents(int level, menu_player players_from_menu[4])
{

    path = "./examples/level";
    path += to_string(level);
    ifstream open_level(path);
    if (!open_level.is_open())
    {
        //how did you even get here?
    }
    else
    {
        string line;
        getline(open_level, line);
        high_score = stoi(line);
        int row = 0;
        while (getline(open_level, line))
        {
            vector<base_block *> newrow;
            for (int collumn = 0; collumn < (int)line.length(); collumn++)
            {
                base_block *created = create(line[collumn], collumn, row);
                if (created->type == 'g')
                {
                    ghosts.push_back((ghost *)created);
                }
                else if (created->type == 'b')
                {
                    bombermen_all.push_back((bomberman *)created);
                }
                newrow.push_back(created);
            }
            blocks.push_back(newrow);
            row++;
        }
        load_players(players_from_menu);
        score_changed = false;
        players_won = false;
    }
}

void working_contents::load_players(menu_player players[4])
{
    int num = 0;
    for (auto guy : bombermen_all)
    {
        guy->mask = player_variables[0][(players[num].get_colour())][0];
        guy->controls = players[num].get_player_controls();
        num++;
    }
    return;
}

void working_contents::execute_command(wchar_t command)
{
    switch (command)
    {
    case 'w':
        for (auto moved : bombermen_all)
        {
            if (moved->controls == 1)
                moved->move(blocks, moved->collumn, (moved->row) - 1);
        }
        return;
    case 'a':
        for (auto moved : bombermen_all)
        {
            if (moved->controls == 1)
                moved->move(blocks, moved->collumn - 1, (moved->row));
        }
        return;
    case 's':
        for (auto moved : bombermen_all)
        {
            if (moved->controls == 1)
                moved->move(blocks, moved->collumn, (moved->row) + 1);
        }
        return;
    case 'd':
        for (auto moved : bombermen_all)
        {
            if (moved->controls == 1)
                moved->move(blocks, moved->collumn + 1, (moved->row));
        }
        return;
    case 'q':
        //bomb
        for (int i = 0; i < (int)bombermen_all.size(); i++)
        {
            if (bombermen_all[i]->controls == 1)
                bombermen_all[i]->place_bomb(blocks, bombs, bombermen_all[i]->collumn, bombermen_all[i]->row, i);
        }
        return;

    case KEY_UP:
        for (auto moved : bombermen_all)
        {
            if (moved->controls == 2)
                moved->move(blocks, moved->collumn, (moved->row) - 1);
        }
        return;
    case KEY_LEFT:
        for (auto moved : bombermen_all)
        {
            if (moved->controls == 2)
                moved->move(blocks, moved->collumn - 1, (moved->row));
        }
        return;
    case KEY_DOWN:
        for (auto moved : bombermen_all)
        {
            if (moved->controls == 2)
                moved->move(blocks, moved->collumn, (moved->row) + 1);
        }
        return;
    case KEY_RIGHT:
        for (auto moved : bombermen_all)
        {
            if (moved->controls == 2)
                moved->move(blocks, moved->collumn + 1, (moved->row));
        }
        return;
    case 'm':
        for (int i = 0; i < (int)bombermen_all.size(); i++)
        {
            if (bombermen_all[i]->controls == 2)
                bombermen_all[i]->place_bomb(blocks, bombs, bombermen_all[i]->collumn, bombermen_all[i]->row, i);
        }
        return;

    default:
        return;
    }
}

void working_contents::computer_move()
{
    for (auto imposter : ghosts)
    {
        if ((bombermen_all[0]->score % 6) == 1)
        {
            imposter->direction++;
        }
        switch (imposter->direction)
        {
        case 0:
            if (blocks[imposter->row + 1][imposter->collumn]->type == 'b')
            {
                for (int z = (bombermen_all.size() - 1); z >= 0; z--)
                {
                    if (blocks[(imposter->row) + 1][imposter->collumn] == bombermen_all[z])
                    {

                        if (bombermen_all[z]->score > high_score)
                        {
                            score_changed = true;
                            high_score = bombermen_all[z]->score;
                            high_score_mask = bombermen_all[z]->mask;
                        }

                        delete bombermen_all[z];
                        bombermen_all.erase(bombermen_all.begin() + z);

                        blocks[(imposter->row) + 1][imposter->collumn] = new grass(imposter->collumn, (imposter->row) + 1);
                        break;
                    }
                }
            }
            imposter->move(blocks, imposter->collumn, (imposter->row) + 1);
            break;
        case 1:
            if (blocks[imposter->row][imposter->collumn + 1]->type == 'b')
            {
                for (int z = (bombermen_all.size() - 1); z >= 0; z--)
                {
                    if (blocks[(imposter->row)][imposter->collumn + 1] == bombermen_all[z])
                    {

                        if (bombermen_all[z]->score > high_score)
                        {
                            score_changed = true;
                            high_score = bombermen_all[z]->score;
                            high_score_mask = bombermen_all[z]->mask;
                        }

                        delete bombermen_all[z];
                        bombermen_all.erase(bombermen_all.begin() + z);

                        blocks[(imposter->row)][imposter->collumn + 1] = new grass(imposter->collumn + 1, (imposter->row));
                        break;
                    }
                }
            }
            imposter->move(blocks, imposter->collumn + 1, (imposter->row));

            break;
        case 2:
            if (blocks[imposter->row - 1][imposter->collumn]->type == 'b')
            {
                for (int z = (bombermen_all.size() - 1); z >= 0; z--)
                {
                    if (blocks[(imposter->row - 1)][imposter->collumn] == bombermen_all[z])
                    {

                        if (bombermen_all[z]->score > high_score)
                        {
                            score_changed = true;
                            high_score = bombermen_all[z]->score;
                            high_score_mask = bombermen_all[z]->mask;
                        }

                        delete bombermen_all[z];
                        bombermen_all.erase(bombermen_all.begin() + z);

                        blocks[(imposter->row) - 1][imposter->collumn] = new grass(imposter->collumn, (imposter->row - 1));
                        break;
                    }
                }
            }
            imposter->move(blocks, imposter->collumn, (imposter->row) - 1);

            break;
        case 3:
            if (blocks[imposter->row][imposter->collumn - 1]->type == 'b')
            {
                for (int z = (bombermen_all.size() - 1); z >= 0; z--)
                {
                    if (blocks[(imposter->row)][imposter->collumn - 1] == bombermen_all[z])
                    {

                        if (bombermen_all[z]->score > high_score)
                        {
                            score_changed = true;
                            high_score = bombermen_all[z]->score;
                            high_score_mask = bombermen_all[z]->mask;
                        }

                        delete bombermen_all[z];
                        bombermen_all.erase(bombermen_all.begin() + z);

                        blocks[(imposter->row)][imposter->collumn - 1] = new grass(imposter->collumn - 1, (imposter->row));
                        break;
                    }
                }
            }
            imposter->move(blocks, imposter->collumn - 1, (imposter->row));

            break;
        default:
            if (blocks[imposter->row][imposter->collumn - 1]->type == 'b')
            {
                for (int z = (bombermen_all.size() - 1); z >= 0; z--)
                {
                    if (blocks[(imposter->row)][imposter->collumn - 1] == bombermen_all[z])
                    {

                        if (bombermen_all[z]->score > high_score)
                        {
                            score_changed = true;
                            high_score = bombermen_all[z]->score;
                            high_score_mask = bombermen_all[z]->mask;
                        }

                        delete bombermen_all[z];
                        bombermen_all.erase(bombermen_all.begin() + z);

                        blocks[(imposter->row)][imposter->collumn - 1] = new grass(imposter->collumn - 1, (imposter->row));
                        break;
                    }
                }
            }
            imposter->move(blocks, imposter->collumn - 1, (imposter->row));
            break;
        }
    }

    return;
}

void working_contents::bombs_tick()
{
    for (int i = (bombs.size() - 1); i >= 0; i--)
    {

        bool tick_return;

        if ((tick_return = (bombs[i]->tick()) )== true)
        {

            if (i < (int)bombermen_all.size())
            {
                bombermen_all[bombs[i]->who_placed]->num_placed_bombs--;
            }

            //

            int save_col, save_row;
            int current_radius = (bombs[i]->radius);
            bool was_destuctible;
            bool bomb_deleted=false;
            for (int col_var = (-current_radius); col_var <= current_radius; col_var++)
            {
                for (int row_var = (-current_radius); row_var <= current_radius; row_var++)
                {
                    if ((row_var == 0) || (col_var == 0))
                    {
                        if ((((bombs[i]->row + row_var) >= 0) && ((bombs[i]->collumn + col_var) >= 0) && ((bombs[i]->row + row_var) < (int)(blocks.size() - 1)) && ((bombs[i]->collumn + col_var) < (int)(blocks[1].size() - 1))))
                        {
                            save_row = bombs[i]->row+row_var;
                            save_col = bombs[i]->collumn+col_var;
                            was_destuctible= blocks[save_row][save_col]->destructible;

                            if (i < (int)bombermen_all.size())
                            {
                                bombermen_all[bombs[i]->who_placed]->score++;
                            }

                            if (blocks[bombs[i]->row + row_var][bombs[i]->collumn + col_var]->type == 'g')
                            {

                                for (int y = (int)(ghosts.size() - 1); y >= 0; y--)
                                {
                                    if (blocks[bombs[i]->row + row_var][bombs[i]->collumn + col_var] == ghosts[y])
                                    {
                                        delete ghosts[y];
                                        ghosts.erase(ghosts.begin() + y);
                                        break;
                                    }
                                }
                            }
                            else if (blocks[bombs[i]->row + row_var][bombs[i]->collumn + col_var]->type == 'b')
                            {

                                if (i < (int)bombermen_all.size())
                                {
                                    bombermen_all[bombs[i]->who_placed]->score++;
                                }

                                for (int z = (bombermen_all.size() - 1); z >= 0; z--)
                                {
                                    if (blocks[bombs[i]->row + row_var][bombs[i]->collumn + col_var] == bombermen_all[z])
                                    {

                                        if (bombermen_all[z]->score > high_score)
                                        {
                                            score_changed = true;
                                            high_score = bombermen_all[z]->score;
                                            high_score_mask = bombermen_all[z]->mask;
                                        }

                                        delete bombermen_all[z];
                                        bombermen_all.erase(bombermen_all.begin() + z);
                                        bomb_deleted=true;

                                        break;
                                    }
                                }
                            }

                             if (was_destuctible)
                            {
                                blocks[save_row][save_col] = new grass(save_col,save_row);
                            }                           
                            /*
                            if (blocks[bombs[i]->row + row_var][bombs[i]->collumn + col_var]->destructible)
                            {
                                blocks[bombs[i]->row + row_var][bombs[i]->collumn + col_var] = new grass(bombs[i]->collumn + col_var, bombs[i]->row + row_var);
                            }
                            */
                        }
                    }
                }
            }
            if(!bomb_deleted){
                delete bombs[i];
            }
            bombs.erase(bombs.begin() + i);
        }
    }

    return;
}

bool working_contents::game_should_run()
{

    if (bombermen_all.size() == 0)
    {
        players_won = false;
        return 0;
    }
    else if ((bombermen_all.size() == 1) && (ghosts.size() == 0))
    {

        if (bombermen_all[0]->score > high_score)
        {
            score_changed = true;
            high_score = bombermen_all[0]->score;
            high_score_mask = bombermen_all[0]->mask;
        }

        players_won = true;
        return 0;
    }
    return 1;
}

void working_contents::run_game()
{

    game_window = newwin(blocks.size() + 2, blocks[0].size() + 2, 0, 0);
    box(game_window, 0, 0);
    refresh();
    wrefresh(game_window);
    keypad(game_window, true);
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    wchar_t entry;
    int stepcount = 0;
    nodelay(game_window, true);
    set<wchar_t> last_pressed;
    set<wchar_t> current_pressed;

    while (game_should_run())
    {

        load_screen();

        while ((entry = wgetch(game_window)) != ERR)
        {
            if ((last_pressed.find(entry) == last_pressed.end()) && (current_pressed.find(entry) == current_pressed.end()))
            {
                current_pressed.insert(entry);
            }
            else
            {
                current_pressed.insert(entry);
            }
        }
        usleep(1000);
        bombs_tick();
        stepcount++;
        stepcount %= 1000;
        if (stepcount % 100 == 0)
        {
            last_pressed = current_pressed;
            current_pressed.clear();
            for (auto const &a : last_pressed)
            {
                execute_command(a);
            }
            load_screen();
            if (stepcount == 0)
            {
                computer_move();
            }
        }
    }

    werase(game_window);
    refresh();

    free_blocks();

    wrefresh(game_window);
    delwin(game_window);

    if (players_won == true)
    {
        cout << "Congratulations, you win!\r" << endl;
    }
    else
    {
        cout << " You lose!\r" << endl;
        ;
    }
    if (score_changed)
    {
        change_score(path, high_score);
        string end_message = "Player ";
        end_message += high_score_mask;
        end_message += " has achieved new high score: ";
        end_message += to_string(high_score);
        cout << (end_message) << "\r" << endl;
    }
    cout << "press any key to return to main menu\r" << flush;
    getch();

    return;
}