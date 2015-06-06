/*
** obj_texture.c for function for applying the object textures in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Jun  3 11:10:13 2015 quentin gasparotto
** Last update Sat Jun  6 19:15:02 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void		basic_color(UNUSED t_vector3 isec_point, UNUSED t_vector3 norm,
			    t_object *touch, void *send_scene)
{
  get_color(touch->obj_color, touch->disp_color, (t_scene *)send_scene);
}

void		text_to_plane(t_vector3 isec_point, UNUSED t_vector3 norm,
			      t_object *touch, void *send_scene)
{
  t_scene	*scene;
  t_vector2	text_pos;

  scene = (t_scene *)send_scene;
  if (touch->texture != NULL)
    {
      text_pos = plane_mapping(isec_point, touch->texture);
      get_pix_color((int)text_pos.x, (int)text_pos.y,
		    *touch->texture, touch->disp_color);
    }
  else
    get_color(touch->obj_color, touch->disp_color, scene);
}

void		text_to_cylinder(t_vector3 isec_point, UNUSED t_vector3 norm,
				 t_object *touch, void *send_scene)
{
  t_vector2	text_pos;
  t_scene	*scene;

  scene = (t_scene *)send_scene;
  if (touch->texture != NULL)
    {
      text_pos = cylinder_map(isec_point, touch->texture);
      get_pix_color((int)text_pos.x, (int)text_pos.y,
		    *touch->texture, touch->disp_color);
    }
  else
    get_color(touch->obj_color, touch->disp_color, scene);
}

void		text_to_cone(t_vector3 isec_point, UNUSED t_vector3 norm,
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

void		text_to_sphere(t_vector3 isec_point, UNUSED t_vector3 norm,
			       t_object *touch, void *send_scene)
{
  t_vector2	text_pos;
  t_scene	*scene;

  scene = (t_scene *)send_scene;
  if (touch->texture != NULL)
    {
      text_pos = sphere_map(isec_point, touch->texture);
      get_pix_color((int)text_pos.x, (int)text_pos.y,
		    *touch->texture, touch->disp_color);
    }
  else if (touch->proced != NULL)
    {
      sphere_proced(isec_point, touch);
    }
  else
    get_color(touch->obj_color, touch->disp_color, scene);
}
