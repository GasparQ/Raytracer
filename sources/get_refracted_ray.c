/*
** get_refracted_ray.c for get refracted ray in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Mar 24 19:23:00 2015 quentin gasparotto
** Last update Mon Jun  1 21:32:55 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

t_streight	get_refracted_ray(t_vector3 norm, t_vector3 incident_ray,
				  t_vector3 point, double coeff)
{
  t_streight	refracted_ray;
  double	scalaire;
  static int	i = 0;

  scalaire = get_scal(norm, incident_ray);
  if (scalaire < 0)
    scalaire = -scalaire;
  coeff = (i == 0 || coeff == 0) ? coeff : 1 / coeff;
  i = (i + 1) % 2;
  refracted_ray.dir.x =
    coeff * incident_ray.x +
    (coeff * scalaire - sqrt(1 + coeff * coeff *
			     (scalaire * scalaire - 1))) * norm.x;
  refracted_ray.dir.y =
    coeff * incident_ray.y +
    (coeff * scalaire - sqrt(1 + coeff * coeff *
			     (scalaire * scalaire - 1))) * norm.y;
  refracted_ray.dir.z =
    coeff * incident_ray.z +
    (coeff * scalaire - sqrt(1 + coeff * coeff *
			     (scalaire * scalaire - 1))) * norm.z;
  refracted_ray.point = point;
  return (refracted_ray);
}
