/*
** EPITECH PROJECT, 2021
** annexes.c
** File description:
** desc
*/

#include "../include/sokoban.h"

int my_strlen(char const *str)
{
    int i = 0;
    
    while (str[i] != '\0')
        i++;
    return (i);
}

void my_putchar(char c)
{
    write (1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;
    
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}
