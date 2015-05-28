/*
** tore.c for tore resolution in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Thu Mar 19 19:30:35 2015 quentin gasparotto
** Last update Thu May 28 15:37:03 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void	get_tore_pow(double *pow_point, double *pow_dir, t_streight strgt)
{
  pow_dir[0] = pow(strgt.dir.x, 2);
  pow_dir[1] = pow(strgt.dir.y, 2);
  pow_dir[2] = pow(strgt.dir.z, 2);
  pow_point[0] = pow(strgt.point.x, 2);
  pow_point[1] = pow(strgt.point.y, 2);
  pow_point[2] = pow(strgt.point.z, 2);
}

void	get_rays(double *rays, t_object *my_obj)
{
  rays[0] = pow(my_obj->mesh.tore->int_r, 2);
  rays[1] = pow(my_obj->mesh.tore->ex_r, 2);
}

void	init_tore_param(double *param, t_streight strgt, t_object *my_obj)
{
  double	pow_point[3];
  double	pow_dir[3];
  double	rays[2];

  get_tore_pow(pow_point, pow_dir, strgt);
  get_rays(rays, my_obj);
  param[0] = pow(pow_dir[0] + pow_dir[1] + pow_dir[2], 2);
  param[1] = (4.0 * (pow_dir[0] + pow_dir[1] + pow_dir[2]) *
	      (strgt.point.x * strgt.dir.x + strgt.point.y * strgt.dir.y +
	       strgt.point.z * strgt.dir.z));
  param[2] = (2.0 * (pow_dir[0] + pow_dir[1] + pow_dir[2]) *
	      (pow_point[0] + pow_point[1] + pow_point[2] + rays[0] - rays[1]) +
	      4.0 * pow((strgt.dir.x * strgt.point.x +
			 strgt.dir.y * strgt.point.y +
			 strgt.dir.z * strgt.point.z), 2)
	      - 4.0 * rays[0] * (pow_dir[0] + pow_dir[1]));
  param[3] = (4.0 * (strgt.dir.x * strgt.point.x +
		     strgt.dir.y * strgt.point.y +
		     strgt.dir.z * strgt.point.z) *
	      (pow_point[0] + pow_point[1] + pow_point[2] + rays[0] - rays[1])
	      - 8.0 * rays[0] * (strgt.point.x * strgt.dir.x +
				strgt.point.y * strgt.dir.y));
  param[4] = (pow(pow_point[0] + pow_point[1] + pow_point[2] +
		  rays[0] - rays[1], 2)
	      - 4.0 * rays[0] * (pow_point[0] + pow_point[1]));
}

double		draw_tore(t_streight strgt, t_object *my_obj)
{
  double	param[5];
  double	roots[4];
  int		size;

  invert_translate(&(strgt.point), my_obj->origin);
  invert_rotate_coord(&(strgt.point), my_obj->rotation);
  invert_rotate_coord(&(strgt.dir), my_obj->rotation);
  init_tore_param(param, strgt, my_obj);
  size = quadratic_solver(param, roots);
  return (get_min(roots, size));
}
