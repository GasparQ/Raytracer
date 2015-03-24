/*
** add_obj.c for add an obj to obj list in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Feb 25 10:03:48 2015 quentin gasparotto
** Last update Tue Mar 24 19:33:03 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void		add_object(t_system *sys, t_vector3 origin,
			   t_vector3 rotation, double *properties)
{
  t_object	new_obj;

  if ((new_obj.disp_color = malloc(sys->img.bpp / 8)) == NULL)
    exit(my_strerror(MALLOC_ERR));
  new_obj.origin.x = origin.x;
  new_obj.origin.y = origin.y;
  new_obj.origin.z = origin.z;
  new_obj.rotation.x = rotation.x;
  new_obj.rotation.y = rotation.y;
  new_obj.rotation.z = rotation.z;
  new_obj.brightness = properties[0];
  new_obj.opacity = properties[1];
  new_obj.reflect = properties[2];
  new_obj.middle_ind = properties[3];
  my_put_in_list(&sys->obj_list, new_obj);
  free(properties);
}
