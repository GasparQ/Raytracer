/*
** get_min_root.c for get min root in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Fri Mar 20 18:33:29 2015 quentin gasparotto
** Last update Fri Mar 20 18:35:02 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

double		get_min(double *roots, int size)
{
  int		rank;
  double	final;

  if (!valid_roots(roots, size))
    return (-1.0);
  final = -1.0;
  rank = 0;
  while (rank < size)
    {
      if ((roots[rank] < 0 && roots[rank] < final) ||
	  (roots[rank] > 0 && final == -1.0))
	final = roots[rank];
      rank = rank + 1;
    }
  return (final);
}