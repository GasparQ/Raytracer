/*
** average.c for average in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Fri Mar  6 16:47:34 2015 quentin gasparotto
** Last update Fri May 29 16:23:18 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void	init_average(int *average, int end)
{
  int	rank;

  rank = 0;
  while (rank < end)
    {
      average[rank] = 0;
      rank = rank + 1;
    }
}

void	add_average(t_scene *scene, t_spot *tmp,
		    double cos_a, t_object *act_obj)
{
  int	rank;

  rank = 0;
  while (rank < scene->act_image->bpp / 8)
    {
      resolve_brightness(act_obj, tmp, rank);
      act_obj->disp_color[rank] = cos_a * act_obj->disp_color[rank];
      scene->act_image->average[rank] = scene->act_image->average[rank] +
	act_obj->disp_color[rank];
      rank = rank + 1;
    }
}

void	average_to_color(int *average, unsigned char *color, int nb, int end)
{
  int	rank;

  if (nb > 1)
    {
      rank = 0;
      while (rank < end)
	{
	  if (average[rank] / (nb - 1) > 255)
	    color[rank] = 255;
	  else
	    color[rank] = (unsigned char)(average[rank] / (nb - 1));
	  rank = rank + 1;
	}
    }
}
