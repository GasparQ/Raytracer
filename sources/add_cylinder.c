/*
** add_cylinder.c for add a cylinder to obj list in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Feb 25 10:03:06 2015 quentin gasparotto
** Last update Fri Mar 13 19:19:39 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int		add_cylinder(t_system *sys, double radius,
			     int color, t_vector3 limit[2])
{
  t_cylinder	*obj_cylinder;

  sys->obj_list->shape_resolver = &draw_cylinder;
  sys->obj_list->free_mesh = &free_cylinder;
  if ((obj_cylinder = malloc(sizeof(*obj_cylinder))) == NULL)
    exit(my_strerror(MALLOC_ERR));
  sys->obj_list->init = &init_cylinder_norm;
  obj_cylinder->radius = radius;
  obj_cylinder->limit[0] = limit[0];
  obj_cylinder->limit[1] = limit[1];
  sys->obj_list->mesh.cylinder = obj_cylinder;
  sys->obj_list->obj_color = color;
  return (CLEAN);
}
