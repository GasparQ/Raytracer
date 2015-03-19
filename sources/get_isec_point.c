/*
** get_isec_point.c for get isec point in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Mar 10 11:18:48 2015 quentin gasparotto
** Last update Fri Mar 13 14:32:06 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

t_vector3	get_isec_point(t_streight streight, t_object *my_obj)
{
  t_vector3	isec_point;

  invert_translate(&(streight.point), my_obj->origin);
  invert_rotate_coord(&(streight.point), my_obj->rotation);
  invert_rotate_coord(&(streight.dir), my_obj->rotation);
  isec_point.x = (streight.point.x +
		  streight.lambda * streight.dir.x);
  isec_point.y = (streight.point.y +
		  streight.lambda * streight.dir.y);
  isec_point.z = (streight.point.z +
		  streight.lambda * streight.dir.z);
  return (isec_point);
}
