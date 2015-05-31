/*
** get_object.c for function for get an object from ray in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sun May 31 20:18:46 2015 quentin gasparotto
** Last update Sun May 31 20:19:21 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

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
