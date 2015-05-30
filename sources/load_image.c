/*
** load_image.c for load the image in /home/gaspar_q/rendu/Igraph/MUL_2014_rtv1/sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Feb  3 16:42:37 2015 quentin gasparotto
** Last update Sat May 30 09:44:19 2015 quentin gasparotto
*/

#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

int	load_image(t_scene *scene, t_vector2 pos, t_vector2 dim)
{
  int	x;
  int	y;

  y = pos.y;
  while (y < WDW_HEIGHT && y < pos.y + dim.y)
    {
      x = pos.x;
      while (x < WDW_WIDTH && x < pos.x + dim.x)
	{
	  disp_color(scene, x, y);
	  x = x + 1;
	}
      y = y + 1;
      if (y % 200 == 0)
	printf("%d / %d\n", y, WDW_HEIGHT);
      /* if (y % 200 == 0) */
      /* 	mlx_put_image_to_window(sys->mlx, sys->wdw, scene->load.img, */
      /* 				WDW_WIDTH / 2 - 70 + 30 * (y / 200 - 1), */
      /* 				WDW_HEIGHT / 2 - 10); */
    }
  //mlx_put_image_to_window(sys->mlx, sys->wdw, sys->img.img, 0, 0);
  return (CLEAN);
}
