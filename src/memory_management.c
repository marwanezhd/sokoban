#include "../include/sokoban.h"

int count_line(char const *map)
{
    int i = 0;
    int count = 1;
    
    while (map[i] != '\0') {
        if (map[i] == '\n')
            count++;
        i++;
    }
    return (count);
}

int count_char(char const *map)
{
    int i = 0;
    int j = 0;
    
    while (map[i] != '\0') {
        if (map[i] >= 'a' && map[i] <= 'z' || map[i] >= 'A' && map[i] <= 'Z' || map[i] == '#')
            i++;
        else
            break;
    }
    return (i);
}

char **init_tab(char const *str)
{
    char **tab = malloc(sizeof(char *) * (count_line(str) + 1));
    int x = 0;
    int y = 0;
    int i = 0;
    
    while (x < count_line(str)) {
        y = 0;
        tab[x] = malloc(sizeof(char) * count_char(str));
        while (y != count_char(str)) {
            tab[x][y] = str[i];
            y++;
            i++;
        }
        i = i + 1;
        tab[x][y] = '\0';
        x++;
    }
    tab[x] = NULL;
    return (tab);
}

char *get_file(char const *file)
{
    struct stat s;
    stat(file, &s);
    int fd;
    
    char *map = malloc(sizeof(char) * s.st_size);
    fd = open(file, O_RDONLY);
    read(fd, map, s.st_size);
    close(fd);
    return (map);
}
