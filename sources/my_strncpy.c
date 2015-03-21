/*
** my_strncpy.c for mystrncpy in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sat Mar 21 11:09:34 2015 quentin gasparotto
** Last update Sat Mar 21 11:15:55 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void	my_strncpy(char *src, char *dest, int n)
{
  int	rank;

  rank = 0;
  while (rank < n)
    {
      dest[rank] = src[rank];
      rank = rank + 1;
    }
}
