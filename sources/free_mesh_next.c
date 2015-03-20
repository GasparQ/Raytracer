/*
** free_mesh_next.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer/sources
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Fri Mar 20 20:09:00 2015 fernand veyrier
** Last update Fri Mar 20 20:10:33 2015 fernand veyrier
*/

#include "../include/prototypes.h"

void		free_holed_cube(t_mesh obj_mesh)
{
  free(obj_mesh.holed_cube);
}
