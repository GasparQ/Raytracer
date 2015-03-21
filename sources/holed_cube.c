/*
** holed_cube.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer/sources
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Fri Mar 20 19:18:52 2015 fernand veyrier
** Last update Sat Mar 21 18:48:10 2015 fernand veyrier
*/

#include "../include/prototypes.h"

void		init_holed_cube_param(double *param,
				      t_streight strgt,
				      t_object *my_obj)
{
  param[0] = pow(strgt.dir.x, 4) + pow(strgt.dir.y, 4) + pow(strgt.dir.z, 4);
  param[1] = 4 * (pow(strgt.dir.x, 3) * strgt.point.x
		  + pow(strgt.dir.y, 3) * strgt.point.y
		  + pow(strgt.dir.y, 3) * strgt.point.y);
  param[2] = 6 * (pow(strgt.dir.x, 2) * pow(strgt.point.x, 2)
		  + pow(strgt.dir.y, 2) * pow(strgt.point.y, 2)
		  + pow(strgt.dir.y, 2) * pow(strgt.point.y, 2))
    - 5 * (pow(strgt.dir.x, 2) + pow(strgt.dir.y, 2) + pow(strgt.dir.z, 2));
  param[3] = 4 * (pow(strgt.point.x, 3) * strgt.dir.x
		  + pow(strgt.point.y, 3) * strgt.dir.y
		  + pow(strgt.point.y, 3) * strgt.dir.y)
    - 10 * (strgt.dir.x * strgt.point.x
	    + strgt.dir.y * strgt.point.y
	    + strgt.dir.y * strgt.point.y);
  param[4] = pow(strgt.point.x , 4) + pow(strgt.point.y, 4)
    + pow(strgt.point.z, 4)
    - 5 * (pow(strgt.point.x, 2)
	   + pow(strgt.point.y, 2)
	   + pow(strgt.point.z, 2));
}

double		draw_holed_cube(t_streight strgt, t_object *my_obj)
{
  double	param[5];
  double	roots[4];
  int		size;

  init_holed_cube_param(param, strgt, my_obj);
  size = quadratic_solver(param, roots);
  return (get_min(roots, size));
}
