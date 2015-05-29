/*
** transparency.c for resolve transparence in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Mar 24 19:12:25 2015 quentin gasparotto
** Last update Fri May 29 19:46:49 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void	refract_color(unsigned char *obj, unsigned char *ref,
		      double opacity, int lim)
{
  int	rank;

  rank = 0;
  while (rank < lim)
    {
      obj[rank] = ref[rank] * opacity + obj[rank] * (1 - opacity);
      rank = rank + 1;
    }
}

void	resolve_transparency(t_streight refracted_ray, t_object *act,
			     t_scene *scene)
{
  t_object	*touch;
  t_vector3	isec_point;

  if ((touch = get_object(scene->obj_list, &refracted_ray)) != NULL)
    {
      isec_point = get_isec_point(refracted_ray, touch);
      resolve_light(isec_point, touch, scene, refracted_ray);
      refract_color(act->disp_color, touch->disp_color, act->phong.opacity,
		    scene->act_image->bpp / 8);
    }
  else
    refract_color(act->disp_color, scene->act_image->color,
		  act->phong.opacity, scene->act_image->bpp / 8);
}
