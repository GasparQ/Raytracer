/*
** expose_gestion.c for expose gestion in /home/gaspar_q/rendu/Igraph/MUL_2014_rtv1/sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Feb  3 17:19:37 2015 quentin gasparotto
** Last update Fri May 29 17:22:06 2015 quentin gasparotto
*/

#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

int	key_gestion(int keycode, t_system *sys)
{
  if (keycode == ESCAPE)
    {
      free_scene(sys->scene_list);
      exit(3);
    }
  return (CLEAN);
}

int	expose_gestion(t_system *sys)
{
  mlx_put_image_to_window(sys->mlx, sys->wdw,
			  sys->scene_list->act_image->img, 0, 0);
  return (CLEAN);
}
