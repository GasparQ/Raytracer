/*
** rtv1.c for rtv1 main function in /home/gaspar_q/rendu/Igraph/MUL_2014_rtv1/sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Feb  3 16:31:47 2015 quentin gasparotto
** Last update Sat May 30 21:47:01 2015 quentin gasparotto
*/

#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

int		main(int ac, char **av, char **env)
{
  t_system	sys;

  (void)ac;
  (void)av;
  if (env[0] == NULL)
    return (my_strerror(ENV_FAIL));
  if (init_system(&sys) == -1)
    return (my_strerror("Init fail\n"));
  loading_time(&sys);
  sys.scene_list->act_image = sys.scene_list->img;
  mlx_hook(sys.wdw, KeyPress, KeyPressMask, &key_gestion, &sys);
  mlx_expose_hook(sys.wdw, &expose_gestion, &sys);
  mlx_loop(sys.mlx);
  return (CLEAN);
}