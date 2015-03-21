/*
** tore.c for tore resolution in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Thu Mar 19 19:30:35 2015 quentin gasparotto
** Last update Sat Mar 21 18:29:11 2015 quentin gasparotto
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
	pow(my_obj->mesh.tore->int_r, 2) - pow(my_obj->mesh.tore->ex_r, 2));
  param[0] = pow(sphr, 2);
  param[1] = 4 * sphr * (strgt.point.x * strgt.dir.x +
			 strgt.point.y * strgt.dir.y +
			 strgt.point.z * strgt.point.z);
  param[2] = (2 * sphr * ct - 4 * pow(my_obj->mesh.tore->ex_r, 2) *
	      (pow(strgt.dir.x, 2) + pow(strgt.dir.z, 2)));
  param[3] = ((4 * (strgt.dir.x * strgt.point.x +
		    strgt.dir.y * strgt.point.y +
		    strgt.dir.z * strgt.point.z) * ct -
	       (8 * pow(my_obj->mesh.tore->ex_r, 2) *
		(strgt.point.x * strgt.dir.x + strgt.dir.z * strgt.point.z))));
  param[4] = (ct - 4 * pow(my_obj->mesh.tore->ex_r, 2) *
	      (pow(strgt.point.x, 2) + pow(strgt.point.z, 2)) / param[0]);
}

double		draw_tore(t_streight strgt, t_object *my_obj)
{
  double	param[5];
  double	roots[4];
  int		size;

  init_tore_param(param, strgt, my_obj);
  size = quadratic_solver(param, roots);
  return (get_min(roots, size));
}
