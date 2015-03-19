/*
** expose_gestion.c for expose gestion in /home/gaspar_q/rendu/Igraph/MUL_2014_rtv1/sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Feb  3 17:19:37 2015 quentin gasparotto
** Last update Fri Mar 13 15:55:54 2015 quentin gasparotto
*/

#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

int	key_gestion(int keycode, t_system *sys)
{
  if (keycode == ESCAPE)
    {
      free_my_list(sys->obj_list);
      free_spot_list(sys->spot_list);
      free(sys->color);
      free(sys->average);
      exit(3);
    }
  return (CLEAN);
}

int	expose_gestion(t_system *sys)
{
  mlx_put_image_to_window(sys->mlx, sys->wdw, sys->img.img, 0, 0);
  return (CLEAN);
}
