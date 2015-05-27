/*
** objects.c for objects in /home/gaspar_q/rendu/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Feb  3 17:52:32 2015 quentin gasparotto
** Last update Wed May 27 22:00:37 2015 quentin gasparotto
*/

#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

double		draw_sphere(t_streight strgt, t_object *my_obj)
{
  double	param[3];
  double	k_tab[2];

  invert_translate(&(strgt.point), my_obj->origin);
  invert_rotate_coord(&(strgt.point), my_obj->rotation);
  invert_rotate_coord(&(strgt.dir), my_obj->rotation);
  param[0] = (pow(strgt.dir.x, 2.0) +
	     pow(strgt.dir.y, 2.0) +
	     pow(strgt.dir.z, 2.0));
  param[1] = 2.0 * (strgt.point.x * strgt.dir.x +
		   strgt.point.y * strgt.dir.y +
		   strgt.point.z * strgt.dir.z);
  param[2] = (pow(strgt.point.x, 2.0) + pow(strgt.point.y, 2.0) +
	     pow(strgt.point.z, 2.0) - pow(my_obj->mesh.sphere->radius, 2.0));
  resolve_polynoms(param, k_tab);
  sort_n_check(k_tab);
  my_obj->rev_norm = (k_tab[1] < F_ZERO) ? -1 : 1;
  return (k_tab[0]);
}

double		draw_plan(t_streight strgt, t_object *my_obj)
{
  double	k;

  invert_translate(&(strgt.point), my_obj->origin);
  invert_rotate_coord(&(strgt.point), my_obj->rotation);
  invert_rotate_coord(&(strgt.dir), my_obj->rotation);
  k = (-1) * ((my_obj->mesh.plan->norm.x * strgt.point.x +
	       my_obj->mesh.plan->norm.y * strgt.point.y +
	       my_obj->mesh.plan->norm.z * strgt.point.z +
	       my_obj->mesh.plan->d) /
	      (my_obj->mesh.plan->norm.x * strgt.dir.x +
	       my_obj->mesh.plan->norm.y * strgt.dir.y +
	       my_obj->mesh.plan->norm.z * strgt.dir.z));
  if (k >= F_ZERO)
    return (k);
  return (-1.0);
}

double		draw_cylinder(t_streight strgt, t_object *my_obj)
{
  double	param[3];
  double	k_tab[2];

  strgt.lambda = -1.0;
  invert_translate(&(strgt.point), my_obj->origin);
  invert_rotate_coord(&(strgt.point), my_obj->rotation);
  invert_rotate_coord(&(strgt.dir), my_obj->rotation);
  param[0] = (pow(strgt.dir.x, 2.0) +
	     pow(strgt.dir.y, 2.0));
  param[1] = 2.0 * (strgt.point.x * strgt.dir.x +
		   strgt.point.y * strgt.dir.y);
  param[2] = (pow(strgt.point.x, 2.0) + pow(strgt.point.y, 2.0)
	     - pow(my_obj->mesh.cylinder->radius, 2.0));
  resolve_polynoms(param, k_tab);
  sort_n_check(k_tab);
  my_obj->rev_norm = (k_tab[1] < F_ZERO) ? -1 : 1;
  return (k_tab[0]);
}

double		draw_cone(t_streight strgt, t_object *my_obj)
{
  double	param[3];
  double	k_tab[2];

  strgt.lambda = -1.0;
  invert_translate(&(strgt.point), my_obj->origin);
  invert_rotate_coord(&(strgt.point), my_obj->rotation);
  invert_rotate_coord(&(strgt.dir), my_obj->rotation);
  param[0] = (pow(strgt.dir.x, 2) + pow(strgt.dir.y, 2) - pow(strgt.dir.z, 2) *
	     pow(tan(my_obj->mesh.cone->phi), 2));
  param[1] = 2.0 * (strgt.point.x * strgt.dir.x + strgt.point.y * strgt.dir.y -
		   strgt.point.z * strgt.dir.z *
		   pow(tan(my_obj->mesh.cone->phi), 2));
  param[2] = (pow(strgt.point.x, 2) +
	     pow(strgt.point.y, 2) -
	     pow(strgt.point.z, 2) * pow(tan(my_obj->mesh.cone->phi), 2));
  resolve_polynoms(param, k_tab);
  sort_n_check(k_tab);
  my_obj->rev_norm = (k_tab[1] < F_ZERO) ? -1 : 1;
  return (k_tab[0]);
}

double		draw_paraboloid(t_streight strgt, t_object *my_obj)
{
  double	param[3];
  double	k_tab[2];

  strgt.lambda = -1.0;
  invert_translate(&(strgt.point), my_obj->origin);
  invert_rotate_coord(&(strgt.point), my_obj->rotation);
  invert_rotate_coord(&(strgt.dir), my_obj->rotation);
  param[0] = pow(strgt.dir.x, 2.0) + pow(strgt.dir.y, 2.0);
  param[1] = 2.0 * (strgt.point.x * strgt.dir.x +
		   strgt.point.y * strgt.dir.y) -
		   strgt.dir.z * my_obj->mesh.paraboloid->cte;
  param[2] = (pow(strgt.point.x, 2.0) + pow(strgt.point.y, 2.0) -
	     my_obj->mesh.paraboloid->cte * strgt.point.z);
  resolve_polynoms(param, k_tab);
  sort_n_check(k_tab);
  my_obj->rev_norm = (k_tab[1] < F_ZERO) ? -1 : 1;
  return (k_tab[0]);
}
