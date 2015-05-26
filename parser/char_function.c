/*
** char_function.c for char_function for get next line in /home/gaspar_q/rendu/Prog_elem_C/CPE_2014_get_next_line
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Fri Dec 26 19:09:43 2014 quentin gasparotto
** Last update Tue May 26 17:39:03 2015 fernand veyrier
*/

#include "get_next_line.h"

int	my_strncpy(char *src, char *dest, int n)
{
  int   rank;

  rank = 0;
  while (rank < n)
    {
      dest[rank] = src[rank];
      rank = rank + 1;
    }
  dest[rank] = '\0';
  return (0);
}

int	init_buffer(char *buffer, int size)
{
  int   rank;

  rank = 0;
  while (rank < size)
    {
      buffer[rank] = '\0';
      rank = rank + 1;
    }
  return (0);
}

int	search_for_char(char *buffer)
{
  int   rank;

  rank = 0;
  while (buffer[rank] != '\n' && buffer[rank] != '\0')
    rank = rank + 1;
  return (rank);
}

char	*my_realloc(char *ptr, int new_size)
{
  char  *new_ptr;
  int   rank;

  if ((new_ptr = malloc(new_size)) == NULL)
    return (NULL);
  init_buffer(new_ptr, new_size);
  if (ptr != NULL)
    {
      rank = 0;
      while (ptr[rank] != '\0')
        {
          new_ptr[rank] = ptr[rank];
          rank = rank + 1;
        }
      new_ptr[rank] = '\0';
      free(ptr);
    }
  return (new_ptr);
}
