/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** desc
*/

#include "../include/sokoban.h"

int error_management(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            help();
            return (1);
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    struct stat s;
    stat(av[1], &s);
    char *map = get_file(av[1]);
    char **tab = init_tab(map);
    
    if (error_management(ac, av) == 1)
        return (0);
    if (valid_file(av[1]) == 84)
        return (84);
    init_game();
    if (game(tab) == 1) {
        endwin();
        free(map);
        free(tab);
        return (1);
    }
    endwin();
    free(map);
    free(tab);
    return (0);
}
