/*
** init_graphs.c for init of all graphs in /home/gaspar_q/rendu/Igraph/MUL_2014_rtv1/sources
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Feb  3 16:44:51 2015 quentin gasparotto
** Last update Wed Mar 11 12:13:52 2015 quentin gasparotto
*/

#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

void	my_put_pixel_to_img(int x, int y, unsigned char *color, t_image *img)
{
  int	i;

  i = 0;
  while (i < img->bpp / 8)
    {
      img->dat[x * img->bpp / 8 + y * img->wdth + i] = color[i];
      i = i + 1;
    }
}

void	get_color(int color, unsigned char *color_tab, t_system *sys)
{
  int	i;

  color = mlx_get_color_value(sys->mlx, color);
  i = 0;
  if (sys->img.edn == 0)
    {
      while (i < sys->img.bpp / 8)
	{
	  color_tab[i] = (color >> (i * 8)) % 256;
	  i = i + 1;
	}
    }
  else
    {
      while (i < sys->img.bpp / 8)
	{
	  color_tab[sys->img.bpp / 8 - i] = (color >> (i * 8)) % 256;
	  i = i + 1;
	}
    }
}

