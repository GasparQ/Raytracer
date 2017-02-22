/*
** loading_screen.c for loading screen in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Thu Mar  5 18:33:26 2015 quentin gasparotto
** Last update Fri May 29 16:54:15 2015 quentin gasparotto
*/

#include "prototypes.h"

void	init_load_img(t_scene *scene, t_image *load_img)
{
  int	x;
  int	y;

  get_color(RED, scene->act_image->color, scene);
  y = 0;
  while (y < load_img->hght)
    {
      x = 0;
      while (x < load_img->wdth)
	{
	  my_put_pixel_to_img(x, y, scene->act_image->color, load_img);
	  x = x + 1;
	}
      y = y + 1;
    }
}
