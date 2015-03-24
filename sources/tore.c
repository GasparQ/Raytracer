/*
** tore.c for tore resolution in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Thu Mar 19 19:30:35 2015 quentin gasparotto
** Last update Tue Mar 24 10:43:37 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void	init_tore_param(double *param, t_streight strgt, t_object *my_obj)
{
  double	px_2;
  double	py_2;
  double	pz_2;
  double	dx_2;
  double	dy_2;
  double	dz_2;
  double	Raye_2;
  double	ray_2;

  dx_2 = pow(strgt.dir.x, 2);
  dy_2 = pow(strgt.dir.y, 2);
  dz_2 = pow(strgt.dir.z, 2);

  px_2 = pow(strgt.point.x, 2);
  py_2 = pow(strgt.point.y, 2);
  pz_2 = pow(strgt.point.z, 2);

  Raye_2 = pow(my_obj->mesh.tore->int_r, 2);
  ray_2 = pow(my_obj->mesh.tore->ex_r, 2);

  param[0] = pow(dx_2 + dy_2 + dz_2, 2);

  param[1] = 4.0 * (dx_2 + dy_2 + dz_2) * (strgt.point.x * strgt.dir.x +
					   strgt.point.y * strgt.dir.y +
					   strgt.point.z * strgt.dir.z);

  param[2] = (2.0 * (dx_2 + dy_2 + dz_2) * (px_2 + py_2 + pz_2 + Raye_2 - ray_2) +
	      4.0 * pow((strgt.dir.x * strgt.point.x + strgt.dir.y * strgt.point.y + strgt.dir.z * strgt.point.z), 2) - 4.0 * Raye_2 * (dx_2 + dy_2));

  param[3] = (4.0 * (strgt.dir.x * strgt.point.x + strgt.dir.y * strgt.point.y + strgt.dir.z * strgt.point.z) * (px_2 + py_2 + pz_2 + Raye_2 - ray_2)
	      - 8.0 * Raye_2 * (strgt.point.x * strgt.dir.x + strgt.point.y * strgt.dir.y));

  param[4] = (pow(px_2 + py_2 + pz_2 + Raye_2 - ray_2, 2) - 4.0 * Raye_2 *
	      (px_2 + py_2));
  
  /* param[2] = (2.0 * (dx_2 + dy_2 + dz_2) * (px_2 + py_2 + pz_2 + Raye_2 - ray_2) + */
  /* 	      pow((strgt.point.x * strgt.dir.x + */
  /* 		   strgt.point.y * strgt.dir.y + */
  /* 		   strgt.point.z * strgt.dir.z), 2) - */
  /* 	      4.0 * Raye_2 * (dx_2 + dy_2)); */
  /* param[3] = (4.0 * (strgt.dir.x * strgt.point.x + */
  /* 		     strgt.dir.y * strgt.point.y + */
  /* 		     strgt.dir.z * strgt.point.z) * (px_2 + py_2 + pz_2 + Raye_2 - ray_2) - */
  /* 	      (8.0 * Raye_2 * (strgt.point.x * strgt.dir.x + strgt.dir.y * strgt.point.y))); */

}

/* a = (d0² + d1² + d2²)² */

/*   b = 4 (d0² + d1² + d2²)(d0 p0 + d1 p1 + d2 p2) */

/*   c = 2 (d0² + d1² + d2²)(p0² + p1² + p2² + R² - r²) + (d0 p0 + d1 p1 + d2 p2)² - 4 R² (d0² + d2²) */

/*   d = 4 (d0 p0 + d1 p1 + d2 p2) (p0² + p1² + p2² + R² - r²) - 8 R² (d0 p0 + d2 p2) */

/*   e = (p0² + p1² + p2² + R² - r²)² - 4 R² (p0² + p2²) */


double		draw_tore(t_streight strgt, t_object *my_obj)
{
  double	param[5];
  double	roots[4];
  int		size;

  //  printf("%f %f\n", my_obj->mesh.tore->int_r, my_obj->mesh.tore->ex_r);
  invert_translate(&(strgt.point), my_obj->origin);
  invert_rotate_coord(&(strgt.point), my_obj->rotation);
  invert_rotate_coord(&(strgt.dir), my_obj->rotation);
  init_tore_param(param, strgt, my_obj);
  size = quadratic_solver(param, roots);
  return (get_min(roots, size));
}
