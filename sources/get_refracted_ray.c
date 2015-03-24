/*
** get_refracted_ray.c for get refracted ray in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Mar 24 19:23:00 2015 quentin gasparotto
** Last update Tue Mar 24 19:53:21 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

t_streight	get_refracted_ray(t_vector3 norm, t_vector3 incident_ray,
				  t_vector3 point, double coeff)
{
  t_streight	refracted_ray;
  double	scalaire;

  scalaire = get_scal(norm, incident_ray);
  refracted_ray.dir.x =
    (coeff * incident_ray.x +
     (coeff * scalaire -
      sqrt(1.0 + coeff * coeff * (pow(scalaire, 2) - 1.0))) * norm.x);
  refracted_ray.dir.y =
    (coeff * incident_ray.y +
     (coeff * scalaire -
      sqrt(1.0 + coeff * coeff * (pow(scalaire, 2) - 1.0))) * norm.y);
  refracted_ray.dir.z =
    (coeff * incident_ray.z +
     (coeff * scalaire -
      sqrt(1.0 + coeff * coeff * (pow(scalaire, 2) - 1.0))) * norm.z);
  refracted_ray.point = point;
  return (refracted_ray);
}
