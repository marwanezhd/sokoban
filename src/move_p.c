#include "../include/sokoban.h"

int *found_p(char **tab)
{
    int x = 0;
    int y = 0;
    int *coord = malloc(sizeof(int) * 2); 
    
    while (tab[x] != NULL) {
        while (tab[x][y] != '\0') {
            if (tab[x][y] == 'P') {
                coord[0] = x;
                coord[1] = y;
                return(coord);
            }
            y++;
        }
        x++;
        y = 0;
    }
    return (0);
}

char **moove_p_left(char **tab, int *coord)
{
    int x = coord[0];
    int y = coord[1];
    
    if (tab[x][y - 1] == 'X' && tab[x][y - 2] == ' ' || tab[x][y - 2] == 'O') {
        tab[x][y] = ' ';
        tab[x][y - 1] = 'P';
        tab[x][y - 2] = 'X';
        return (tab);
    }
    if (tab[x][y - 1] == ' ') {
        tab[x][y] = ' ';
        tab[x][y - 1] = 'P';
    }
    return (tab);
}

char **moove_p_right(char **tab, int *coord)
{
    int x = coord[0];
    int y = coord[1];
    
    if (tab[x][y + 1] == 'X' && tab[x][y + 2] == ' ' || tab[x][y + 1] == 'X' && tab[x][y + 2] == 'O') {
        tab[x][y] = ' ';
        tab[x][y + 1] = 'P';
        tab[x][y + 2] = 'X';
        return (tab);
    }
    if (tab[x][y + 1] == ' ') {
        tab[x][y] = ' ';
        tab[x][y + 1] = 'P';
    }
    return (tab);
}

char **moove_p_down(char **tab, int *coord)
{
    int x = coord[0];
    int y = coord[1];
    
    if (tab[x + 1][y] == 'X' && tab[x + 2][y] == ' ' || tab[x + 1][y] == 'X' && tab[x + 2][y] == 'O') {
        tab[x][y] = ' ';
        tab[x + 1][y] = 'P';
        tab[x + 2][y] = 'X';
        return (tab);
    }
    if (tab[x + 1][y] == ' ') {
        tab[x][y] = ' ';
        tab[x + 1][y] = 'P';
    }
    return (tab);
}

char **moove_p_up(char **tab, int *coord)
{
    int x = coord[0];
    int y = coord[1];
    
    if (tab[x - 1][y] == 'X' && tab[x - 2][y] == ' ' || tab[x - 1][y] == 'X' && tab[x - 2][y] == 'O') {
        tab[x][y] = ' ';
        tab[x - 1][y] = 'P';
        tab[x - 2][y] = 'X';
        return (tab);
    }
    if (tab[x - 1][y] == ' ') {
        tab[x][y] = ' ';
        tab[x - 1][y] = 'P';
    }
    return (tab);
}
