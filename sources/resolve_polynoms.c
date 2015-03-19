/*
** resolve_polynoms.c for resolve polynoms in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Thu Mar 12 11:31:16 2015 quentin gasparotto
** Last update Sat Mar 14 19:32:36 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void		resolve_polynoms(t_vector3 param, double *k_tab)
{
  double	delta;
  double	k1;
  double	k2;

  delta = pow(param.y, 2.0) - (4.0 * param.x * param.z);
  if (delta >= F_ZERO)
    {
      k1 = (-param.y + sqrt(delta)) / (2.0 * param.x);
      k2 = (-param.y - sqrt(delta)) / (2.0 * param.x);
      if ((k1 < k2 || k2 < F_ZERO) && k1 >= F_ZERO)
	{
	  k_tab[0] = k1;
	  (k2 >= F_ZERO) ? (k_tab[1] = k2) : (k_tab[1] = -1.0);
	  return ;
	}
      else if (k2 >= F_ZERO)
	{
	  k_tab[0] = k2;
	  (k1 >= F_ZERO) ? (k_tab[1] = k1) : (k_tab[1] = -1.0);
	  return ;
	}
    }
  k_tab[0] = -1.0;
  k_tab[1] = -1.0;
}
