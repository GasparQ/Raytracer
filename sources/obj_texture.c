/*
** obj_texture.c for function for applying the object textures in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Jun  3 11:10:13 2015 quentin gasparotto
** Last update Wed Jun  3 17:15:49 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void		text_to_plane(t_vector3 isec_point, t_vector3 norm,
			      t_object *touch, void *send_scene)
{
  t_scene	*scene;
  t_vector2	text_pos;

  scene = (t_scene *)send_scene;
  if (touch->texture != NULL)
    {
      text_pos.x = (int)(isec_point.x) % (int)(touch->texture->wdth / 4);
      text_pos.x = (text_pos.x < 0) ? -text_pos.x : text_pos.x;
      text_pos.y = (int)(isec_point.y) % (int)touch->texture->hght;
      text_pos.y = (text_pos.y < 0) ? -text_pos.y : text_pos.y;
      get_pix_color((int)text_pos.x, (int)text_pos.y,
		    *touch->texture, touch->disp_color);
    }
  else
    get_color(touch->obj_color, touch->disp_color, scene);
}

void		text_to_cylinder(t_vector3 isec_point, t_vector3 norm,
				 t_object *touch, void *send_scene)
{
  t_vector2	text_pos;
  t_scene	*scene;

  scene = (t_scene *)send_scene;
  if (touch->texture != NULL)
    {
      text_pos.x = acos(isec_point.x / touch->mesh.cylinder->radius) /
	(2 * M_PI);
      text_pos.x = (int)(text_pos.x * (touch->texture->wdth / 4)) %
	(int)(touch->texture->wdth / 4);
      if (text_pos.x < 0)
	text_pos.x = -text_pos.x;
      text_pos.y = isec_point.z / 100;
      text_pos.y = (int)(text_pos.y * touch->texture->hght) %
	(int)touch->texture->hght;
      if (text_pos.y < 0)
	text_pos.y = -text_pos.y;
      get_pix_color((int)text_pos.x, (int)text_pos.y,
		    *touch->texture, touch->disp_color);
    }
  else
    get_color(touch->obj_color, touch->disp_color, scene);
}

void		text_to_cone(t_vector3 isec_point, t_vector3 norm,
			     t_object *touch, void *send_scene)
{
  t_vector2	text_pos;
  t_scene	*scene;

  scene = (t_scene *)send_scene;
  if (touch->texture != NULL)
    {
      text_pos.x = acos(isec_point.x * touch->mesh.cone->phi) /
	(2 * M_PI);
      text_pos.x = (int)(text_pos.x * (touch->texture->wdth / 4)) %
	(int)(touch->texture->wdth / 4);
      if (text_pos.x < 0)
	text_pos.x = -text_pos.x;
      text_pos.y = isec_point.z / tan(touch->mesh.cone->phi);
      text_pos.y = (int)(text_pos.y * touch->texture->hght) %
	(int)touch->texture->hght;
      if (text_pos.y < 0)
	text_pos.y = -text_pos.y;
      get_pix_color((int)text_pos.x, (int)text_pos.y,
		    *touch->texture, touch->disp_color);
    }
  else
    get_color(touch->obj_color, touch->disp_color, scene);
}

void		text_to_sphere(t_vector3 isec_point, t_vector3 norm,
			       t_object *touch, void *send_scene)
{
  t_vector2	text_pos;
  t_scene	*scene;

  scene = (t_scene *)send_scene;
  if (touch->texture != NULL)
    {
      isec_point = unit_vec(isec_point);
      text_pos.x = atan2(isec_point.y, isec_point.x);
      if (text_pos.x < 0)
	text_pos.x += (2 * M_PI);
      text_pos.x /= (2 * M_PI);
      text_pos.y = acos(isec_point.z) / M_PI;
      text_pos.x *= touch->texture->wdth / 4;
      text_pos.y *= touch->texture->hght;
      get_pix_color((int)text_pos.x, (int)text_pos.y,
		    *touch->texture, touch->disp_color);
    }
  else
    get_color(touch->obj_color, touch->disp_color, scene);
}
