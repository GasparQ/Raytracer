/*
** disp_color.c for disp color in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1/sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Thu Mar 12 11:48:17 2015 quentin gasparotto
** Last update Sat Mar 21 17:35:53 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void	init_streight(t_streight *strgt, double dist, int x, int y)
{
  strgt->dir.x = dist;
  strgt->dir.y = WDW_WIDTH / 2.0 - (double)x;
  strgt->dir.z = WDW_HEIGHT / 2.0 - (double)y;
}

void	disp_color(t_system *sys, int x, int y)
{
  t_object	*final_obj;
  t_streight	strgt;

  init_streight(&strgt, sys->eye.distance, x, y);
  rotate_coord(&(strgt.dir), sys->eye.dir);
  strgt = get_streight(strgt.dir, sys->eye.pos);
  final_obj = bomb_ray(&strgt, sys->obj_list);
  if (final_obj != NULL)
    {
      //resolve_light(get_isec_point(strgt, final_obj), final_obj, sys, strgt);
      get_color(final_obj->obj_color, final_obj->disp_color, sys);
      my_put_pixel_to_img(x, y, final_obj->disp_color, &sys->img);
    }
  else
    {
      my_put_pixel_to_img(x, y, sys->color, &sys->img);
    }
}
