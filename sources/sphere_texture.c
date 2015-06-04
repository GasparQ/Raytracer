/*
** sphere_texture.c for function for the gestion of sphere texture in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Jun  3 19:28:21 2015 quentin gasparotto
** Last update Thu Jun  4 22:48:58 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

t_vector2	sphere_map(t_vector3 isec_point, t_image *texture)
{
  t_vector2	text_pos;

  isec_point = unit_vec(isec_point);
  text_pos.x = atan2(isec_point.y, isec_point.x);
  if (text_pos.x < 0)
    text_pos.x += (2 * M_PI);
  text_pos.x /= (2 * M_PI);
  text_pos.y = acos(isec_point.z) / M_PI;
  text_pos.x *= texture->wdth / 4;
  text_pos.y *= texture->hght;
  return (text_pos);
}

double		get_bump_height(int x, int y, t_image *texture)
{
  double	height;
  int		i;

  get_pix_color(x, y, *texture, texture->color);
  height = 0;
  i = 0;
  while (i < texture->bpp / 8)
    {
      height += texture->color[i];
      ++i;
    }
  height /= (texture->bpp / 8);
  return (height);
}

void		sphere_bump(t_vector3 isec_point, t_object *touch,
			    t_vector3 *norm)
{
  t_vector2	text_pos;
  int		x_grad;
  int		y_grad;
  int		z_grad;
  int		more[4];

  text_pos = sphere_map(isec_point, touch->bump);
  more[0] = (text_pos.x - 1 > 0) ? text_pos.x - 1 : text_pos.x;
  more[1] = (text_pos.x + 1 < touch->bump->wdth / 4) ?
    text_pos.x + 1 : text_pos.x;
  more[2] = (text_pos.y - 1 > 0) ? text_pos.y - 1 : text_pos.y;
  more[3] = (text_pos.y + 1 < touch->bump->hght) ?
    text_pos.y + 1 : text_pos.y;
  x_grad = (get_bump_height(more[0], text_pos.y, touch->bump) -
	    get_bump_height(more[1], text_pos.y, touch->bump));
  y_grad = (get_bump_height(text_pos.x, more[2], touch->bump) -
	    get_bump_height(text_pos.x, more[3], touch->bump));
  z_grad = (get_bump_height(more[0], more[2], touch->bump) -
	    get_bump_height(more[1], more[3], touch->bump));
  norm->x = norm->x + text_pos.x * x_grad;
  norm->y = norm->y + text_pos.y * y_grad;
  norm->z = norm->z + z_grad;
}

void		sphere_proced(t_vector3 isec_point, t_object *touch)
{
  double	fnoise;
  double	t;
  double	n;
  double	ft;
  double	f;
  int		i;
  t_vector3	send;
  double	max_amp;
  double	amp;

  f = 0.00125;
  max_amp = 0;
  amp = 1;
  i = 0;
  fnoise = 0;
  while (i < 3)
    {
      send.x = isec_point.x * f;
      send.y = isec_point.y * f;
      send.z = isec_point.z * f;
      fnoise += noise(send) * amp;
      max_amp += amp;
      amp *= 0.5;
      f *= 2;
      ++i;
    }
  fnoise = fnoise * (1 - 0.5) / (1 - f);
  /* fnoise = 1 - sqrt(fabs(sin(10 * M_PI * fnoise))); */
  t = 20 * fnoise;
  n = t - (int)t;
  ft = n / M_PI;
  fnoise = (1 - cos(ft)) * 10;
  i = 0;
  while (i < touch->proced->bpp / 8)
    {
      if ((touch->color1[i] * (1 - fnoise) +
      	   touch->color2[i] * fnoise) > 255)
      	touch->disp_color[i] = 255;
      else if ((touch->color1[i] * (1 - fnoise) +
		touch->color2[i] * fnoise) < 0x00)
      	touch->disp_color[i] = 0x00;
      else
	touch->disp_color[i] = (touch->color1[i] * (1 - fnoise) +
				touch->color2[i] * fnoise);
      ++i;
    }
}
