/*
** effects.c for function for the gestion of the effects in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Mon Jun  1 15:57:22 2015 quentin gasparotto
** Last update Fri Jun  5 20:39:41 2015 quentin gasparotto
*/

#include "prototypes.h"

void	init_average(int *average, int end)
{
  int	rank;

  rank = 0;
  while (rank < end)
    {
      average[rank] = 0;
      rank = rank + 1;
    }
}

void	resolve_cell_shading(t_image *act_image, t_image *nice_img,
			     t_vector2 pos)
{
  int	i;

  i = 0;
  while (i < 25)
    {
      if (pos.x - 2 + i % 5 >= 0 && pos.x - 2 + i % 5 < WDW_WIDTH &&
	  pos.y - 2 + i / 5 >= 0 && pos.y - 2 + i / 5 < WDW_HEIGHT)
	{
	  if (i != 13)
	    {
	      get_pix_color(pos.x - 2 + i % 5, pos.y - 2 + i / 5,
			    *act_image, act_image->color);
	      if (check_border(act_image, (int)pos.x, (int)pos.y) == 0)
		{
		  my_put_pixel_to_img((int)pos.x, (int)pos.y,
		  		      nice_img->color, nice_img);
		  return ;
		}
	    }
	}
      ++i;
    }
}
