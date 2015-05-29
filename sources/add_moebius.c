/*
** add_moebius.c for add a moebius rub in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Mar 24 10:25:05 2015 quentin gasparotto
** Last update Fri May 29 23:19:24 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int		add_moebius(t_object *act_obj, double *mesh_prop)
{
  t_moebius	*moeb_obj;

  act_obj->shape_resolver = &draw_moebius;
  act_obj->free_mesh = &free_moebius;
  if ((moeb_obj = malloc(sizeof(*moeb_obj))) == NULL)
    exit(my_strerror(MALLOC_ERR));
  act_obj->init = &init_moebius_norm;
  moeb_obj->radius = mesh_prop[0];
  moeb_obj->nb_tors = mesh_prop[1];
  moeb_obj->tors_angle = mesh_prop[2];
  act_obj->mesh.moebius = moeb_obj;
  return (CLEAN);
}
