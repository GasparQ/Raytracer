/*
** draw_moebius.c for draw moebius rub in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Mar 24 10:28:19 2015 quentin gasparotto
** Last update Fri May 29 23:19:14 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

/* /\* void		init_moebius_param(double *param, t_streight strgt) *\/ */
/* /\* { *\/ */
/* /\*   double	dx_2; *\/ */
/* /\*   double	dy_2; *\/ */
/* /\*   double	dz_2; *\/ */
/* /\*   double	px_2; *\/ */
/* /\*   double	py_2; *\/ */
/* /\*   double	pz_2; *\/ */

/* /\*   dx_2 = pow(strgt.dir.x, 2); *\/ */
/* /\*   dy_2 = pow(strgt.dir.y, 2); *\/ */
/* /\*   dz_2 = pow(strgt.dir.z, 2); *\/ */

/* /\*   px_2 = pow(strgt.point.x, 2); *\/ */
/* /\*   py_2 = pow(strgt.point.y, 2); *\/ */
/* /\*   pz_2 = pow(strgt.point.z, 2); *\/ */

/* /\*   param[0] = (dx_2 * strgt.dir.y + *\/ */
/* /\* 	      dz_2 * strgt.dir.y + *\/ */
/* /\* 	      pow(strgt.dir.y, 3) *\/ */
/* /\* 	      - 2.0 * dx_2 * strgt.dir.z *\/ */
/* /\* 	      - 2.0 * dy_2 * strgt.dir.z); *\/ */

/* /\*   param[1] = (2.0 * strgt.point.x * strgt.dir.x * strgt.dir.y + *\/ */
/* s/\* 	      dx_2 * strgt.point.y + *\/ */
/* /\* 	      2.0 * strgt.point.z * strgt.dir.y * strgt.dir.z + *\/ */
/* /\* 	      dz_2 * strgt.point.y + *\/ */
/* /\* 	      2.0 * dy_2 * strgt.point.y + *\/ */
/* /\* 	      strgt.point.y * dy_2 *\/ */
/* /\* 	      - 2.0 * strgt.dir.x * strgt.dir.z *\/ */
/* /\* 	      - 2.0 * (dx_2 * strgt.point.z + 2.0 * strgt.dir.x * strgt.point.x * strgt.dir.z) *\/ */
/* /\* 	      - 2.0 * (strgt.dir.y * strgt.point.y * strgt.dir.z + dy_2 * strgt.point.z)); *\/ */

/* /\*   param[2] = (px_2 * strgt.dir.y + *\/ */
/* /\* 	      2.0 * strgt.point.x * strgt.dir.x * strgt.point.y + *\/ */
/* /\* 	      strgt.dir.y * pz_2 + *\/ */
/* /\* 	      2.0 * strgt.point.z * strgt.dir.z * strgt.point.y + *\/ */
/* /\* 	      strgt.dir.y * py_2 + *\/ */
/* /\* 	      2.0 * strgt.dir.y * py_2 *\/ */
/* /\* 	      - strgt.dir.y *\/ */
/* /\* 	      - 2.0 * (strgt.dir.z * strgt.point.x + strgt.dir.x * strgt.point.z) *\/ */
/* /\* 	      - 2.0 * (2.0 * strgt.dir.x * strgt.point.x * strgt.point.z + px_2 * strgt.dir.z) *\/ */
/* /\* 	      - 2.0 * (py_2 * strgt.dir.z + 2.0 * strgt.dir.y * strgt.point.y * strgt.point.z)); *\/ */

/* /\*   param[3] = (px_2 * strgt.point.y + *\/ */
/* /\* 	      pz_2 * strgt.point.y + *\/ */
/* /\* 	      pow(strgt.point.y, 3) *\/ */
/* /\* 	      - strgt.point.y *\/ */
/* /\* 	      - strgt.point.x * strgt.point.z * 2.0 *\/ */
/* /\* 	      - 2.0 * px_2 * strgt.point.z *\/ */
/* /\* 	      - 2.0 * py_2 * strgt.point.z); *\/ */
/* /\* } *\/ */

/* /\* double	param[4]; *\/ */
/* /\* double	roots[3]; *\/ */
/* /\* double	lambda; *\/ */

/* /\* invert_translate(&(strgt.point), my_obj->origin); *\/ */
/* /\* invert_rotate_coord(&(strgt.point), my_obj->rotation); *\/ */
/* /\* invert_rotate_coord(&(strgt.dir), my_obj->rotation); *\/ */
/* /\* lambda = ((-(my_obj->mesh.moebius->radius + *\/ */
/* /\* 	       my_obj->mesh.moebius->nb_tors * cos(my_obj->mesh.moebius->tors_angle)) * cos(2.0 * my_obj->mesh.moebius->tors_angle) + *\/ */
/* /\* 	     strgt.point.x + *\/ */
/* /\* 	     my_obj->mesh.moebius->nb_tors * sin(my_obj->mesh.moebius->tors_angle) *\/ */
/* /\* 	     - strgt.point.z) / (strgt.dir.z - strgt.dir.x)); *\/ */
/* /\* if (lambda < F_ZERO) *\/ */
/* /\*   return (-1.0); *\/ */
/* /\* return (lambda); *\/ */
/* /\* /\\* init_moebius_param(param, strgt); *\\/ *\/ */
/* /\* /\\* cubic_solver(param, roots); *\\/ *\/ */
/* /\* /\\* return (get_min(roots, 3)); *\\/ *\/ */

/* /\* x = x0 + k * vx *\/ */
/* /\* y = y0 + k * vy *\/ */
/* /\* z = z0 + k * vz *\/ */

/* /\* x0 + k * vx = (2 + t * cos(kv)) * cos(2v) *\/ */
/* /\* y0 + k * vy = (2 + t * cos(kv)) * sin(2v) *\/ */
/* /\* z0 + k * vz = t * sin(kv) *\/ */

/* /\* k = ((2 + t * cos(kv)) * cos(2v) - x0) / vx *\/ */
/* /\* k = ((2 + t * cos(kv)) * sin(2v) - z0) / vy *\/ */
/* /\* k = (t * sin(kv) - z0) / vz *\/ */

double		draw_moebius(t_streight strgt, t_object *my_obj)
{
  double	t;
  double	v;
  int		k;
  double	final;
  double	res[3];

  k = 0;
  final = -1.0;
  while (k <= 100)
    {
      v = (double)k * M_PI / 100.0;
      t = -1;
      while (t <= 1)
	{
	  res[0] = ((2 + t * cos(my_obj->mesh.moebius->nb_tors * v)) * cos(2 * v) - strgt.point.x) / strgt.dir.x;
	  res[1] = ((2 + t * cos(my_obj->mesh.moebius->nb_tors * v)) * sin(2 * v) - strgt.point.y) / strgt.dir.y;
	  res[2] = (t * sin(my_obj->mesh.moebius->nb_tors * v) - strgt.point.z) / strgt.dir.z;
	  if (res[0] == res[1] && res[0] == res[3] && (res[0] < final || final == -1.0))
	    final = res[0];
	  t += 0.02;
	}
      ++k;
    }
  return (final);
}
