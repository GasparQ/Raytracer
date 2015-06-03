/*
** add_sphere.c for add sphere to obj list in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Fri Feb 13 19:13:11 2015 quentin gasparotto
** Last update Wed Jun  3 11:26:32 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int		add_sphere(t_object *act_obj, double *mesh_prop)
{
  t_sphere	*obj_sphere;

  act_obj->shape_resolver = &draw_sphere;
  act_obj->free_mesh = &free_sphere;
  if ((obj_sphere = malloc(sizeof(*obj_sphere))) == NULL)
    exit(my_strerror(MALLOC_ERR));
  act_obj->init = &init_sphere_norm;
  obj_sphere->radius = *mesh_prop;
  act_obj->mesh.sphere = obj_sphere;
  act_obj->apply_texture = &text_to_sphere;
  return (CLEAN);
}
