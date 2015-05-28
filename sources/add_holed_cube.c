/*
** cube_hole.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer/sources
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Fri Mar 20 18:52:54 2015 fernand veyrier
** Last update Thu May 28 16:32:46 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int		add_holed_cube(t_object *act_obj, double *mesh_prop)
{
  t_holed_cube	*obj_cube;

  act_obj->shape_resolver = &draw_holed_cube;
  act_obj->free_mesh = &free_holed_cube;
  if ((obj_cube = malloc(sizeof(*obj_cube))) == NULL)
    exit(my_strerror(MALLOC_ERR));
  act_obj->init = &init_holed_cube_norm;
  obj_cube->cote = mesh_prop[0];
  obj_cube->hole_prop = mesh_prop[1];
  act_obj->mesh.holed_cube = obj_cube;
  return (CLEAN);
}
