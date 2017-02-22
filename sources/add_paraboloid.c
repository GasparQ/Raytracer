/*
** add_paraboloid.c for add a paraboloid in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Mar 11 17:24:16 2015 quentin gasparotto
** Last update Thu Jun  4 20:10:35 2015 quentin gasparotto
*/

#include "prototypes.h"

int		add_paraboloid(t_object *act_obj, double *mesh_param)
{
  t_paraboloid	*obj_para;

  act_obj->shape_resolver = &draw_paraboloid;
  act_obj->free_mesh = &free_paraboloid;
  if ((obj_para = malloc(sizeof(*obj_para))) == NULL)
    exit(my_strerror(MALLOC_ERR));
  act_obj->init = &init_paraboloid_norm;
  obj_para->cte = mesh_param[0];
  act_obj->mesh.paraboloid = obj_para;
  return (CLEAN);
}
