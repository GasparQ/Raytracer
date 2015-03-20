/*
** degre_4_solver.c for degre 4 solver in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Fri Mar 20 16:45:25 2015 quentin gasparotto
** Last update Fri Mar 20 19:42:55 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int     valid_roots(double *root, int size)
{
  int	rank;

  rank = 0;
  while (rank < size)
    {
      if (root[rank] > 0)
	return (1);
      rank = rank + 1;
    }
  return (0);
}

void	init_p_q_r(double *p, double *q, double *r, double *param)
{
  double	a = param[0], b = param[1], c = param[2], d = param[3], e = param[4];

  *p = (-3.0 * pow(param[1], 2) / (8.0 * pow(param[0], 2)) + param[2] / param[0]);
  *q = pow((b / 2), 3) / pow(a, 3) - ((1.0 / 2.0) * b * c) / pow(a, 2) + (d / a);
  *r = -3.0 * pow((b / 4.0 / a), 4) + c * (pow((b / 4.0), 2) / pow(a, 3)) - (1.0 / 4.0) * b * d / pow(a, 2) + e / a;
}

int		calc_degre_4(double *param, double *roots)
{
  double	p;
  double	q;
  double	r;
  double	a0;
  double	b0;

  printf("a:%.3f b:%.3f c:%.3f d:%.3f e:%.3f\n", param[0], param[1], param[2], param[3], param[4]);
  init_p_q_r(&p, &q, &r, param);
  printf("p %.3f q %.3f r %.3f\n", p, q, r);
  if (q == F_ZERO)
    {
      roots[0] = -sqrt(p / 2.0 - sqrt(p * p / 4.0 - r));
      roots[1] = -sqrt(p / 2.0 + sqrt(p * p / 4.0 - r));
      roots[2] = sqrt(p / 2.0 - sqrt(p * p / 4.0 - r));
      roots[3] = sqrt(p / 2.0 + sqrt(p * p / 4.0 - r));
      printf("q = 0\n");
      return (4);
    }
  printf("q != 0\n");
  param[0] = 8.0;
  param[1] = -4.0 * p;
  param[2] = -8 * r;
  param[3] = 4.0 * r * p - q * q;
  cubic_solver(param, roots);

  printf("y0 = %.3f\n", roots[0]);

  a0 = sqrt(-p + 2.0 * roots[0]);
  if (a0 != 0)
    b0 = -q / (2.0 * a0);
  else
    b0 = sqrt(pow(roots[0], 2) - r);

  param[0] = 1;
  param[1] = -a0;
  param[2] = roots[0] - b0;
  resolve_polynoms(param, roots);

  param[0] = 1;
  param[1] = a0;
  param[2] = roots[0] + b0;
  resolve_polynoms(param, &roots[2]);

  return (4);
}

void		final_translation(double *param, double *roots)
{
  int		rank;
  double	b;

  b = - param[1] / (4.0 * param[0]);
  rank = 0;
  while (rank < 4)
    {
      if (roots[rank] != -1.0)
	roots[rank] = roots[rank] + b;
      rank = rank + 1;
    }
}

int	        quadratic_solver(double *param, double *roots)
{
  if (param[0] == 0 && param[1] == 0)
    {
      resolve_polynoms(&param[2], roots);
      return (2);
    }
  else if (param[0] == 0)
    {
      cubic_solver(param, roots);
      return (3);
    }
  if (calc_degre_4(param, roots) != -1)
    final_translation(param, roots);
  return (4);
}

int	main(int ac, char **av)
{
  double	param[5];
  double	roots[4];
  int	size;
  int	rank;

  if (ac == 6)
    {
      param[0] = atoi(av[1]);
      param[1] = atoi(av[2]);
      param[2] = atoi(av[3]);
      param[3] = atoi(av[4]);
      param[4] = atoi(av[5]);
      size = quadratic_solver(param, roots);
      printf("\n");
      rank = 0;
      while (rank < size)
      	{
      	  printf("%.3f\n", roots[rank]);
      	  rank = rank + 1;
      	}
      return (0);
    }
  printf("Pas assez d'arg biatch\n");
  return (1);
}
