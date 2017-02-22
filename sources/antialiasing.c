/*
** antialiasing.c for function for the antialiasing of the image in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Sat May 30 14:45:47 2015 quentin gasparotto
** Last update Sun Jun  7 22:52:28 2015 adrien milcent
*/

#include "prototypes.h"

int	cmp_colors(unsigned char *color1, unsigned char *color2,
		   int bpp, int limit)
{
  int	i;

  i = 0;
  while (i < bpp)
    {
      if (ABS(color1[i] - color2[i]) >= limit)
	return (1);
      ++i;
    }
  return (0);
}

void	add_color_to_avg(unsigned char *color, int *average,
			 int limit, int fact)
{
  int	i;

  i = 0;
  while (i < limit)
    {
      average[i] += color[i] * fact;
      ++i;
    }
}

void		choose_color(t_image *act_image, t_image *copy,
			     t_vector2 pos, int tell)
{
  int		i;

  i = 0;
  if (tell == 1)
    {
      while (i < act_image->bpp / 8)
	{
	  copy->dat[(int)pos.x * copy->bpp / 8 + (int)pos.y * copy->wdth + i] =
	    act_image->average[i] / 9;
	  ++i;
	}
    }
  else
    {
      while (i < act_image->bpp / 8)
	{
	  copy->dat[(int)pos.x * copy->bpp / 8 + (int)pos.y * copy->wdth + i] =
	    act_image->dat[(int)pos.x * act_image->bpp / 8 +
			   (int)pos.y * act_image->wdth + i];
	  ++i;
	}
    }
}

void	resolve_antialiased_color(t_image *act_image, t_image *nice_img,
				  t_vector2 pos)
{
  int	i;
  int	tell;

  tell = 0;
  i = 0;
  while (i < 9)
    {
      if (pos.x - 1 + i % 3 >= 0 && pos.x - 1 + i % 3 < WDW_WIDTH &&
	  pos.y - 1 + i / 3 >= 0 && pos.y - 1 + i / 3 < WDW_HEIGHT)
	{
	  get_pix_color(pos.x - 1 + i % 3, pos.y - 1 + i / 3,
			*act_image, act_image->color);
	  add_color_to_avg(act_image->color, act_image->average,
			   act_image->bpp / 8, 1);
	  if (i != 4 && check_border(act_image, (int)pos.x, (int)pos.y))
	    tell = 1;
	}
      ++i;
    }
  choose_color(act_image, nice_img, pos, tell);
}

int	        resolve_effects(t_image *act_image, t_scene *scene,
				void (*effect)(t_image *, t_image *, t_vector2))
{
  t_image       nice_img;
  t_vector2	pos;

  if (init_img(&nice_img, get_vector2(WDW_WIDTH, WDW_HEIGHT), scene, 0) == -1)
    return (-1);
  pos.y = 0;
  while (pos.y < WDW_HEIGHT)
    {
      pos.x = 0;
      while (pos.x < WDW_WIDTH)
	{
	  init_average(act_image->average, act_image->bpp / 8);
	  get_pix_color(pos.x, pos.y, *act_image, nice_img.color);
	  effect(act_image, &nice_img, pos);
	  ++pos.x;
	}
      ++pos.y;
    }
  copy_img(nice_img, act_image);
  free(nice_img.color);
  free(nice_img.average);
  return (0);
}
