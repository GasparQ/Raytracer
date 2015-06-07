/*
** loading.c for rtracer in /home/milcen_a/rendu/Graph_Prog/MUL_2014_rtracer
**
** Made by adrien milcent
** Login   <milcen_a@epitech.net>
**
** Started on  Sun Jun  7 22:41:48 2015 adrien milcent
** Last update Sun Jun  7 22:43:40 2015 adrien milcent
*/

#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

void	check_max(int *x, int *y, int max)
{
  if (*x <= max && *y <= max)
    {
      if (*x == max)
	{
	  ++(*y);
	  *x = 0;
	}
      else
	++(*x);
    }
}

void	load_my_image(int nb, int nb_t, t_scene *copy)
{
  int	width;
  int	height;
  int	max;
  int	x;
  int	y;
  int	i;

  i = 0;
  x = 0;
  y = 0;
  max = (nb_t / 2) - 1;
  while (i != nb && i < nb_t)
    {
      check_max(&x, &y, max);
      ++i;
    }
  width = x * (WDW_WIDTH / (nb_t / 2));
  height = y * (WDW_HEIGHT / 2);
  load_image(copy, get_vector2(width, height),
	     get_vector2(WDW_WIDTH / (nb_t / 2), WDW_HEIGHT / 2));
}
