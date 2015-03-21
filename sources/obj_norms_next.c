/*
** obj_norms_next.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer/sources
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Fri Mar 20 20:14:08 2015 fernand veyrier
** Last update Sat Mar 21 18:01:26 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void		init_holed_cube_norm(t_vector3 *holed_cube_norm,
				     t_vector3 isec_point, t_object *obj)
{
  (void)obj;
  holed_cube_norm->x = 4 * pow(isec_point.x, 3) - 10 * isec_point.x;
  holed_cube_norm->y = 4 * pow(isec_point.y, 3) - 10 * isec_point.y;
  holed_cube_norm->z = 4 * pow(isec_point.z, 3) - 10 * isec_point.z;
}

void	init_tore_norm(t_vector3 *norm, t_vector3 isec_point, t_object *obj)
{
  norm->x = (4.0 * isec_point.x * (pow(isec_point.x, 2) +
				   pow(isec_point.y, 2) +
				   pow(isec_point.z, 2) +
				   pow(obj->mesh.tore->int_r, 2) -
				   pow(obj->mesh.tore->ex_r, 2)) -
	     8.0 * pow(obj->mesh.tore->int_r, 2) * isec_point.x);
  norm->y = (4.0 * isec_point.y * (pow(isec_point.x, 2) +
				   pow(isec_point.y, 2) +
				   pow(isec_point.z, 2) +
				   pow(obj->mesh.tore->int_r, 2) -
				   pow(obj->mesh.tore->ex_r, 2)));
  norm->z = (4.0 * isec_point.z * (pow(isec_point.x, 2) +
				   pow(isec_point.y, 2) +
				   pow(isec_point.z, 2) +
				   pow(obj->mesh.tore->int_r, 2) -
				   pow(obj->mesh.tore->ex_r, 2)) -
	     8.0 * pow(obj->mesh.tore->int_r, 2) * isec_point.z);
}
