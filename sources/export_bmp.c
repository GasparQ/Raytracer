/*
** export_bmp.c for function for the export into bmp in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Jun  2 14:55:17 2015 quentin gasparotto
** Last update Tue Jun  2 17:23:55 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void	write_integer(int fd, unsigned int value)
{
  char	value_buff[4];

  value_buff[0] = (value / (3 * 255)) % 255;
  value_buff[1] = (value / (2 * 255)) % 255;
  value_buff[2] = (value / 255) % 255;
  value_buff[3] = value % 255;
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

int	export_bmp(t_image *exp_img)
{
  int	fd;
  char	tu;

  if ((fd = get_file()) == -1)
    return (-1);
  write(fd, "BM", 2);
  write_integer(fd, 200); /* file size */
  write_integer(fd, 0);
  write_integer(fd, 0); /* offset */
  write(fd, "28", 2); /* header size */
  write_integer(fd, WDW_WIDTH);
  write_integer(fd, WDW_HEIGHT);
  write(fd, "\x0\x1", 2);
  write_integer(fd, exp_img->bpp);
  write_integer(fd, 0); /* mode de compression */
  write_integer(fd, WDW_WIDTH * WDW_HEIGHT * exp_img->bpp / 8);
  write_integer(fd, WDW_WIDTH);
  write_integer(fd, WDW_HEIGHT);
  write_integer(fd, 4228250625);
  write_integer(fd, 0);
  write(fd, exp_img, WDW_WIDTH * WDW_HEIGHT * exp_img->bpp / 8);
  close(fd);
  return (0);
}
