/*
** bomb_ray.c for bombard a ray from x and y in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Fri Feb 13 19:41:05 2015 quentin gasparotto
** Last update Wed May 27 10:12:36 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

t_object	*bomb_ray(t_streight *ray, t_object *obj_list)
{
  t_object	*final_obj;
  t_object	*tmp;
  double	k;

  final_obj = NULL;
  ray->lambda = -1.0;
  tmp = obj_list;
  while (tmp != NULL)
    {
      k = tmp->shape_resolver(*ray, tmp);
      if (k >= F_ZERO && (k < ray->lambda || ray->lambda == -1.0))
	{
	  ray->lambda = k;
	  final_obj = tmp;
	}
      tmp = tmp->next;
    }
  return (final_obj);
}
