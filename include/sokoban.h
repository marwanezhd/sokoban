#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sysexits.h>

int error_management(int ac, char **av);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
void desc(void);
int check_map(char const *file);
char *load_map(char const *file);
int valid_map(char **tab);
int valid_file(char const *file);
char **check_o_replace(char **tab, char **save_tab);
int init_game(void);
int refresh_window(int y, int x, char *str);
int game(char **tab);
char *get_file(char const *file);
void help(void);
int display_map(char **tab);
int *found_p(char **tab);
char **moove_p_left(char **tab, int *coord);
char **moove_p_right(char **tab, int *coord);
char **moove_p_down(char **tab, int *coord);
char **moove_p_up(char **tab, int *coord);
int check_win(char **tab);
int check_lose(char **tab, char **save_tab);
int radius_o(int x, int y, char **save_tab, char **tab);
int radius_p(int x, int y, char **tab);
int check_border(char **tab, int x, int y);
int count_line(char const *map);
int count_char(char const *map);
char **init_tab(char const *str);
char **full_tab(char *map);
