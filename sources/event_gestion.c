/*
** expose_gestion.c for expose gestion in /home/gaspar_q/rendu/Igraph/MUL_2014_rtv1/sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Feb  3 17:19:37 2015 quentin gasparotto
** Last update Wed Jun  3 18:25:33 2015 quentin gasparotto
*/

#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

void	init_action(int *keycode_act, void (*act[5])(t_system *))
{
  keycode_act[0] = UP;
  keycode_act[1] = DOWN;
  keycode_act[2] = LEFT;
  keycode_act[3] = RIGHT;
  keycode_act[4] = ESCAPE;
  keycode_act[5] = 115;
  keycode_act[6] = RETURN;
  act[0] = &next_scene;
  act[1] = &prev_scene;
  act[2] = &next_img;
  act[3] = &prev_img;
  act[4] = &exit_ray_tracer;
  act[5] = &save_file;
  act[6] = &send_to_server;
}

int	key_gestion(int keycode, t_system *sys)
{
  int	keycode_action[7];
  void	(*act[7])(t_system *);
  int	i;

  init_action(keycode_action, act);
  i = 0;
  while (i < 7 && keycode_action[i] != keycode)
    ++i;
  if (i < 7)
    act[i](sys);
  if (i < 4)
    mlx_put_image_to_window(sys->mlx, sys->wdw,
			    sys->scene_list->act_image->img, 0, 0);
  return (CLEAN);
}

int	expose_gestion(t_system *sys)
{
  mlx_put_image_to_window(sys->mlx, sys->wdw,
			  sys->act_scene->act_image->img, 0, 0);
  return (CLEAN);
}
