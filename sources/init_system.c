/*
** init_system.c for system initialisation in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Tue Feb 10 20:01:49 2015 quentin gasparotto
** Last update Sun Jun  7 14:21:40 2015 quentin gasparotto
*/

#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

int	init_mlx(t_system *sys)
{
  if ((sys->mlx = mlx_init()) == NULL)
    return (my_strerror(MLX_FAIL));
  sys->wdw = mlx_new_window(sys->mlx, WDW_WIDTH, WDW_HEIGHT, "rtracer");
  if (sys->wdw == NULL)
    return (my_strerror(WDW_FAIL));
  return (CLEAN);
}

int	init_system(t_system *sys, char *file)
{
  if (init_mlx(sys) == ERROR)
    return (ERROR);
  sys->scene_list = NULL;
  if (file == NULL)
    {
      if (basic_scene(sys) == -1)
	return (-1);
    }
  else if (get_objects(sys, file) != 0)
    return (-1);
  return (CLEAN);
}
