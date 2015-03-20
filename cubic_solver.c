/*
** cubic_solver.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Thu Mar 19 19:57:46 2015 fernand veyrier
** Last update Fri Mar 20 13:37:34 2015 fernand veyrier
*/

#include <stdlib.h>
#include <math.h>

double		*cubic_solver(double *param)
{
  double	p;
  double	q;
  double	delta;
  double	*result;
  double	alpha;

  ((result = malloc(sizeof(int) * 3)) == NULL) ? exit(-1) : 0;
  result[0] = -1;
  result[1] = -1;
  result[2] = -1;
  p = (-pow(param[1], 2) / (3 * pow(param[0], 2))) + (param[2] / param[0]);
  q = param[1] / (27 * param[0]) * ((2 * pow(param[1], 2)) / pow(param[0], 2) - (9 * param[2]) / param[0]) + (param[3] / param[0]);
  delta = pow(q, 2) + (4 * pow(p, 3)) / 27;
  printf("delta = %f p = %f q = %f\n", delta, p, q);
  if (delta > 0)
    {
      result[0] = cbrt((-q + sqrt(delta)) / 2) + cbrt((-q - sqrt(delta)) / 2) - (param[1] / (3 * param[0]));
      return (result);
    }
  else if (delta == 0)
    {
      if (p == 0)
	{
	  result[0] = cbrt(-q) - (param[1] / (3 * param[0]));
	  return (result);
	}
      result[0] = (3 * q) / p - (param[1] / (3 * param[0]));
      result[1] = (-3 * q) / (2 * p) - (param[1] / (3 * param[0]));
      result[2] = result[1];
      return (result);
    }
  else
    {
      alpha = 1 / 3 * acos(delta);
      result[0] = -param[1] / (3 * param[0]) + 2 * sqrt(-p / 3) * cos(alpha);
      result[1] = -param[1] / (3 * param[0]) + 2 * sqrt(-p / 3) * cos(alpha + (2 * M_PI) / 3);
      result[2] = -param[1] / (3 * param[0]) + 2 * sqrt(-p / 3) * cos(alpha + (4 * M_PI) / 3);
      /* Et là, c'est le drame. */
      printf("z1 = %f z2 = %f z3 = %f\n", result[0], result[1], result[2]);
      return (result);
    }
}

int		main(int ac, char **av)
{
  double	param[4] = {-2, 3, 0, -1};

  cubic_solver(param);
}
