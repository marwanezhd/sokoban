/*
** EPITECH PROJECT, 2021
** init_game.c
** File description:
** desc
*/

#include "../include/sokoban.h"

int init_game(void)
{
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    return (0);
}
