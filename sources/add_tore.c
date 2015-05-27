/*
** add_tore.c for function to add a tore to object list in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sat Mar 21 17:44:24 2015 quentin gasparotto
** Last update Wed May 27 10:24:28 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int		add_tore(t_object *act_obj, double *mesh_prop)
{
  t_tore	*obj_tore;

  act_obj->shape_resolver = &draw_tore;
  act_obj->free_mesh = &free_tore;
  if ((obj_tore = malloc(sizeof(*obj_tore))) == NULL)
      exit(my_strerror(MALLOC_ERR));
  act_obj->init = &init_tore_norm;
  obj_tore->ex_r = mesh_prop[0];
  obj_tore->int_r = mesh_prop[1];
  act_obj->mesh.tore = obj_tore;
  return (CLEAN);
}
