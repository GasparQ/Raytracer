/*
** tore.c for tore resolution in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Thu Mar 19 19:30:35 2015 quentin gasparotto
** Last update Fri Mar 20 11:09:10 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void	init_tore_param(double *param, t_streight strgt, t_object *my_obj)
{
  double	sphr;
  double	ct;

  sphr = pow(strgt.dir.x, 2) + pow(strgt.dir.y, 2) + pow(strgt.dir.z, 2);
  ct = (pow(strgt.point.x, 2) +
	pow(strgt.point.y, 2) +
	pow(strgt.point.z, 2) +
	pow(my_obj->int_r) - pow(my_obj->ex_r));
  param[0] = pow(sphr, 2);
  param[1] = 4 * sphr * (strgt.point.x * strgt.dir.x +
			 strgt.point.y * strgt.dir.y +
			 strgt.point.z * strgt.point.z) / param[0];
  param[2] =
    (2 * sphr * ct - 4 * pow(my_obj->ex_r, 2) * (pow(strgt.dir.x, 2) +
						 pow(strgt.dir.z, 2))) /
    param[0];
  param[3] = ((4 * (strgt.dir.x * strgt.point.x +
		   strgt.dir.y * strgt.point.y +
		   strgt.dir.z * strgt.point.z) * cte -
	      (8 * pow(my_obj->ex_r, 2) *
	       (strgt.point.x * strgt.dir.x + strgt.dir.z * strgt.point.z))))
    / param[0];
  param[4] = cte - 4 * pow(my_obj->ex_r, 2) * (pow(strgt.point.x, 2) +
					       pow(strgt.point.z, 2))
    / param[0];
  param[0] = 1;
}

void	init_second_function(double *param, double *ex_param)
{
  param[0] = 1;
  param[1] = (3 * pow(ex_param[1], 2) / 8 - ex_param[2]) / 2;
  param[2] = (3 * pow(ex_param[1], 4) / 256 - pow(ex_param[1], 2) *
	      ex_param[2] / 16 + ex_param[1] * ex_param[3] / 16 +
	      ex_param[1] * ex_param[3] / 4 - ex_param[4]);
  param[3] = (param[1] * param[2] -
	      pow((pow(ex_param[1], 3) / 16 -
		   param[1] * param[2] / 4 + param[3] / 2), 2));
}

double		get_min(double *roots, int size)
{
  int		rank;
  double	final;

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

double		draw_tore(t_streight strgt, t_object *my_obj)
{
  double	param[5];
  double	param2[4];
  double	*roots;
  double	d;
  double	d_prime;
  double	alpha;
  double	my_roots[4];
  double	k_roots[2];
  t_vector3	param1;

  init_tore_param(param, strgt, my_obj);
  if (param[0] == 0 && param[1] == 0)
    {
      param1.x = param[2];
      param1.y = param[3];
      param1.z = param[4];
      resolve_polynoms(param1, k_roots);
      return (get_min(k_roots, roots, 2));
    }
  else if (param[0] == 0)
    {
      roots = cubic_solver(param);
      return (get_min(roots, 2));
    }
  else
    {
      init_second_function(param2, param);
      roots = cubic_solver(param2);
      if (roots[0] != -1.0)
	{
	  d = 2.0 * (pow(roots[0], 2) + param2[1]);
	  if (d < 0)
	    return (-1.0);
	  else if (d == 0)
	    {
	      d_prime = pow(roots[0], 2) + param2[2];
	      if (d_prime < 0)
		return (-1.0);
	      else
		d_prime = sqrt(d_prime);
	    }
	  else
	    d_prime = sqrt((param2[1] * param2[2] - param2[3]) / d);

	  alpha = d - 4.0 * (roots[0] - d_prime);
	  if (alpha == F_ZERO)
	    {
	      roots[0] = -sqrt(d) / 2.0 + param[0] / 4.0;
	      roots[1] = -1.0;
	    }
	  else if (alpha > F_ZERO)
	    {
	      my_roots[0] = -(sqrt(d) + sqrt(alpha)) / 2.0 - param[0] / 4.0;
	      my_roots[1] = -(sqrt(d) - sqrt(alpha)) / 2.0 - param[0] / 4.0;
	    }
	  else
	    {
	      my_roots[0] = -1.0;
	      my_roots[1] = -1.0;
	    }

	  alpha = d - 4.0 * (roots[0] + d_prime);
	  if (alpha == 0)
	    {
	      my_roots[2] = sqrt(d) / 2 + param[0] / 4.0;
	      my_roots[3] = -1.0;
	    }
	  else if (alpha > 0)
	    {
	      my_roots[2] = (sqrt(d) + sqrt(alpha)) / 2 - param[0] / 4.0;
	      my_roots[3] = (sqrt(d) - sqrt(alpha)) / 2 - param[0] / 4.0;
	    }
	  else
	    {
	      my_roots[2] = -1.0;
	      my_roots[3] = -1.0;
	    }
	  return (get_min(my_roots, 4));
	}
      else
	return (-1.0);
    }
}
