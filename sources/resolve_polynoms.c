/*
** resolve_polynoms.c for resolve polynoms in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Thu Mar 12 11:31:16 2015 quentin gasparotto
** Last update Sat Mar 21 17:06:51 2015 quentin gasparotto
*/

#include "prototypes.h"

int		resolve_polynoms(double *param, double *k_tab)
{
  double	delta;
  double	k1;
  double	k2;
  double	sqt;

  delta = pow(param[1], 2.0) - (4.0 * param[0] * param[2]);
  if (delta >= 0)
    {
      sqt = sqrt(delta);
      k1 = (-param[1] + sqt) / (2.0 * param[0]);
      k2 = (-param[1] - sqt) / (2.0 * param[0]);
      k_tab[0] = k1;
      k_tab[1] = k2;
      return (2);
    }
  k_tab[0] = -4000000000;
  k_tab[1] = -4000000000;
  return (2);
}
