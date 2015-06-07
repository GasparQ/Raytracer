/*
** load_image.c for load the image in /home/gaspar_q/rendu/Igraph/MUL_2014_rtv1/sources
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Tue Feb  3 16:42:37 2015 quentin gasparotto
** Last update Sun Jun  7 15:26:15 2015 adrien milcent
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
      if ((y - (int)pos.y) % ((int)dim.y / 5) == 0)
	kill(getpid(), SIGUSR1);
    }
  return (CLEAN);
}
