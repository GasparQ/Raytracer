/*
** add_paraboloid.c for add a paraboloid in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Mar 11 17:24:16 2015 quentin gasparotto
** Last update Fri Mar 13 19:19:53 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int		add_paraboloid(t_system *sys, double cte, int color)
{
  t_paraboloid	*obj_para;

  sys->obj_list->shape_resolver = &draw_paraboloid;
  sys->obj_list->free_mesh = &free_paraboloid;
  if ((obj_para = malloc(sizeof(*obj_para))) == NULL)
    exit(my_strerror(MALLOC_ERR));
  sys->obj_list->init = &init_paraboloid_norm;
  obj_para->cte = cte;
  sys->obj_list->mesh.paraboloid = obj_para;
  sys->obj_list->obj_color = color;
  return (CLEAN);
}
