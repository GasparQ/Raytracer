/*
** bumpping.c for functions for the bump mapping in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Fri Jun  5 09:28:45 2015 quentin gasparotto
** Last update Fri Jun  5 09:51:46 2015 quentin gasparotto
*/

#include "prototypes.h"

void	height_map_bump(t_vector2 text_pos, t_image *bump, t_vector3 *norm)
{
  int	x_grad;
  int	y_grad;
  int	z_grad;
  int	more[4];

  more[0] = (text_pos.x - 1 >= 0) ? text_pos.x - 1 : text_pos.x;
  more[1] = (text_pos.x + 1 < bump->wdth / 4) ? text_pos.x + 1 : text_pos.x;
  more[2] = (text_pos.y - 1 >= 0) ? text_pos.y - 1 : text_pos.y;
  more[3] = (text_pos.y + 1 < bump->hght) ? text_pos.y + 1 : text_pos.y;
  x_grad = (get_bump_height(more[0], text_pos.y, bump) -
	    get_bump_height(more[1], text_pos.y, bump));
  y_grad = (get_bump_height(text_pos.x, more[2], bump) -
	    get_bump_height(text_pos.x, more[3], bump));
  z_grad = (get_bump_height(more[0], more[2], bump) -
	    get_bump_height(more[1], more[3], bump));
  *norm = unit_vec(*norm);
  norm->x = norm->x + text_pos.x * x_grad;
  norm->y = norm->y + text_pos.y * y_grad;
  norm->z = norm->z + z_grad;
}

void	bump_map_bump(t_vector2 text_pos, t_image *bump, t_vector3 *norm)
{
  get_pix_color((int)text_pos.x, (int)text_pos.y, *bump, bump->color);
  norm->x += bump->color[2];
  norm->y += bump->color[1];
  norm->z += bump->color[0];
}
