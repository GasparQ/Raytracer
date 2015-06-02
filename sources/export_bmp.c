/*
** export_bmp.c for function for the export into bmp in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Jun  2 14:55:17 2015 quentin gasparotto
** Last update Tue Jun  2 20:00:56 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void		write_integer(int fd, unsigned int value/* , int mode */)
{
  unsigned char	value_buff[4];
  int		i;

  /* if (mode == 1) */
  /*   { */
      /* printf("%d %x\n", value, value); */
  value_buff[3] = (int)(value / pow(256, 3)) % 256;
  value_buff[2] = (int)(value / pow(256, 2)) % 256;
  value_buff[1] = (int)(value / 256) % 256;
  value_buff[0] = value % 256;
    /* } */
  /* else */
  /*   { */
  /*     value_buff[0] = (int)(value / pow(255, 3)) % 255; */
  /*     value_buff[1] = (int)(value / pow(255, 2)) % 255; */
  /*     value_buff[2] = (int)(value / 255) % 255; */
  /*     value_buff[3] = value % 255; */
  /*   } */
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

int	write_img(t_image *exp_img, int fd)
{
  int	y;
  int	x;
  int	i;
  int	wr;

  y = 0;
  while (y < WDW_HEIGHT)
    {
      wr = 0;
      x = 0;
      while (x < WDW_WIDTH * 4)
	{
	  if (x % 4 != ((exp_img->edn == 1) ? 0 : 3))
	    {
	      write(fd, &exp_img->dat[y * exp_img->hght + x * exp_img->wdth], 1);
	      ++wr;
	    }
	  ++x;
	}
      //printf("%d\n", wr);
      //write(fd, "\x0\x0\x0", 3);
      ++y;
    }
}

int	export_bmp(t_image *exp_img)
{
  int	fd;
  unsigned char	tu;
  unsigned char	bp[2];

  if ((fd = get_file()) == -1)
    return (-1);

  write(fd, "BM", 2);
  write_integer(fd, 2 + 4 + 4 + 4 + 2 + 4 + 4 + 2 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + WDW_WIDTH * WDW_HEIGHT * 3/* exp_img->bpp / 8 *//* , 0 */); /* file size */
  write_integer(fd, 0/* , 0 */); /* réserver pour rien */
  write_integer(fd, 54/* , 1 */); /* offset */

  write(fd, "(\x0\x0\x0", 4); /* header size */
  write_integer(fd, WDW_WIDTH/* , 0 */); /* width */
  write_integer(fd, WDW_HEIGHT/* , 0 */); /* height */
  write(fd, "\x1\x0", 2); /* img head size */
  write(fd, "\x18\x0", 2);
  /* bp[0] = (24/\* exp_img->bpp *\/ / 255) % 255; */
  /* bp[1] = 24/\* exp_img->bpp *\/ % 255; */
  /* write(fd, bp, 2); /\* bpp *\/ */
  write_integer(fd, 0/* , 0 */); /* mode de compression */
  write_integer(fd, WDW_WIDTH * WDW_HEIGHT * 3/* exp_img->bpp / 8 *//* , 0 */); /* img size */
  write_integer(fd, 0/* , 0 */);
  write_integer(fd, 0/* , 0 */);
  write_integer(fd, 0/* , 0 */);
  write_integer(fd, 0/* , 0 */);
  write_img(exp_img, fd);
  //write(fd, exp_img, WDW_WIDTH * WDW_HEIGHT * exp_img->bpp / 8);
  close(fd);
  return (0);
}

/* int	main() */
/* { */
/*   export_bmp(NULL); */
/* } */
