/*
** holed_cube.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer/sources
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Fri Mar 20 19:18:52 2015 fernand veyrier
** Last update Sat Jun  6 11:46:12 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void	get_holed_pow(double *d_pow, double *p_pow, t_streight strgt)
{
  d_pow[0] = pow(strgt.dir.x, 2.0);
  d_pow[1] = pow(strgt.dir.y, 2.0);
  d_pow[2] = pow(strgt.dir.z, 2.0);
  p_pow[0] = pow(strgt.point.x, 2.0);
  p_pow[1] = pow(strgt.point.y, 2.0);
  p_pow[2] = pow(strgt.point.z, 2.0);
}

void		init_holed_cube_param(double *param, t_streight strgt,
				      t_object *my_obj)
{
  double	d_pow[3];
  double	p_pow[3];
  double	cote;

  cote = my_obj->mesh.holed_cube->cote;
  get_holed_pow(d_pow, p_pow, strgt);
  param[0] = pow(strgt.dir.x, 4.0) + pow(strgt.dir.y, 4.0) +
    pow(strgt.dir.z, 4.0);
  param[1] = 4.0 * (strgt.point.x * pow(strgt.dir.x, 3.0) +
		    strgt.point.y * pow(strgt.dir.y, 3.0) +
		    strgt.point.z * pow(strgt.dir.z, 3.0));
  param[2] =
    6.0 * (p_pow[0] * d_pow[0] + p_pow[1] * d_pow[1] + p_pow[2] * d_pow[2]) -
    cote * (d_pow[0] + d_pow[1] + d_pow[2]);
  param[3] =
    4.0 * (pow(strgt.point.x, 3.0) * strgt.dir.x +
	   pow(strgt.point.y, 3.0) * strgt.dir.y +
	   pow(strgt.point.z, 3.0) * strgt.dir.z) -
    2.0 * my_obj->mesh.holed_cube->cote *
    (strgt.point.x * strgt.dir.x + strgt.point.y * strgt.dir.y +
     strgt.point.z * strgt.dir.z);
  param[4] = pow(strgt.point.x, 4.0) + pow(strgt.point.y, 4.0) +
    pow(strgt.point.z, 4.0) -
    cote * p_pow[0] - cote * p_pow[1] - cote * p_pow[2] +
    my_obj->mesh.holed_cube->hole_prop;
}

double		draw_holed_cube(t_streight strgt, t_object *my_obj)
{
  double	param[5];
  double	roots[4];
  int		size;

  invert_translate(&(strgt.point), my_obj->origin);
  invert_rotate_coord(&(strgt.point), my_obj->rotation);
  invert_rotate_coord(&(strgt.dir), my_obj->rotation);
  init_holed_cube_param(param, strgt, my_obj);
  size = quadratic_solver(param, roots);
  return (get_min(roots, size));
}
