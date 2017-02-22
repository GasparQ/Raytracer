/*
** add_plan.c for add plan to obj list in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Fri Feb 13 19:18:39 2015 quentin gasparotto
** Last update Thu Jun  4 20:08:02 2015 quentin gasparotto
*/

#include "prototypes.h"

int		add_plan(t_object *act_obj, double *mesh_prop)
{
  t_plan	*obj_plan;

  if ((obj_plan = malloc(sizeof(*obj_plan))) == NULL)
    exit(my_strerror(MALLOC_ERR));
  act_obj->init = &init_plan_norm;
  obj_plan->d = mesh_prop[0];
  obj_plan->norm.x = mesh_prop[1];
  obj_plan->norm.y = mesh_prop[2];
  obj_plan->norm.z = mesh_prop[3];
  act_obj->mesh.plan = obj_plan;
  act_obj->shape_resolver = &draw_plan;
  act_obj->free_mesh = &free_plan;
  act_obj->apply_texture = &text_to_plane;
  act_obj->apply_bump = &plane_bump;
  return (CLEAN);
}
