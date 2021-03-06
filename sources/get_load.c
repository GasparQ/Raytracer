/*
** get_load.c for function for get load images in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sun Jun  7 17:58:08 2015 quentin gasparotto
** Last update Sun Jun  7 22:29:56 2015 quentin gasparotto
*/

#include "prototypes.h"

void	init_load(char **load_img)
{
  load_img[0] = "loader/0.xpm";
  load_img[1] = "loader/10.xpm";
  load_img[2] = "loader/20.xpm";
  load_img[3] = "loader/30.xpm";
  load_img[4] = "loader/40.xpm";
  load_img[5] = "loader/50.xpm";
  load_img[6] = "loader/60.xpm";
  load_img[7] = "loader/70.xpm";
  load_img[8] = "loader/80.xpm";
  load_img[9] = "loader/90.xpm";
  load_img[10] = "loader/100.xpm";
  load_img[11] = "loader/110.xpm";
  load_img[12] = "loader/120.xpm";
  load_img[13] = "loader/130.xpm";
  load_img[14] = "loader/140.xpm";
  load_img[15] = "loader/150.xpm";
  load_img[16] = "loader/160.xpm";
  load_img[17] = "loader/170.xpm";
  load_img[18] = "loader/180.xpm";
  load_img[19] = "loader/190.xpm";
}

int	get_load(void *mlx, t_image *load)
{
  char	*load_img[20];
  int	i;

  init_load(load_img);
  i = 0;
  while (i < 20)
    {
      if (load_texture(&load[i], load_img[i], mlx) == -1)
	return (-1);
      ++i;
    }
  return (0);
}
