/*
** export_bmp.c for function for the export into bmp in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Jun  2 14:55:17 2015 quentin gasparotto
** Last update Tue Jun  2 22:58:44 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void		write_integer(int fd, unsigned int value)
{
  unsigned char	value_buff[4];

  value_buff[3] = (int)(value / pow(256, 3)) % 256;
  value_buff[2] = (int)(value / pow(256, 2)) % 256;
  value_buff[1] = (int)(value / 256) % 256;
  value_buff[0] = value % 256;
  write(fd, value_buff, 4);
}

int	get_file()
{
  int	fd;
  char	*filename;
  int	i;

  if ((filename = malloc(10)) == NULL)
    return (-1);
  my_strncpy("img_1.bmp", filename, 10);
  i = 2;
  while (access(filename, F_OK) != -1)
    {
      if (i % 10 == 0)
	{
	  free(filename);
	  if ((filename = malloc(9 + i / 10 + 1)) == NULL)
	    return (-1);
	}
      sprintf(filename, "img_%d.bmp", i);
      ++i;
    }
  if ((fd = open(filename, O_WRONLY | O_CREAT, 0644)) == -1)
    return (-1);
  free(filename);
  return (fd);
}

void	write_color(t_image *exp_img, int x, int y, int fd)
{
  int	i;

  if (exp_img->edn == 1)
    {
      i = 3;
      while (i > 0)
	{
	  write(fd, &exp_img->dat[(WDW_HEIGHT - y) * exp_img->wdth +
				  x * 4 + i], 1);
	  --i;
	}
    }
  else
    {
      i = 0;
      while (i < 3)
	{
	  write(fd, &exp_img->dat[(WDW_HEIGHT - y) * exp_img->wdth +
				  x * 4 + i], 1);
	  ++i;
	}
    }
}

void	write_img(t_image *exp_img, int fd)
{
  int	y;
  int	x;

  y = 0;
  while (y < WDW_HEIGHT)
    {
      x = 0;
      while (x < WDW_WIDTH)
	{
	  write_color(exp_img, x, y, fd);
	  ++x;
	}
      ++y;
    }
}

int	export_bmp(t_image *exp_img)
{
  int	fd;

  if (exp_img->bpp != 32)
    return (0);
  if ((fd = get_file()) == -1)
    return (-1);
  write(fd, "BM", 2);
  write_integer(fd, 54 + WDW_WIDTH * WDW_HEIGHT * 3);
  write_integer(fd, 0);
  write_integer(fd, 54);
  write(fd, "(\x0\x0\x0", 4);
  write_integer(fd, WDW_WIDTH);
  write_integer(fd, WDW_HEIGHT);
  write(fd, "\x1\x0", 2);
  write(fd, "\x18\x0", 2);
  write_integer(fd, 0);
  write_integer(fd, WDW_WIDTH * WDW_HEIGHT * 3);
  write_integer(fd, 0);
  write_integer(fd, 0);
  write_integer(fd, 0);
  write_integer(fd, 0);
  write_img(exp_img, fd);
  close(fd);
  return (0);
}
