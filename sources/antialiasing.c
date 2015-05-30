/*
** antialiasing.c for function for the antialiasing of the image in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sat May 30 14:45:47 2015 quentin gasparotto
** Last update Sat May 30 15:01:14 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int		antialiasing(t_image *act_image, t_scene *scene)
{
  t_image       nice_img;
  int		x;
  int		y;

  nice_img = init_img(&nice_img, WDW_WIDTH, WDW_HEIGHT, scene);
  y = 0;
  while (y < WDW_HEIGHT)
    {
      x = 0;
      while (x < WDW_WIDTH)
	{
	  ++x;
	}
      ++y;
    }
}
