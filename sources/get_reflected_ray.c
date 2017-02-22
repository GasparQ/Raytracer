/*
** get_reflected_ray.c for get reflected ray in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sat Mar 14 13:48:28 2015 quentin gasparotto
** Last update Thu May 28 12:49:12 2015 quentin gasparotto
*/

#include "prototypes.h"

t_streight	get_reflected_ray(t_vector3 norm, t_vector3 incident_ray,
				  t_vector3 point)
{
  t_streight	reflected_ray;
  double	scalaire;

  scalaire = get_scal(norm, incident_ray);
  reflected_ray.dir.x =
    -2.0 * norm.x * scalaire + incident_ray.x;
  reflected_ray.dir.y =
    -2.0 * norm.y * scalaire + incident_ray.y;
  reflected_ray.dir.z =
    -2.0 * norm.z * scalaire + incident_ray.z;
  reflected_ray.point = point;
  return (reflected_ray);
}
