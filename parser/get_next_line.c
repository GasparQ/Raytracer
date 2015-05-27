/*
** new.c for new get next line in /home/gaspar_q/rendu/Prog_elem_C/CPE_2014_get_next_line
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Fri Dec 26 15:02:58 2014 quentin gasparotto
** Last update Wed May 27 16:09:35 2015 fernand veyrier
*/

#include "get_next_line.h"

char	*get_line(char *save_char, int rank, char *char_read, int rank_read)
{
  char	*line;
  int	len;

  if ((line = malloc(rank + rank_read + 1)) == NULL)
    return (NULL);
  my_strncpy(save_char, line, rank);
  if (char_read != NULL)
    {
      len = 0;
      while (char_read[len++] != '\0');
      if (rank_read > 0)
	my_strncpy(char_read, &line[rank], rank_read);
      my_strncpy(&(char_read[rank_read + 1]), save_char, len - rank_read);
    }
  else
    my_strncpy(&save_char[rank + 1], save_char, 4096 - rank);
  return (line);
}

char	*read_file(const int fd, int *rank_read, int nb_read)
{
  char	*char_read;
  int	lim;

  char_read = NULL;
  while (42)
    {
      char_read = my_realloc(char_read, (nb_read + 1) * 4096 + 1);
      if ((lim = read(fd, &char_read[nb_read * 4096], 4096)) > 0)
	{
	  char_read[lim + 4096 * nb_read] = '\0';
	  *rank_read = search_for_char(char_read);
	  if (char_read[*rank_read] == '\n' || *rank_read < lim)
	    return (char_read);
	  else if (char_read[*rank_read] == '\0')
	    nb_read = nb_read + 1;
	}
      else if (lim == 0)
	return (char_read);
      else if (lim == -1)
	{
	  free(char_read);
	  exit(write(2, "Bad file descriptor\n", 20));
	}
    }
  return (char_read);
}

char		*get_next_line(const int fd)
{
  static char	save_char[4097];
  static int	nb_of_line = 0;
  char		*line;
  char		*char_read;
  int		rank_read;
  int		rank;

  line = NULL;
  rank = 0;
  if (nb_of_line == 0)
    init_buffer(&save_char[0], 4097);
  else
    rank = search_for_char(save_char);
  if (save_char[rank] == '\0')
    {
      rank_read = 0;
      char_read = read_file(fd, &rank_read, 0);
      if (save_char[0] != '\0' || char_read[0] != '\0')
	line = get_line(&save_char[0], rank, char_read, rank_read);
      free(char_read);
    }
  else if (save_char[rank] == '\n')
    line = get_line(&save_char[0], rank, NULL, 0);
  nb_of_line++;
  return (line);
}
