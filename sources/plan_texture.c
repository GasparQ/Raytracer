/*
** plan_texture.c for plan texture in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Thu Jun  4 18:55:23 2015 quentin gasparotto
** Last update Thu Jun  4 20:12:09 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

t_vector2	plane_mapping(t_vector3 isec_point, t_image *texture)
{
  t_vector2	text_pos;

  text_pos.x = (int)(isec_point.x) % (int)(texture->wdth / 4);
  text_pos.x = (text_pos.x < 0) ? -text_pos.x : text_pos.x;
  text_pos.y = (int)(isec_point.y) % (int)texture->hght;
  text_pos.y = (text_pos.y < 0) ? -text_pos.y : text_pos.y;
  return (text_pos);
}

void		plane_bump(t_vector3 isec_point, t_object *touch, t_vector3 *norm)
{
  t_vector2	text_pos;
  int		x_grad;
  int		y_grad;
  int		more[4];

  text_pos = plane_mapping(isec_point, touch->bump);
  more[0] = (text_pos.x - 1 >= 0) ? text_pos.x - 1 : text_pos.x;
  more[1] = (text_pos.x + 1 < touch->bump->wdth / 4) ? text_pos.x + 1 : text_pos.x;
  more[2] = (text_pos.y - 1 >= 0) ? text_pos.y - 1 : text_pos.y;
  more[3] = (text_pos.y + 1 < touch->bump->hght) ? text_pos.y + 1 : text_pos.y;
  x_grad = (get_bump_height(more[0], text_pos.y, touch->bump) -
	    get_bump_height(more[1], text_pos.y, touch->bump));
  y_grad = (get_bump_height(text_pos.x, more[2], touch->bump) -
	    get_bump_height(text_pos.x, more[3], touch->bump));
  *norm = unit_vec(*norm);
  norm->x = norm->x + text_pos.x * x_grad;
  norm->y = norm->y + text_pos.y * y_grad;
  norm->z = norm->z;
}
