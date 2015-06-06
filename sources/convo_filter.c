/*
** filter.c for function for applying a filter in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sat Jun  6 10:47:46 2015 quentin gasparotto
** Last update Sat Jun  6 19:13:34 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void	divide_it(t_image *img, int tell)
{
  int	i;

  i = 0;
  while (i < img->bpp / 8)
    {
      if (img->average[i] / tell > 0xFF)
	img->color[i] = 0xFF;
      else if (img->average[i] / tell < 0x00)
      	img->color[i] = 0x00;
      else
	img->color[i] = img->average[i] / tell;
      ++i;
    }
}

void		get_coeff(t_image *img, t_vector2 pos,
			  void *send_scene)
{
  int		i;
  int		tell;
  double	*matrix;
  t_scene	*scene;

  scene = (t_scene *)send_scene;
  matrix = scene->act_eye->convolution;
  pos.x -= 1;
  pos.y -= 1;
  tell = 0;
  i = 0;
  init_average(img->average, img->bpp / 8);
  while (i < 9)
    {
      if (pos.x + i % 3 >= 0 && pos.x + i % 3 < img->wdth / 4 &&
	  pos.y + i / 3 >= 0 && pos.y + i / 3 < img->hght)
	{
	  get_pix_color((int)pos.x + i % 3, (int)pos.y + i / 3, *
			img, img->color);
	  add_color_to_avg(img->color, img->average, img->bpp / 8,
			   (int)matrix[i]);
	  if (matrix[i] != 0)
	    ++tell;
	}
      ++i;
    }
  divide_it(img, tell);
}

void		apply_filter(t_image *img, t_scene *scene)
{
  t_image	new_img;
  t_vector2	pos;

  if (init_img(&new_img, get_vector2(WDW_WIDTH, WDW_HEIGHT), scene, 2) == -1)
    return ;
  pos.y = 0;
  while (pos.y < WDW_HEIGHT)
    {
      pos.x = 0;
      while (pos.x < WDW_WIDTH)
	{
	  scene->act_eye->filter_meth(img, pos, scene);
	  //get_coeff(img, pos, matrix);
	  //sepia(img, pos, (void *)scene);
	  my_put_pixel_to_img((int)pos.x, (int)pos.y, img->color, &new_img);
	  ++pos.x;
	}
      ++pos.y;
    }
  copy_img(new_img, img);
  free(new_img.color);
  free(new_img.average);
  free(new_img.i_tab);
}
