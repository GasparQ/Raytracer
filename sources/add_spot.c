/*
** add_spot.c for add a spot in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Mon Feb 16 17:33:47 2015 quentin gasparotto
** Last update Fri Mar 13 19:20:22 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int		add_spot(t_system *sys, t_vector3 pos, int color)
{
  t_spot	*new_spot;

  if ((new_spot = malloc(sizeof(*new_spot))) == NULL)
    exit(my_strerror(MALLOC_ERR));
  if ((new_spot->color = malloc(sys->img.bpp / 8)) == NULL)
    exit(my_strerror(MALLOC_ERR));
  get_color(color, new_spot->color, sys);
  new_spot->origin.x = pos.x;
  new_spot->origin.y = pos.y;
  new_spot->origin.z = pos.z;
  new_spot->next = sys->spot_list;
  sys->spot_list = new_spot;
  return (CLEAN);
}
