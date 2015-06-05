/*
** load_texture.c for function for load a texture in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Jun  3 10:43:46 2015 quentin gasparotto
** Last update Fri Jun  5 18:18:16 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

size_t		strlcpy(char *dst, char *src, size_t dstsize)
{
  size_t	i;

  i = 0;
  while (i < dstsize)
    {
      dst[i] = src[i];
      ++i;
    }
  return (i);
}

int	load_texture(t_image *text, char *filename, void *mlx)
{
  int	width;
  int	height;

  if ((text->img = mlx_xpm_file_to_image(mlx, filename,
					 &width, &height)) == NULL)
      return (-1);
  printf("texture get\n");
  if ((text->dat = mlx_get_data_addr(text->img, &text->bpp,
				     &text->wdth, &text->edn)) == NULL)
    return (-1);
  printf("data get\n");
  text->hght = height;
  return (0);
}
