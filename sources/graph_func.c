/*
** init_graphs.c for init of all graphs in /home/gaspar_q/rendu/Igraph/MUL_2014_rtv1/sources
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Feb  3 16:44:51 2015 quentin gasparotto
** Last update Sat May 30 14:59:56 2015 quentin gasparotto
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

void	get_pix_color(int x, int y, t_image image, char *color)
{
  int	rank;
  int	i;

  rank = x * image.bpp + y * image.wdth;
  i = 0;
  while (i < image.bpp)
    {
      color[i] = image.dat[rank + i];
      ++i;
    }
}

void	get_color(int color, unsigned char *color_tab, t_scene *scene)
{
  int	i;

  color = mlx_get_color_value(scene->mlx, color);
  i = 0;
  if (scene->act_image->edn == 0)
    {
      while (i < scene->act_image->bpp / 8)
	{
	  color_tab[i] = (color >> (i * 8)) % 256;
	  i = i + 1;
	}
    }
  else
    {
      while (i < scene->act_image->bpp / 8)
	{
	  color_tab[scene->act_image->bpp / 8 - i] = (color >> (i * 8)) % 256;
	  i = i + 1;
	}
    }
}

