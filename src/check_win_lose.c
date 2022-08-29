#include "../include/sokoban.h"

int check_win(char **tab)
{
    int x = 0;
    int y = 0;

    while (tab[x] != NULL) {
        while (tab[x][y] != '\0') {
            if (tab[x][y] == 'O')
                return (1);
            y++;
        }
        y = 0;
        x++;
    }
    return (0);
}

int radius_o(int x, int y, char **save_tab, char **tab)
{
    if (tab[x - 1][y] == '#' && save_tab[x][y] != 'O')
        return (1);
    if (tab[x + 1][y] == '#' && save_tab[x][y] != 'O')
        return (1);
    if (tab[x][y + 1] == '#' && save_tab[x][y] != 'O')
        return (1);
    if (tab[x][y - 1] == '#' && save_tab[x][y] != 'O')
        return (1);
    return (0);
}

int radius_p(int x, int y, char **tab)
{
    if (tab[x - 1][y] == 'P')
        return (1);
    if (tab[x + 1][y] == 'P')
        return (1);
    if (tab[x][y + 1] == 'P')
        return (1);
    if (tab[x][y - 1] == 'P')
        return (1);
    return (0);
}

int check_border(char **tab, int x, int y)
{
    int border = 0;
    
    if (tab[x - 1][y] == '#')
        border = border + 1;
    if (tab[x + 1][y] == '#')
        border = border + 1;
    if (tab[x][y + 1] == '#')
        border = border + 1;
    if (tab[x][y - 1] == '#')
        border = border + 1;
    return (border);
}

int check_lose(char **tab, char **save_tab)
{
    int x = 0;
    int y = 0;
    int *pos_p = found_p(tab);
    int border = 0;
    
    while (tab[x] != NULL) {
        while (tab[x][y] != '\0') {
            border = 0;
            if (tab[x][y] == 'X') {
                border = check_border(tab, x, y);
                if (border == 2)
                    return (1);
            }
            y++;
        }
        y = 0;
        x++;
    }
    return (0);
}
