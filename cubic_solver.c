/*
** cubic_solver.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Thu Mar 19 19:57:46 2015 fernand veyrier
** Last update Thu Mar 19 22:21:23 2015 fernand veyrier
*/

#include <stdlib.h>
#include <math.h>

double		*cubic_solver(double *param)
{
  double	p;
  double	q;
  double	delta;
  double	*result;

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
      printf("v = %f u = %f\n", cbrt((-q + sqrt(delta)) / 2.0), cbrt((-q - sqrt(delta)) / 2.0));
      result[0] = cbrt((-q + sqrt(delta)) / 2) + cbrt((-q - sqrt(delta)) / 2);
      printf("result 1 = %f\n", result[0]);
      /* La légende raconte que ce calcul est juste. Il n'en est rien. */
      return (result);
    }
}

int		main(int ac, char **av)
{
  double	param[4] = {-4, 2, 4, -3};

  cubic_solver(param);
}
