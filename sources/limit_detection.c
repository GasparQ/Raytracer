/*
** limit_detection.c for function for the limit detection in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Fri Jun  5 17:18:55 2015 quentin gasparotto
** Last update Sun Jun  7 14:24:33 2015 quentin gasparotto
*/

#include "prototypes.h"

unsigned int	get_color_value(t_image *img, int x, int y)
{
  unsigned int	color;
  int		rank;
  int		i;
  int		val_pow;

  color = 0;
  rank = y * img->wdth + x * img->bpp / 8;
  i = 0;
  while (i < img->bpp / 8)
    {
      val_pow = (img->edn == 0) ? i : img->bpp / 8 - i;
      color += img->dat[rank + i] * pow(2, 8 * val_pow);
      ++i;
    }
  return (color);
}

double		get_gradient(t_scene *scene, int x, int y)
{
  double	grad_x;
  double	grad_y;
  int		more[4];

  more[0] = (x + 1 < scene->act_image->wdth / 4) ? x + 1 : x;
  more[1] = (x - 1 >= 0) ? x - 1 : x;
  more[2] = (y + 1 < scene->act_image->hght) ? y + 1 : y;
  more[3] = (y - 1 >= 0) ? y - 1 : y;
  grad_x =
    (scene->act_image->i_tab[more[3] * scene->act_image->wdth / 4 + more[0]] -
     scene->act_image->i_tab[more[3] * scene->act_image->wdth / 4 + more[1]] +
     2 * (scene->act_image->i_tab[y * scene->act_image->wdth / 4 + more[0]] -
	  scene->act_image->i_tab[y * scene->act_image->wdth / 4 + more[1]]) +
     scene->act_image->i_tab[more[2] * scene->act_image->wdth / 4 + more[0]] -
     scene->act_image->i_tab[more[2] *
			     scene->act_image->wdth / 4 + more[1]]) / 3;
  grad_y =
    (scene->act_image->i_tab[more[3] * scene->act_image->wdth / 4 + more[0]] -
     scene->act_image->i_tab[more[2] * scene->act_image->wdth / 4 + more[0]] +
     2 * (scene->act_image->i_tab[more[3] * scene->act_image->wdth / 4 + x] -
	  scene->act_image->i_tab[more[2] * scene->act_image->wdth / 4 + x]) +
     scene->act_image->i_tab[more[3] * scene->act_image->wdth / 4 + more[1]] -
     scene->act_image->i_tab[more[2] *
			     scene->act_image->wdth / 4 + more[1]]) / 3;
  return (grad_y + grad_x);
}

int		check_border(t_image *image, int x, int y)
{
  int		i;
  double	ref;

  ref = image->i_tab[y * image->wdth / 4 + x];
  x -= 1;
  y -= 1;
  i = 0;
  while (i < 9)
    {
      if (x + i % 3 < image->wdth / 4 && x + i % 3 >= 0 &&
	  y + i / 3 < image->hght && y + i / 3 >= 0 &&
	  fabs(image->i_tab[(y + i / 3) * image->wdth / 4 + x + i % 3]
	       - ref) > 0.15)
	return (1);
      ++i;
    }
  return (0);
}

int	get_border(t_scene *scene)
{
  int	x;
  int	y;

  y = 0;
  while (y < scene->act_image->hght)
    {
      x = 0;
      while (x < scene->act_image->wdth / 4)
	++x;
      ++y;
    }
  return (0);
}
