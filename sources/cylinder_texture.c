/*
** cylinder_texture.c for function for the cylinder textures in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sat Jun  6 09:54:34 2015 quentin gasparotto
** Last update Sun Jun  7 13:50:08 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

t_vector2	cylinder_map(t_vector3 isec_point, t_image *texture)
{
  t_vector2	text_pos;

  if (isec_point.z < 0)
    isec_point.z += (abs(isec_point.z) / texture->hght + 1) * texture->hght;
  isec_point.z = (int)(isec_point.z) % 200;
  isec_point = unit_vec(isec_point);
  text_pos.x = atan2(isec_point.y, isec_point.x);
  if (text_pos.x < 0)
    text_pos.x += (2 * M_PI);
  text_pos.x /= (2 * M_PI);
  text_pos.y = (int)isec_point.z % (int)texture->hght;
  text_pos.x *= texture->wdth / 4;
  return (text_pos);
}

void		cylinder_bump(t_vector3 isec_point, t_object *touch,
			      t_vector3 *norm)
{
  t_vector2	text_pos;

  text_pos = cylinder_map(isec_point, touch->bump);
  touch->which_bump(text_pos, touch->bump, norm);
}
