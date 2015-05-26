/*
** add_obj.c for add an obj to obj list in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Feb 25 10:03:48 2015 quentin gasparotto
** Last update Tue May 26 22:23:43 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void		add_object(t_vector3 *physics, int *colors,
			   double *properties, t_object **obj_list)
{
  t_object	new_obj;

  if ((new_obj.disp_color = malloc(colors[0])) == NULL)
    exit(my_strerror(MALLOC_ERR));
  new_obj.obj_color = colors[1];
  new_obj.origin.x = physics[0].x;
  new_obj.origin.y = physics[0].y;
  new_obj.origin.z = physics[0].z;
  new_obj.rotation.x = physics[1].x;
  new_obj.rotation.y = physics[1].y;
  new_obj.rotation.z = physics[1].z;
  new_obj.brightness = properties[0];
  new_obj.opacity = properties[1];
  new_obj.reflect = properties[2];
  new_obj.middle_ind = properties[3];
  new_obj.limit = NULL;
  my_put_in_list(obj_list, new_obj);
  free(properties);
}
