/*
** obj_texture.c for function for applying the object textures in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Jun  3 11:10:13 2015 quentin gasparotto
** Last update Wed Jun  3 12:35:37 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void		text_to_sphere(t_vector3 isec_point, t_object *touch,
			       void *send_scene)
{
  t_vector2	text_pos;
  t_scene	*scene;
  double	theta;
  double	phi;

  scene = (t_scene *)send_scene;
  if (touch->texture != NULL)
    {
      theta = acos(isec_point.z / touch->mesh.sphere->radius);
      phi = acos(isec_point.x / (touch->mesh.sphere->radius * sin(theta)));
      text_pos.x = (theta / M_PI) * (touch->texture->wdth / 4);
      text_pos.y = ((phi) / (2.0 * M_PI)) * touch->texture->hght;
      if (text_pos.x > (touch->texture->wdth / 4))
      	text_pos.x = (int)text_pos.x % (int)(touch->texture->wdth / 4);
      if (text_pos.y > touch->texture->hght)
      	text_pos.y = (int)text_pos.y % (int)touch->texture->hght;
      get_pix_color((int)text_pos.x, (int)text_pos.y,
		    *touch->texture, touch->disp_color);
    }
  else
    {
      get_color(touch->obj_color, touch->disp_color, scene);
    }
}
