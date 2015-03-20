/*
** resolve_polynoms.c for resolve polynoms in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Thu Mar 12 11:31:16 2015 quentin gasparotto
** Last update Fri Mar 20 18:49:37 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void		resolve_polynoms(double *param, double *k_tab)
{
  double	delta;
  double	k1;
  double	k2;

  delta = pow(param[1], 2.0) - (4.0 * param[0] * param[2]);
  if (delta >= F_ZERO)
    {
      k1 = (-param[1] + sqrt(delta)) / (2.0 * param[0]);
      k2 = (-param[1] - sqrt(delta)) / (2.0 * param[0]);
      printf("%.3f %.3f\n", k1, k2);
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
  printf("cplx\n");
  k_tab[0] = -1.0;
  k_tab[1] = -1.0;
}
