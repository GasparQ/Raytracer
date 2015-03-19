/*
** tore.c for tore resolution in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Thu Mar 19 19:30:35 2015 quentin gasparotto
** Last update Thu Mar 19 20:30:02 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void	init_tore_param(double *param, t_streight strgt, t_object *my_obj)
{
  double	sphr;
  double	ct;

  sphr = pow(strgt.dir.x, 2) + pow(strgt.dir.y, 2) + pow(strgt.dir.z, 2);
  ct = (pow(strgt.point.x, 2) +
	pow(strgt.point.y, 2) +
	pow(strgt.point.z, 2) +
	pow(my_obj->int_r) - pow(my_obj->ex_r));
  param[0] = pow(sphr, 2);
  param[1] = 4 * sphr * (strgt.point.x * strgt.dir.x +
			 strgt.point.y * strgt.dir.y +
			 strgt.point.z * strgt.point.z) / param[0];
  param[2] =
    (2 * sphr * ct - 4 * pow(my_obj->ex_r, 2) * (pow(strgt.dir.x, 2) +
						 pow(strgt.dir.z, 2))) /
    param[0];
  param[3] = ((4 * (strgt.dir.x * strgt.point.x +
		   strgt.dir.y * strgt.point.y +
		   strgt.dir.z * strgt.point.z) * cte -
	      (8 * pow(my_obj->ex_r, 2) *
	       (strgt.point.x * strgt.dir.x + strgt.dir.z * strgt.point.z))))
    / param[0];
  param[4] = cte - 4 * pow(my_obj->ex_r, 2) * (pow(strgt.point.x, 2) +
					       pow(strgt.point.z, 2))
    / param[0];
  param[0] = 1;
}

void	init_second_function(double *param, double *ex_param)
{
  param[0] = 1;
  param[1] = (3 * pow(ex_param[1], 2) / 8 - ex_param[2]) / 2;
  param[2] = (3 * pow(ex_param[1], 4) / 256 - pow(ex_param[1], 2) *
	      ex_param[2] / 16 + ex_param[1] * ex_param[3] / 16 +
	      ex_param[1] * ex_param[3] / 4 - ex_param[4]);
  param[3] = (param[1] * param[2] -
	      pow((pow(ex_param[1], 3) / 16 -
		   param[1] * param[2] / 4 + param[3] / 2), 2));
}

double		draw_tore(t_streight strgt, t_object *my_obj)
{
  double	param[5];
  double	param2[4];

  init_tore_param(param, strgt, my_obj);
  if (param[0] == 0)
    //résoud l'équation de dégré 3
  else
    {
      init_second_function(param2, param);
      //résoud l'équation de dégré 3
      if (/* des racine */)
	{
	  //on prend une racine à la wanne again et on se tape la bite contre le clavier
	  //s'il s'avère qu'un front se trouve dans la trajectoire de votre bite à se moment là
	  //considérez que vous vous tapez la bite contre un front
	  //on calc un delta
	  if (/* delta < 0 */)
	    {
	      //no root
	    }
	  else if (/* delta = 0 */)
	    {
	      //d'
	      if (/* d' < 0 */)
		{
		  //no root
		}
	      else
		//d'
	    }
	  else
	    {
	      //d'
	    }
	  //calc des racines
	}
    }
}
