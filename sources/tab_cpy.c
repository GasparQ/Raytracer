/*
** tab_cpy.c for cpy a tab of double in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sat Mar 21 11:16:13 2015 quentin gasparotto
** Last update Sat Mar 21 11:17:17 2015 quentin gasparotto
*/

#include "prototypes.h"

void	tab_ncpy(double *src, double *dest, int n)
{
  int	rank;

  rank = 0;
  while (rank < n)
    {
      dest[rank] = src[rank];
      rank = rank + 1;
    }
}
