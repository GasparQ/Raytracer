/*
** add_hyperboloid.c for function for add and hyperboloid to obj list in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed May 27 11:45:18 2015 quentin gasparotto
** Last update Thu Jun  4 20:10:19 2015 quentin gasparotto
*/

#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

int		add_hyperboloid(t_object *act_obj, double *mesh_prop)
{
  t_hyperboloid	*obj_hyper;

  act_obj->shape_resolver = &draw_hyperboloid;
  act_obj->free_mesh = &free_hyperboloid;
  if ((obj_hyper = malloc(sizeof(*obj_hyper))) == NULL)
    exit(my_strerror(MALLOC_ERR));
  act_obj->init = &init_hyper_norm;
  obj_hyper->a = mesh_prop[0];
  obj_hyper->b = mesh_prop[1];
  obj_hyper->c = mesh_prop[2];
  obj_hyper->d = mesh_prop[3];
  obj_hyper->c_factor = mesh_prop[4];
  act_obj->mesh.hyperboloid = obj_hyper;
  return (CLEAN);
}
