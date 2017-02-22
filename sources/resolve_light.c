/*
** resolve_light.c for resolve light between all meshes in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Mon Feb 16 15:59:27 2015 quentin gasparotto
** Last update Sun Jun  7 14:44:47 2015 quentin gasparotto
*/

#include "prototypes.h"

void		resolve_brightness(t_object *act_obj, t_scene *scene,
				   int limit)
{
  int		i;
  t_spot	*tmp;

  tmp = scene->spot_list;
  while (tmp != NULL)
    {
      i = 0;
      while (i < limit)
	{
	  if (act_obj->disp_color[i] * (1 - act_obj->phong.brightness) +
	      act_obj->phong.brightness * tmp->color[i] > 0xFF)
	    act_obj->disp_color[i] = 0xFF;
	  else if (act_obj->disp_color[i] * (1 - act_obj->phong.brightness) +
		   act_obj->phong.brightness * tmp->color[i] < 0x00)
	    act_obj->disp_color[i] = 0x00;
	  else
	    act_obj->disp_color[i] =
	      act_obj->disp_color[i] * (1 - act_obj->phong.brightness) +
	      act_obj->phong.brightness * tmp->color[i];
	  ++i;
	}
      tmp = tmp->next;
    }
}

void	reflect_color(unsigned char *obj, unsigned char *ref,
		      double reflect, int lim)
{
  int	rank;

  rank = 0;
  while (rank < lim)
    {
      obj[rank] = ref[rank] * reflect + obj[rank] * (1 - reflect);
      rank = rank + 1;
    }
}

void		resolve_reflection(t_streight reflect_ray, t_object *act,
				   t_scene *scene)
{
  t_object	*touch;
  t_vector3	isec_point;

  if ((touch = get_object(scene->obj_list, &reflect_ray)) != NULL)
    {
      isec_point = get_isec_point(reflect_ray, touch);
      resolve_light(isec_point, touch, scene, reflect_ray);
      reflect_color(act->disp_color, touch->disp_color, act->phong.reflect,
		    scene->act_image->bpp / 8);
    }
  else
    reflect_color(act->disp_color, scene->act_image->color, act->phong.reflect,
		  scene->act_image->bpp / 8);
}

void		resolve_light(t_vector3 isec_point,
			      t_object *act_obj,
			      t_scene *scene,
			      t_streight strgt)
{
  t_vector3	norm;
  t_vector3	use_vectors[3];

  act_obj->init(&norm, isec_point, act_obj);
  act_obj->apply_texture(isec_point, norm, act_obj, scene);
  if (act_obj->apply_bump != NULL && act_obj->bump != NULL)
    act_obj->apply_bump(isec_point, act_obj, &norm);
  rotate_coord(&norm, act_obj->rotation);
  rotate_coord(&isec_point, act_obj->rotation);
  translate(&isec_point, act_obj->origin);
  use_vectors[0] = norm;
  use_vectors[1] = isec_point;
  use_vectors[2] = strgt.dir;
  light_solver(use_vectors, scene, act_obj);
  if (act_obj->effects < 5)
    {
      act_obj->effects += 1;
      if (act_obj->phong.reflect > F_ZERO)
	resolve_reflection(REFLECT(strgt.dir), act_obj, scene);
      if (act_obj->phong.opacity > F_ZERO)
	resolve_transparency(REFRACT(strgt.dir, act_obj->phong.middle_ind),
			     act_obj, scene);
    }
  act_obj->effects -= (act_obj->effects == 5 ? -1 : 0);
}
