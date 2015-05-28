/*
** draw_hyperboloid.c for function which will draw an hyperboloid in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed May 27 11:36:14 2015 quentin gasparotto
** Last update Thu May 28 10:26:03 2015 quentin gasparotto
*/

#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

double		draw_hyperboloid(t_streight strgt, t_object *my_obj)
{
  double	param[3];
  double	k_tab[2];

  invert_translate(&(strgt.point), my_obj->origin);
  invert_rotate_coord(&(strgt.point), my_obj->rotation);
  invert_rotate_coord(&(strgt.dir), my_obj->rotation);
  param[0] = (pow(strgt.dir.x, 2.0) / pow(my_obj->mesh.hyperboloid->a, 2.0) +
	      pow(strgt.dir.y, 2.0) / pow(my_obj->mesh.hyperboloid->b, 2.0) -
	      pow(strgt.dir.z, 2.0) / pow(my_obj->mesh.hyperboloid->c, 2.0));
  param[1] = 2.0 * (strgt.point.x * strgt.dir.x /
		    pow(my_obj->mesh.hyperboloid->a, 2.0) +
		    strgt.point.y * strgt.dir.y /
		    pow(my_obj->mesh.hyperboloid->b, 2.0) -
		    strgt.point.z * strgt.dir.z /
		    pow(my_obj->mesh.hyperboloid->c, 2.0));
  param[2] = (pow(strgt.point.x, 2.0) / pow(my_obj->mesh.hyperboloid->a, 2.0) +
	      pow(strgt.point.y, 2.0) / pow(my_obj->mesh.hyperboloid->b, 2.0) -
	      pow(strgt.point.z, 2.0) / pow(my_obj->mesh.hyperboloid->c, 2.0) +
	      my_obj->mesh.hyperboloid->d);
  resolve_polynoms(param, k_tab);
  sort_n_check(k_tab);
  my_obj->rev_norm = (k_tab[1] < F_ZERO) ? -1 : 1;
  return (k_tab[0]);
}
    
