/*
** my_strlen.c for my strlen in /home/gaspar_q/rendu/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Feb  3 17:13:45 2015 quentin gasparotto
** Last update Wed Feb 11 16:14:36 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    {
      while (str[i] != '\0')
	{
	  i = i + 1;
	}
    }
  return (i);
}
