/*
** extract_point.c for extract point in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sat Mar 14 20:14:25 2015 quentin gasparotto
** Last update Sat Mar 14 20:15:49 2015 quentin gasparotto
*/

#include "prototypes.h"

t_vector3	extract_point(t_streight ray)
{
  t_vector3	point;

  point.x = ray.point.x + ray.lambda * ray.dir.x;
  point.y = ray.point.y + ray.lambda * ray.dir.y;
  point.z = ray.point.z + ray.lambda * ray.dir.z;
  return (point);
}
