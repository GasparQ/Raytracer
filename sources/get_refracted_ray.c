/*
** get_refracted_ray.c for get refracted ray in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Mar 24 19:23:00 2015 quentin gasparotto
** Last update Thu May 28 12:48:47 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

t_streight	get_refracted_ray(t_vector3 norm, t_vector3 incident_ray,
				  t_vector3 point, double coeff)
{
  t_streight	refracted_ray;
  double	scalaire;
  double	value;

  scalaire = get_scal(norm, incident_ray);
  value = ((coeff == 1) ? 0 :
	   coeff * scalaire + sqrt(coeff * coeff * scalaire * scalaire +
				   1.0 - coeff * coeff));
  refracted_ray.dir.x =
    coeff * incident_ray.x + value * norm.x;
  refracted_ray.dir.y =
    coeff * incident_ray.y + value * norm.y;
  refracted_ray.dir.z =
    coeff * incident_ray.z + value * norm.z;
  refracted_ray.point = point;
  return (refracted_ray);
}
