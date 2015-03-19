/*
** add_sphere.c for add sphere to obj list in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Fri Feb 13 19:13:11 2015 quentin gasparotto
** Last update Fri Mar 13 19:19:28 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int		add_sphere(t_system *sys, double rad, int color)
{
  t_sphere	*obj_sphere;

  sys->obj_list->shape_resolver = &draw_sphere;
  sys->obj_list->free_mesh = &free_sphere;
  if ((obj_sphere = malloc(sizeof(*obj_sphere))) == NULL)
    exit(my_strerror(MALLOC_ERR));
  sys->obj_list->init = &init_sphere_norm;
  obj_sphere->radius = rad;
  sys->obj_list->mesh.sphere = obj_sphere;
  sys->obj_list->obj_color = color;
  return (CLEAN);
}
