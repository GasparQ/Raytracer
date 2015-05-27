/*
** disp_color.c for disp color in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1/sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Thu Mar 12 11:48:17 2015 quentin gasparotto
** Last update Wed May 27 10:20:38 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void	init_streight(t_streight *strgt, double dist, int x, int y)
{
  strgt->dir.x = dist;
  strgt->dir.y = WDW_WIDTH / 2.0 - (double)x;
  strgt->dir.z = WDW_HEIGHT / 2.0 - (double)y;
}

t_object	*resolve_limits(t_object *touch_obj, t_streight *strgt)
{
  t_vector3	isec_point;
  t_streight	new_ray;
  t_object	*lim;

  if (touch_obj == NULL)
    return (NULL);
  if (touch_obj->limit != NULL)
    {
      isec_point = get_isec_point(*strgt, touch_obj);
      rotate_coord(&isec_point, touch_obj->rotation);
      translate(&isec_point, touch_obj->origin);
      new_ray.dir = get_vec_from_points(isec_point, touch_obj->origin);
      new_ray.point = isec_point;
      if ((lim = bomb_ray(&new_ray, touch_obj->limit)) != NULL &&
	  new_ray.lambda < 1)
	{
	  strgt->point = new_ray.point;
	  return (NULL);
	}
    }
  return (touch_obj);
}

void	disp_color(t_system *sys, int x, int y)
{
  t_object	*final_obj;
  t_streight	strgt;

  init_streight(&strgt, sys->eye.distance, x, y);
  rotate_coord(&(strgt.dir), sys->eye.dir);
  strgt = get_streight(strgt.dir, sys->eye.pos);
  final_obj = bomb_ray(&strgt, sys->obj_list);
  if (final_obj != NULL)
    {
      if ((final_obj = resolve_limits(final_obj, &strgt)) == NULL)
	{
	  if ((final_obj = bomb_ray(&strgt, sys->obj_list)) != NULL)
	    {
	      if ((final_obj = resolve_limits(final_obj, &strgt)) == NULL)
	      	if ((final_obj = bomb_ray(&strgt, sys->obj_list)) == NULL)
	      	  {
		    my_put_pixel_to_img(x, y, sys->color, &sys->img);
		    return ;
		  }
	    }
	  else
	    {
	      my_put_pixel_to_img(x, y, sys->color, &sys->img);
	      return ;
	    }
	}
      resolve_light(get_isec_point(strgt, final_obj), final_obj, sys, strgt);
      //get_color(final_obj->obj_color, final_obj->disp_color, sys);
      my_put_pixel_to_img(x, y, final_obj->disp_color, &sys->img);
    }
  else
    {
      my_put_pixel_to_img(x, y, sys->color, &sys->img);
    }
}
