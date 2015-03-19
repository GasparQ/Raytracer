/*
** add_cone.c for add a cone to obj list in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Feb 25 10:51:50 2015 quentin gasparotto
** Last update Fri Mar 13 19:20:44 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int		add_cone(t_system *sys, double phi,
			 int color, t_vector3 limit[2])
{
  t_cone	*obj_cone;

  sys->obj_list->shape_resolver = &draw_cone;
  sys->obj_list->free_mesh = &free_cone;
  if ((obj_cone = malloc(sizeof(*obj_cone))) == NULL)
    exit(my_strerror(MALLOC_ERR));
  sys->obj_list->init = &init_cone_norm;
  obj_cone->phi = phi;
  obj_cone->limit[0] = limit[0];
  obj_cone->limit[1] = limit[1];
  sys->obj_list->obj_color = color;
  sys->obj_list->mesh.cone = obj_cone;
  return (CLEAN);
}
