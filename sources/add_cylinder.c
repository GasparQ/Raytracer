/*
** add_cylinder.c for add a cylinder to obj list in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Feb 25 10:03:06 2015 quentin gasparotto
** Last update Wed Jun  3 16:32:04 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int		add_cylinder(t_object *act_obj, double *mesh_prop)
{
  t_cylinder	*obj_cylinder;

  act_obj->shape_resolver = &draw_cylinder;
  act_obj->free_mesh = &free_cylinder;
  if ((obj_cylinder = malloc(sizeof(*obj_cylinder))) == NULL)
    exit(my_strerror(MALLOC_ERR));
  act_obj->init = &init_cylinder_norm;
  obj_cylinder->radius = mesh_prop[0];
  act_obj->mesh.cylinder = obj_cylinder;
  act_obj->apply_texture = &text_to_cylinder;
  return (CLEAN);
}
