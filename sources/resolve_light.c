/*
** resolve_light.c for resolve light between all meshes in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Mon Feb 16 15:59:27 2015 quentin gasparotto
** Last update Tue May 26 22:28:02 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void	resolve_brightness(t_object *act_obj, t_spot *act_spot, int rank)
{
  if (act_obj->disp_color[rank] * (1 - act_obj->brightness) +
      act_obj->brightness * act_spot->color[rank] > 255)
    act_obj->disp_color[rank] = 255;
  else
    act_obj->disp_color[rank] =
      act_obj->disp_color[rank] * (1 - act_obj->brightness) +
      act_obj->brightness * act_spot->color[rank];
}

double		resolve_shadow(t_vector3 isec_point,
			       t_system *sys,
			       t_vector3 light_vec,
			       t_vector3 norm)
{
  t_streight	new_ray;
  t_object	*touch;
  double	cos_a;

  if ((cos_a = get_scal(norm, light_vec) /
       (vec_norm(norm) * vec_norm(light_vec))) < F_ZERO)
    return (F_ZERO);
  new_ray = get_streight(light_vec, isec_point);
  if ((touch = bomb_ray(&new_ray, sys->obj_list)) != NULL)
    {
      if (new_ray.lambda > F_ZERO && new_ray.lambda < 1.0)
	return ((1 - touch->opacity) * cos_a);
    }
  return (cos_a);
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
				   t_system *sys)
{
  t_object	*touch;
  t_vector3	isec_point;

  if ((touch = bomb_ray(&reflect_ray, sys->obj_list)) != NULL)
    {
      isec_point = get_isec_point(reflect_ray, touch);
      resolve_light(isec_point, touch, sys, reflect_ray);
      reflect_color(act->disp_color, touch->disp_color, act->reflect,
		    sys->img.bpp / 8);
    }
  else
    reflect_color(act->disp_color, sys->color, act->reflect,
		  sys->img.bpp / 8);
}

void		resolve_light(t_vector3 isec_point,
			      t_object *act_obj,
			      t_system *sys,
			      t_streight strgt)
{
  t_vector3	norm;
  t_vector3	light_vec;
  double	cos_a;
  t_spot	*tmp;

  act_obj->init(&norm, isec_point, act_obj);
  rotate_coord(&norm, act_obj->rotation);
  rotate_coord(&isec_point, act_obj->rotation);
  translate(&isec_point, act_obj->origin);
  init_average(sys->average, sys->img.bpp / 8);
  tmp = sys->spot_list;
  while (tmp != NULL)
    {
      get_color(act_obj->obj_color, act_obj->disp_color, sys);
      light_vec = get_vec_from_points(isec_point, tmp->origin);
      cos_a = resolve_shadow(isec_point, sys, light_vec, norm);
      add_average(sys, tmp, cos_a, act_obj);
      tmp = tmp->next;
    }
  average_to_color(sys->average, act_obj->disp_color,
		   sys->spot_nb, sys->img.bpp / 8);
  if (act_obj->reflect > F_ZERO)
    resolve_reflection(get_reflected_ray(unit_vec(norm),
					 strgt.dir, isec_point),
		       act_obj, sys);
  if (act_obj->opacity > F_ZERO)
    resolve_transparency(get_refracted_ray(unit_vec(norm),
					   strgt.dir, isec_point,
					   act_obj->middle_ind),
			 act_obj, sys);
}
