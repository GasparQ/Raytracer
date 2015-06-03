/*
** get_vector3.c for get origin in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Feb 25 10:17:57 2015 quentin gasparotto
** Last update Wed Jun  3 16:16:09 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

t_vector3	get_positive_point(t_vector3 point)
{
  if (point.x < 0)
    point.x = -point.x;
  if (point.y < 0)
    point.y = -point.y;
  if (point.z < 0)
    point.z = -point.z;
  return (point);
}

t_vector3	get_vec_from_points(t_vector3 a_point, t_vector3 b_point)
{
  t_vector3	vec_ab;

  vec_ab.x = b_point.x - a_point.x;
  vec_ab.y = b_point.y - a_point.y;
  vec_ab.z = b_point.z - a_point.z;
  return (vec_ab);
}

t_vector3	get_vector3(double x, double y, double z)
{
  t_vector3	coord;

  coord.x = x;
  coord.y = y;
  coord.z = z;
  return (coord);
}

t_vector2	get_vector2(double x, double y)
{
  t_vector2	vec;

  vec.x = x;
  vec.y = y;
  return (vec);
}
