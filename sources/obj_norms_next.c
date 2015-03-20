/*
** obj_norms_next.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer/sources
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Fri Mar 20 20:14:08 2015 fernand veyrier
** Last update Fri Mar 20 20:23:33 2015 fernand veyrier
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
