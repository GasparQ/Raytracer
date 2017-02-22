/*
** sphere_texture.c for function for the gestion of sphere texture in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Jun  3 19:28:21 2015 quentin gasparotto
** Last update Sun Jun  7 17:50:19 2015 quentin gasparotto
*/

#include "prototypes.h"

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

  text_pos = sphere_map(isec_point, touch->bump);
  touch->which_bump(text_pos, touch->bump, norm);
}

double		smooth_noise(t_vector3 isec_point)
{
  double	fnoise;
  double	max_amp;
  double	amp;
  double	f;
  int		i;
  t_vector3	send;

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
  return (fnoise * (1 - 0.5) / (1 - f));
}

void		sphere_proced(t_vector3 isec_point, t_object *touch)
{
  double	n;
  double	ft;
  double	fnoise;
  int		i;
  t_vector2	map;

  map = sphere_map(isec_point, touch->proced);
  fnoise = noise2(map);
  n = (20 * fnoise) - (int)(20 * fnoise);
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
