/*
** free_mesh_next.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer/sources
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Fri Mar 20 20:09:00 2015 fernand veyrier
** Last update Sat Mar 21 17:49:59 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void		free_holed_cube(t_mesh obj_mesh)
{
  free(obj_mesh.holed_cube);
}

void	free_tore(t_mesh obj_mesh)
{
  free(obj_mesh.tore);
}
