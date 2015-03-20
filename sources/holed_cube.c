/*
** cube_hole.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer/sources
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Fri Mar 20 18:52:54 2015 fernand veyrier
** Last update Fri Mar 20 19:06:49 2015 fernand veyrier
*/

#include "../include/prototypes.h"

int		add_holed_cube(t_system *sys, double size, int color)
{
  t_holed_cube	*obj_cube;

  sys->obj_list->shape_resolver = draw_holed_cube;
  sys->obj_list->free_mesh = free_holed_cube;
  if ((obj_cube = malloc(sizeof(*obj_cube))) == NULL)
    exit(my_strerror(MALLOC_ERR));
  sys->obj_list->init = init_holed_cube;
  obj_cube->cote = size;
  sys->obj_list->mesh.holed_cube = obj_cube;
  sys->obj_list->obj_color = color;
  return (CLEAN);
}
