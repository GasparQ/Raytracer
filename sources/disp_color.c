/*
** disp_color.c for disp color in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1/sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Thu Mar 12 11:48:17 2015 quentin gasparotto
** Last update Sun May 31 18:15:14 2015 quentin gasparotto
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
      if ((lim = get_object(touch_obj->limit, &new_ray)) != NULL &&
	  new_ray.lambda < 1)
	{
	  strgt->point = new_ray.point;
	  return (NULL);
	}
    }
  return (touch_obj);
}

t_object	*get_object(t_object *obj_list, t_streight *strgt)
{
  t_object	*final_obj;
  t_streight	cpy;
  t_object	*tmp;
  t_object	*same;

  if ((final_obj = bomb_ray(strgt, obj_list)) == NULL)
    return (NULL);
  same = final_obj;
  while ((final_obj = resolve_limits(final_obj, strgt)) == NULL)
    {
      cpy = *strgt;
      if ((final_obj = bomb_ray(strgt, obj_list)) == NULL)
	return (NULL);
      if (same->limit != NULL &&
	  (tmp = get_object(same->limit, &cpy)) != NULL &&
	  cpy.lambda >= F_ZERO && cpy.lambda < strgt->lambda)
	{
	  strgt->lambda = cpy.lambda;
	  return (tmp);
	}
      same = final_obj;
    }
  return (final_obj);
}

void	        antialias_method(void *send_scene, t_vector2 pos,
				 t_streight strgt)
{
  int		i;
  t_object	*final_obj;
  t_scene	*scene;

  scene = (t_scene *)send_scene;
  init_average(scene->act_image->average, scene->act_image->bpp / 8);
  i = -1;
  while (++i < 9)
    {
      strgt.dir.y += (i % 3) * 0.25;
      strgt.dir.z += (i / 3) * 0.25;
      final_obj = get_object(scene->obj_list, &strgt);
      if (final_obj != NULL)
	{
	  final_obj->effects = 0;
	  resolve_light(get_isec_point(strgt, final_obj), final_obj, scene, strgt);
	  //get_color(final_obj->obj_color, final_obj->disp_color, scene);
	  add_color_to_avg(final_obj->disp_color, scene->act_image->average,
			   scene->act_image->bpp / 8);
	}
      else
	add_color_to_avg(scene->act_image->color, scene->act_image->average,
			 scene->act_image->bpp / 8);
    }
  choose_color(scene->act_image, scene->act_image, pos, 1);
}

void		basic_method(void *send_scene, t_vector2 pos, t_streight strgt)
{
  t_scene	*scene;
  t_object	*final_obj;

  scene = (t_scene *)send_scene;
  strgt.dir.y += 0.25;
  strgt.dir.z += 0.25;
  final_obj = get_object(scene->obj_list, &strgt);
  if (final_obj != NULL)
    {
      final_obj->effects = 0;
      resolve_light(get_isec_point(strgt, final_obj), final_obj, scene, strgt);
      my_put_pixel_to_img((int)pos.x, (int)pos.y,
			  final_obj->disp_color, scene->act_image);
    }
  else
    my_put_pixel_to_img((int)pos.x, (int)pos.y,
			scene->act_image->color, scene->act_image);
}

void	disp_color(t_scene *scene, int x, int y)
{
  t_streight	strgt;

  init_streight(&strgt, scene->act_eye->distance, x, y);
  rotate_coord(&(strgt.dir), scene->act_eye->dir);
  strgt = get_streight(strgt.dir, scene->act_eye->pos);
  strgt.dir.y -= 0.25;
  strgt.dir.z -= 0.25;
  scene->act_image->render_method(scene, get_vector2(x, y), strgt);
}
