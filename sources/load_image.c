/*
** load_image.c for load the image in /home/gaspar_q/rendu/Igraph/MUL_2014_rtv1/sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Feb  3 16:42:37 2015 quentin gasparotto
** Last update Sat Mar 21 17:31:38 2015 quentin gasparotto
*/

#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

int	load_image(t_system *sys)
{
  int	x;
  int	y;

  y = 0;
  while (y < WDW_HEIGHT)
    {
      x = 0;
      while (x < WDW_WIDTH)
	{
	  disp_color(sys, x, y);
	  x = x + 1;
	}
      y = y + 1;
      if (y % 200 == 0)
      	mlx_put_image_to_window(sys->mlx, sys->wdw, sys->load.img,
				WDW_WIDTH / 2 - 70 + 30 * (y / 200 - 1),
				WDW_HEIGHT / 2 - 10);
    }
  mlx_put_image_to_window(sys->mlx, sys->wdw, sys->img.img, 0, 0);
  return (CLEAN);
}
