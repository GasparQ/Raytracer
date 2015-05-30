/*
** get_properties.c for get properties of the object in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sat Mar 14 13:09:31 2015 quentin gasparotto
** Last update Sat May 30 11:23:40 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

double		*get_properties(double brightness,
				double opacity, double reflect,
				double middle_ind)
{
  double	*properties_tab;

  if ((properties_tab = malloc(sizeof(double) * 4)) == NULL)
    exit(my_strerror(MALLOC_ERR));
  properties_tab[0] = brightness;
  properties_tab[1] = opacity;
  properties_tab[2] = reflect;
  properties_tab[3] = middle_ind;
  return (properties_tab);
}

void	add_phong(t_object *obj, double *phong_prop)
{
  obj->phong.brightness = phong_prop[0];
  obj->phong.diffuse = phong_prop[1];
  obj->phong.specular = phong_prop[2];
  obj->phong.spe_rad = phong_prop[3];
  obj->phong.opacity = phong_prop[4];
  obj->phong.middle_ind = phong_prop[5];
  obj->phong.reflect = phong_prop[6];
}

void	add_coord(t_object *obj, double *coord)
{
  obj->origin.x = coord[0];
  obj->origin.y = coord[1];
  obj->origin.z = coord[2];
  obj->rotation.x = coord[3];
  obj->rotation.y = coord[4];
  obj->rotation.z = coord[5];
}
