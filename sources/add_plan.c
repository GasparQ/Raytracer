/*
** add_plan.c for add plan to obj list in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Fri Feb 13 19:18:39 2015 quentin gasparotto
** Last update Fri Mar 13 19:20:00 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int		add_plan(t_system *sys, int color, double d, t_vector3 norm)
{
  t_plan	*obj_plan;

  if ((obj_plan = malloc(sizeof(*obj_plan))) == NULL)
    exit(my_strerror(MALLOC_ERR));
  sys->obj_list->init = &init_plan_norm;
  obj_plan->norm.x = norm.x;
  obj_plan->norm.y = norm.y;
  obj_plan->norm.z = norm.z;
  obj_plan->d = d;
  sys->obj_list->mesh.plan = obj_plan;
  sys->obj_list->obj_color = color;
  sys->obj_list->shape_resolver = &draw_plan;
  sys->obj_list->free_mesh = &free_plan;
  return (CLEAN);
}
