/*
** add_cone.c for add a cone to obj list in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Feb 25 10:51:50 2015 quentin gasparotto
** Last update Wed Jun  3 17:03:55 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int		add_cone(t_object *act_obj, double *mesh_prop)
{
  t_cone	*obj_cone;

  act_obj->shape_resolver = &draw_cone;
  act_obj->free_mesh = &free_cone;
  if ((obj_cone = malloc(sizeof(*obj_cone))) == NULL)
    exit(my_strerror(MALLOC_ERR));
  act_obj->init = &init_cone_norm;
  obj_cone->phi = mesh_prop[0];
  act_obj->mesh.cone = obj_cone;
  act_obj->apply_texture = &text_to_cone;
  return (CLEAN);
}
