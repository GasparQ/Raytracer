/*
** cubic_solver.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Thu Mar 19 19:57:46 2015 fernand veyrier
** Last update Sat Mar 21 17:13:28 2015 fernand veyrier
*/

#include <stdlib.h>
#include <math.h>
#include "solver.h"

void		cubic_solver_next(double *param, double *result, t_cubic cubic)
{
  cubic.alpha = 1. / 3. *
    acos(-cubic.q / 2. * pow(27 / (pow(-cubic.p, 3.)), 0.5));
  result[0] = -param[1] / (3 * param[0]) + 2.
    * sqrt(-cubic.p / 3.) * cos(cubic.alpha);
  result[1] = -param[1] / (3 * param[0]) + 2.
    * sqrt(-cubic.p / 3.) * cos(cubic.alpha + (2. * M_PI) / 3.);
  result[2] = -param[1] / (3 * param[0]) + 2.
    * sqrt(-cubic.p / 3.) * cos(cubic.alpha + (4. * M_PI) / 3.);
}

void		cubic_solver(double *param, double *result)
{
  t_cubic	cubic;

  result[0] = -4000000000;
  result[1] = -4000000000;
  result[2] = -4000000000;
  cubic.p = (-pow(param[1], 2) / (3 * pow(param[0], 2)))
    + (param[2] / param[0]);
  cubic.q = param[1] / (27 * param[0]) * ((2 * pow(param[1], 2))
					  / pow(param[0], 2) - (9 * param[2])
					  / param[0]) + (param[3] / param[0]);
  cubic.delta = pow(cubic.q, 2) + (4 * pow(cubic.p, 3)) / 27;
  if (cubic.delta > 0)
    result[0] = cbrt((-cubic.q + sqrt(cubic.delta)) / 2.) +
      cbrt((-cubic.q - sqrt(cubic.delta)) / 2.) - (param[1] / (3. * param[0]));
  else if (cubic.delta == 0)
    {
      if (cubic.p == 0)
	return ((void)(result[0] = cbrt(-cubic.q) - (param[1] /
						     (3 * param[0]))));
      result[0] = (3 * cubic.q) / cubic.p - (param[1] / (3 * param[0]));
      result[1] = (-3 * cubic.q) / (2 * cubic.p) - (param[1] / (3 * param[0]));
      result[2] = result[1];
    }
  else
    cubic_solver_next(param, result, cubic);
}
