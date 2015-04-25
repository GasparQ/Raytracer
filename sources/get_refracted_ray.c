/*
** get_refracted_ray.c for get refracted ray in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Mar 24 19:23:00 2015 quentin gasparotto
** Last update Tue Apr 21 10:28:37 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

t_streight	get_refracted_ray(t_vector3 norm, t_vector3 incident_ray,
				  t_vector3 point, double coeff)
{
  t_streight	refracted_ray;
  double	scalaire;
  double	value;

  //  printf("incident: %f, %f, %f )( normale: %f, %f, %f\t", incident_ray.x, incident_ray.y, incident_ray.z, norm.x, norm.y, norm.z);
  scalaire = get_scal(norm, incident_ray);
  value = ((coeff == 1) ? 0 : coeff * scalaire + sqrt(coeff * coeff * scalaire * scalaire + 1.0 - coeff * coeff));
  //  printf("%f - %f = %f, coeff: %f\n", (coeff * scalaire), sqrt(coeff * coeff * scalaire * scalaire + 1.0 - coeff * coeff), value, coeff);
  refracted_ray.dir.x =
    coeff * incident_ray.x + value * norm.x;
  refracted_ray.dir.y =
    coeff * incident_ray.y + value * norm.y;
  refracted_ray.dir.z =
    coeff * incident_ray.z + value * norm.z;
  refracted_ray.point = point;
  //  printf("refracted: %f, %f, %f\n", refracted_ray.dir.x, refracted_ray.dir.y, refracted_ray.dir.z);
  return (/* get_reflected_ray(norm, refracted_ray.dir, point) */refracted_ray);
}
