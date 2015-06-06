/*
** plan_texture.c for plan texture in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Thu Jun  4 18:55:23 2015 quentin gasparotto
** Last update Sat Jun  6 10:26:01 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

t_vector2	plane_mapping(t_vector3 isec_point, t_image *texture)
{
  t_vector2	text_pos;

  if (isec_point.x < 0)
    isec_point.x += (abs(isec_point.x) / (texture->wdth / 4) + 1) *
      (texture->wdth / 4);
  text_pos.x = (int)isec_point.x % (int)(texture->wdth / 4);
  if (isec_point.y < 0)
    isec_point.y += (abs(isec_point.y) / texture->hght + 1) * texture->hght;
  text_pos.y = (int)(isec_point.y) % (int)texture->hght;
  return (text_pos);
}

void		plane_bump(t_vector3 isec_point, t_object *touch,
			   t_vector3 *norm)
{
  t_vector2	text_pos;

  text_pos = plane_mapping(isec_point, touch->bump);
  touch->which_bump(text_pos, touch->bump, norm);
}
