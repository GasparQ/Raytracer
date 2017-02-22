/*
** filter.c for function for the basic filter in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sat Jun  6 15:21:59 2015 quentin gasparotto
** Last update Sun Jun  7 14:08:14 2015 quentin gasparotto
*/

#include "prototypes.h"

void			sepia(t_image *img, t_vector2 pos, void *send_scene)
{
  unsigned int		pix_color;
  unsigned int		red;
  unsigned int		green;
  unsigned int		blue;
  t_scene		*scene;

  scene = (t_scene *)send_scene;
  pix_color = get_color_value(img, (int)pos.x, (int)pos.y);
  pix_color -= (((pix_color >> 24) % 256) << 24);
  red = (pix_color >> 16) % 256;
  green = (pix_color >> 8) % 256;
  blue = pix_color % 256;
  pix_color = 0;
  pix_color += ((MIN(255, (unsigned int)(red * 0.393 +
					 green * 0.769 +
					 blue * 0.189))) << 16);
  pix_color += ((MIN(255, (unsigned int)(red * 0.349 +
					 green * 0.686 +
					 blue * 0.168))) << 8);
  pix_color += MIN(255, (unsigned int)(red * 0.272 +
				       green * 0.534 +
				       blue * 0.131));
  get_color(pix_color, img->color, scene);
}

void			black_n_white(t_image *img, t_vector2 pos, void *send_scene)
{
  unsigned int		pix_color;
  unsigned int		red;
  unsigned int		green;
  unsigned int		blue;
  unsigned int		i;
  t_scene		*scene;

  scene = (t_scene *)send_scene;
  pix_color = get_color_value(img, (int)pos.x, (int)pos.y);
  pix_color -= (((pix_color >> 24) % 256) << 24);
  red = (pix_color >> 16) % 256;
  green = (pix_color >> 8) % 256;
  blue = pix_color % 256;
  i = MIN(255, (unsigned int)((red + green + blue) / 3));
  pix_color = 0;
  pix_color += (i << 16);
  pix_color += (i << 8);
  pix_color += i;
  get_color(pix_color, img->color, scene);
}

void		        revert(t_image *img, t_vector2 pos, void *send_scene)
{
  unsigned int		pix_color;
  unsigned int		red;
  unsigned int		green;
  unsigned int		blue;
  t_scene		*scene;

  scene = (t_scene *)send_scene;
  pix_color = get_color_value(img, (int)pos.x, (int)pos.y);
  pix_color -= (((pix_color >> 24) % 256) << 24);
  red = (pix_color >> 16) % 256;
  green = (pix_color >> 8) % 256;
  blue = pix_color % 256;
  pix_color = 0;
  pix_color += ((255 - red) << 16);
  pix_color += ((255 - green) << 8);
  pix_color += 255 - blue;
  get_color(pix_color, img->color, scene);
}
