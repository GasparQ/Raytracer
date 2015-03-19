/*
** my_put_error.c for my put error in /home/gaspar_q/rendu/Igraph/MUL_2014_rtv1/sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Feb  3 17:00:22 2015 quentin gasparotto
** Last update Wed Feb 11 16:26:36 2015 quentin gasparotto
*/

#include <stdlib.h>
#include "../include/prototypes.h"

void	my_put_error(char *str)
{
  int	i;
  int	len;

  if (str != NULL)
    {
      len = my_strlen(str);
      i = 0;
      while (i < len)
	{
	  my_puterrchar(str[i]);
	  i = i + 1;
	}
    }
  else
    {
      my_put_error("Null");
    }
}
