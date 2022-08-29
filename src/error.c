/*
** EPITECH PROJECT, 2021
** error.c
** File description:
** desc
*/

#include "../include/sokoban.h"

int valid_file(char const *file)
{
  struct stat s;
  stat(file, &s);
  int fd;
  char *map = malloc(sizeof(char) * s.st_size);
  
  fd = open(file, O_RDONLY);
  if (fd == - 1) {
    write (2, "fichier invalide\n", 18);
    return (84);
  }
  if (read(fd, map, s.st_size) == - 1) {
    write(2, "Lecture du fichier impossible\n", 31);
    return (84);
  }
  close(fd);
  free(map);
  return (0);
}

int valid_map(char **tab)
{
  int x = 0;
  int y = 0;
  
  while (tab[x] != NULL) {
    while (tab[x][y] != '\0') {
      if (tab[x][y] != '\n' && tab[x][y] != ' ' &&
	  tab[x][y] != 'P' && tab[x][y] != '#' &&
	  tab[x][y] != 'O' && tab[x][y] != 'X') {
	write(2, "map invalide\n", 14);
	return (84);
      }
      y++;
    }
    y = 0;
    x++;
  }
  return (0);
}
