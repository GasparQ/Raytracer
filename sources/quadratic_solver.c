/*
** degre_4_solver.c for degre 4 solver in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Fri Mar 20 16:45:25 2015 quentin gasparotto
** Last update Sat Jun  6 11:49:20 2015 quentin gasparotto
*/

#include "prototypes.h"

void	init_p_q_r(double *pqr, double *param)
{
  pqr[0] = (-3.0 * pow(param[1], 2) / (8.0 * pow(param[0], 2)) +
	    param[2] / param[0]);
  pqr[1] = (pow((param[1] / 2.0), 3) / pow(param[0], 3) -
	    (0.5 * param[1] * param[2]) / pow(param[0], 2) +
	    (param[3] / param[0]));
  pqr[2] = (-3.0 * pow((param[1] / 4.0 / param[0]), 4) +
	    param[2] * (pow((param[1] / 4.0), 2) / pow(param[0], 3)) -
	    (1.0 / 4.0) * param[1] * param[3] / pow(param[0], 2) +
	    param[4] / param[0]);
}

void		double_polynom_resolve(double *param, double *roots, double *pqr)
{
  double	a0;
  double	b0;
  double	y0;

  y0 = roots[0];
  a0 = sqrt(-pqr[0] + 2.0 * y0);
  if (a0 != 0)
    b0 = -pqr[1] / (2.0 * a0);
  else
    b0 = sqrt((y0 * y0) - pqr[2]);
  param[0] = 1;
  param[1] = -a0;
  param[2] = y0 - b0;
  resolve_polynoms(param, roots);
  param[0] = 1;
  param[1] = a0;
  param[2] = y0 + b0;
  resolve_polynoms(param, &roots[2]);
}

int		calc_degre_4(double *param, double *roots)
{
  double	pqr[3];

  init_p_q_r(pqr, param);
  param[0] = 8.0;
  param[1] = -4.0 * pqr[0];
  param[2] = -8.0 * pqr[2];
  param[3] = 4.0 * pqr[2] * pqr[0] - pqr[1] * pqr[1];
  cubic_solver(param, roots);
  double_polynom_resolve(param, roots, pqr);
  return (4);
}

void		final_translation(double *param, double *roots, int deg)
{
  int		rank;
  double	b;

  b = - param[1] / (4.0 * param[0]);
  rank = 0;
  while (rank < deg)
    {
      if (roots[rank] != -4000000000)
	roots[rank] = roots[rank] + b;
      if (roots[rank] == -4000000000 || roots[rank] < F_ZERO)
	roots[rank] = -4000000000;
      rank = rank + 1;
    }
}

int		quadratic_solver(double *param, double *roots)
{
  int		ret;
  double	save_param[5];

  if (param[0] == 0)
    {
      if (param[1] == 0)
	return (resolve_polynoms(&param[2], roots));
      cubic_solver(&param[1], roots);
      return (3);
    }
  else if (param[1] == 0 && param[3] == 0)
    {
      param[1] = param[3];
      resolve_polynoms(param, roots);
      (roots[0] == -4000000000 || roots[0] >= 0) ?
	(roots[0] = sqrt(roots[0])) : (roots[0] = -1.0);
      (roots[1] == -4000000000 || roots[1] >= 0) ?
	(roots[1] = sqrt(roots[1])) : (roots[1] = -1.0);
      return (2);
    }
  tab_ncpy(param, save_param, 5);
  ret = calc_degre_4(param, roots);
  final_translation(save_param, roots, ret);
  return (ret);
}
