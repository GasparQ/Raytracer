/*
** add_tore.c for function to add a tore to object list in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sat Mar 21 17:44:24 2015 quentin gasparotto
** Last update Sat Mar 21 17:49:13 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int		add_tore(t_system *sys, double ex_r, double int_r, int color)
{
  t_tore	*obj_tore;

  sys->obj_list->shape_resolver = &draw_tore;
  sys->obj_list->free_mesh = &free_tore;
  if ((obj_tore = malloc(sizeof(*obj_tore))) == NULL)
      exit(my_strerror(MALLOC_ERR));
  sys->obj_list->init = &init_tore_norm;
  obj_tore->ex_r = ex_r;
  obj_tore->int_r = int_r;
  sys->obj_list->mesh.tore = obj_tore;
  sys->obj_list->obj_color = color;
  return (CLEAN);
}
