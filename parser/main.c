/*
** main.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Tue May 26 17:05:55 2015 fernand veyrier
** Last update Tue May 26 23:18:16 2015 fernand veyrier
*/

#include "get_next_line.h"

#define HEADER	"^<\\?xml version[[:space:]]*=[[:space:]]*\"[[:digit:].]+\"\\?>$"
#define OBJECT	"[[:space:]]<object>[[:space:]]$"

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

int		follow_pattern(const int fd, regex_t regex,
			       regmatch_t reg_struct)
{
  char		*buffer;
  int		is_invalid;

  while ((buffer = get_next_line(fd)))
    {
      is_invalid = regcomp(&regex, OBJECT, REG_EXTENDED);
      if (is_invalid)
	return (fprintf(stderr, "Regex error.\n"));
      is_invalid = regexec(&regex, buffer, 0, &reg_struct, 0);
      if (is_invalid)
	return (fprintf(stderr, "Invalid XML file.\n"));
    }
  return (0);
}

// devra renvoyer un t_sys
int		get_objects(const int fd)
{
  int		is_invalid;
  regex_t	regex;
  regmatch_t	reg_struct;
  char		*buf;
  size_t	match;

  buf = get_next_line(fd);
  match = 0;
  is_invalid = regcomp(&regex, HEADER, REG_EXTENDED);
  if (is_invalid)
    return (fprintf(stderr, "Regex error.\n"));
  is_invalid = regexec(&regex, buf, match, &reg_struct, 0);
  if (is_invalid)
    return (fprintf(stderr, "Invalid XML header.\n"));
  return (follow_pattern(fd, regex, reg_struct));
}

int		main(int ac, char **av)
{
  int		fd;
  char		*buf;

  if (ac < 2)
    return (-1);
  if ((fd = check_extension(av[1])) == -1)
    return (-1);
  get_objects(fd);
  return (0);
}
