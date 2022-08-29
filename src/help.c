#include "../include/sokoban.h"

void help(void)
{
    write(1, "USAGE\n", 7);
    write(1, "      ./my_sokoban map\n", 24);
    write(1, "DESCRIPTION\n", 13);
    write(1, "      map file representing the warehouse map,", 44);
    write(1, " containing '#' for walls,\n", 31);
    write(1, "      'P' for the player, 'X' for boxes", 42);
    write(1, "and ‘O’ for storage locations.\n", 35);
}
