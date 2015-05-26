/*
** main.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Tue May 26 17:05:55 2015 fernand veyrier
** Last update Tue May 26 17:47:26 2015 fernand veyrier
*/

#include "get_next_line.h"

int		check_extension(char *file)
{
  int		fd;

  if (strlen(file) < 4 || strncmp(file + strlen(file) - 4, ".xml", 4))
    {
      fprintf(stderr, "Only .xml extension is valid.\n");
      return (-1);
    }
  if ((fd = open(file, O_RDONLY)) == -1)
    {
      fprintf(stderr, "Error opening file.\n");
      return (-1);
    }
  return (fd);
}

int		main(int ac, char **av)
{
  int		fd;
  char		*buf;

  if (ac < 2)
    return (-1);
  if ((fd = check_extension(av[1])) == -1)
    return (-1);
  while ((buf = get_next_line(fd)) != NULL)
    {
      printf("%s\n", buf);
    }
  return (0);
}
