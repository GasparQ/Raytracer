/*
** add_moebius.c for add a moebius rub in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Mar 24 10:25:05 2015 quentin gasparotto
** Last update Tue Mar 24 17:09:54 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

double	*moebius_prop(double *prop, double radius, double nb_tors, double tors_angle)
{
  prop[0] = radius;
  prop[1] = nb_tors;
  prop[2] = tors_angle;
  return (prop);
}

int		add_moebius(t_system *sys, double *prop, int color)
{
  t_moebius	*moeb_obj;

  sys->obj_list->shape_resolver = &draw_moebius;
  sys->obj_list->free_mesh = &free_moebius;
  if ((moeb_obj = malloc(sizeof(*moeb_obj))) == NULL)
    exit(my_strerror(MALLOC_ERR));
  sys->obj_list->init = &init_moebius_norm;
  moeb_obj->radius = prop[0];
  moeb_obj->nb_tors = prop[1];
  moeb_obj->tors_angle = prop[2];
  sys->obj_list->mesh.moebius = moeb_obj;
  sys->obj_list->obj_color = color;
  return (CLEAN);
}
