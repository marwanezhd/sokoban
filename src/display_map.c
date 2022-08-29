#include "../include/sokoban.h"

int display_map(char **tab)
{
    int i = 0;
    int y = 0;
    int x = 0;
    
    while (tab[i] != NULL) {
        mvprintw(y, x, tab[i]);
        y++;
        i++;
    }
    return (0);
}
