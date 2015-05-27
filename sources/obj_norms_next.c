/*
** obj_norms_next.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer/sources
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Fri Mar 20 20:14:08 2015 fernand veyrier
** Last update Wed May 27 13:45:48 2015 quentin gasparotto
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
  t_vector3	save;

  save = isec_point;
  save.z = 0;
  save = unit_vec(save);
  norm->x = isec_point.x - save.x * obj->mesh.tore->int_r;
  norm->y = isec_point.y - save.y * obj->mesh.tore->int_r;
  norm->z = isec_point.z;
}

void	init_moebius_norm(t_vector3 *norm, t_vector3 isec_point, t_object *obj)
{
  (void)obj;
  (void)norm;
  (void)isec_point;
}

void	init_hyper_norm(t_vector3 *norm, t_vector3 isec_point, t_object *obj)
{
  norm->x = isec_point.x / obj->mesh.hyperboloid->a;
  norm->y = isec_point.y / obj->mesh.hyperboloid->b;
  norm->z = (-1.0) * isec_point.z / obj->mesh.hyperboloid->c;
}
