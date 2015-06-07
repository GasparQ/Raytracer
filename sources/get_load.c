/*
** get_load.c for function for get load images in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sun Jun  7 17:58:08 2015 quentin gasparotto
** Last update Sun Jun  7 18:07:07 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void	init_load(char **load_img)
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

int	get_load(t_system *sys)
{
  char	*load_img[10];
  int	i;

  init_load(load_img);
  i = 0;
  while (i < 10)
    {
      if (load_texture(&sys->load[i], load_img[i], sys->mlx) == -1)
	return (-1);
      ++i;
    }
  return (0);
}
