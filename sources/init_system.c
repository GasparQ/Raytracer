/*
** init_system.c for system initialisation in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Tue Feb 10 20:01:49 2015 quentin gasparotto
** Last update Sun Jun  7 21:43:43 2015 adrien milcent
*/

#include <pthread.h>
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

void		*output_preload(void *sys)
{
  int		i;
  t_system	*sys1;

  i = 0;
  sys1 = (t_system *)sys;
  while (42 && sys1 != NULL)
    {
      mlx_put_image_to_window(sys1->mlx, sys1->wdw,
			      sys1->load[i].img,
			      (WDW_WIDTH / 2) - 240, (WDW_HEIGHT / 2) - 240);
      ++i;
      usleep(50000);
      if (i == 11)
	{
	  i = 0;
	  mlx_clear_window(sys1->mlx, sys1->wdw);
	}
    }
  return (NULL);
}

int		init_system(t_system *sys, char *file)
{
  pthread_t	t1;

  if (init_mlx(sys) == ERROR)
    return (ERROR);
  if (get_load(sys->mlx, sys->load) == -1)
    return (-1);
  pthread_create(&t1, NULL, output_preload, (void *)sys);
  sys->scene_list = NULL;
  if (file == NULL)
    {
      if (basic_scene(sys) == -1)
	return (-1);
    }
  else if (get_objects(sys, file) != 0)
    return (-1);
  pthread_cancel(t1);
  mlx_clear_window(sys->mlx, sys->wdw);
  return (CLEAN);
}
