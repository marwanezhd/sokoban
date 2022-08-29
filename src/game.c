#include "../include/sokoban.h"

char **even_key(int key, char **tab, int *coord)
{
    if (key == KEY_LEFT)
        tab = moove_p_left(tab, coord);
    if (key == KEY_RIGHT)
        tab = moove_p_right(tab, coord);
    if (key == KEY_UP)
        tab = moove_p_up(tab, coord);
    if (key == KEY_DOWN)
        tab = moove_p_down(tab, coord);
    return (tab);
}

int game(char **tab)
{
    int *coord;
    int key;
    char **save_tab = tab;
    
    display_map(tab);
    while (key != '\n') {        
        coord = found_p(tab);
        key = getch();
        if (key == ' ')
            game(save_tab);
        tab = even_key(key, tab, coord);
        if (check_win(tab) == 0)
            return (0);
        if (check_lose(tab, save_tab) == 1)
            return (1);
        display_map(tab);
        key = - 1;
    }
    return (0);
}
