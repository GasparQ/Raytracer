/*
** get_load.c for function for get load images in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sun Jun  7 17:58:08 2015 quentin gasparotto
** Last update Sun Jun  7 19:30:07 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void	init_load(char **load_img)
{
  load_img[0] = "0.xpm";
  load_img[1] = "10.xpm";
  load_img[2] = "20.xpm";
  load_img[3] = "30.xpm";
  load_img[4] = "40.xpm";
  load_img[5] = "50.xpm";
  load_img[6] = "60.xpm";
  load_img[7] = "70.xpm";
  load_img[8] = "80.xpm";
  load_img[9] = "90.xpm";
  load_img[10] = "100.xpm";
}

void	init_preload(char **load_img)
{
  load_img[0] = "";
  load_img[1] = "";
  load_img[2] = "";
  load_img[3] = "";
  load_img[4] = "";
  load_img[5] = "";
  load_img[6] = "";
  load_img[7] = "";
  load_img[8] = "";
  load_img[9] = "";
}

int	get_load(void *mlx, t_image *load, int mode)
{
  char	*load_img[11];
  int	i;

  if (mode == 0)
    init_load(load_img);
  else
    init_preload(load_img);
  i = 0;
  while (i < 10)
    {
      if (load_texture(&load[i], load_img[i], mlx) == -1)
	return (-1);
      ++i;
    }
  return (0);
}
