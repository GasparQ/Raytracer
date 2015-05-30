/*
** getters.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer/parser
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sat May 30 20:34:09 2015 fernand veyrier
** Last update Sat May 30 20:35:15 2015 fernand veyrier
*/

#include "get_next_line.h"

t_vector3	get_vector(char *buf)
{
  int		i;
  int		j;
  t_vector3	vec;
  char		nbr[BUFSIZ];

  i = 0;
  while ((j = 0) == 0 && buf[i] && buf[i] != '(')
    ++i;
  while (buf[++i] != ',')
    nbr[j++] = buf[i];
  nbr[j] = 0;
  vec.x = atof(nbr);
  j = 0;
  ++i;
  while (buf[i] != ',')
    nbr[j++] = buf[i++];
  nbr[j] = 0;
  vec.y = atof(nbr);
  j = 0;
  ++i;
  while (buf[i] != ')')
    nbr[j++] = buf[i++];
  nbr[j] = 0;
  vec.z = atof(nbr);
  return (vec);
}

int		get_color_parser(char *buf)
{
  int		i;
  int		j;
  char		nbr[BUFSIZ];

  i = 0;
  j = 0;
  while (buf[i] && buf[i] != 'x')
    ++i;
  ++i;
  while (buf[i] && ((buf[i] >= '0' && buf[i] <= '9')
		    || (buf[i] >= 'A' && buf[i] <= 'F')))
    nbr[j++] = buf[i++];
  nbr[j] = 0;
  return (my_getnbr_base(nbr, "0123456789ABCDEF"));
}

int		get_nbr_parser(char *buf)
{
  int		i;
  int		j;
  char		nbr[BUFSIZ];

  i = 0;
  j = 0;
  while (buf[i] && !(buf[i] >= '0' && buf[i] <= '9') && buf[i] != '-')
    ++i;
  while (buf[i] && ((buf[i] >= '0' && buf[i] <= '9') || buf[i] == '-'))
    nbr[j++] = buf[i++];
  nbr[j] = 0;
  return (atoi(nbr));
}

double		get_double_parser(char *buf)
{
  int		i;
  int		j;
  char		nbr[BUFSIZ];

  i = 0;
  j = 0;
  while (buf[i] && !(buf[i] >= '0' && buf[i] <= '9') && buf[i] != '-')
    ++i;
  while (buf[i] && ((buf[i] >= '0' && buf[i] <= '9')
		    || buf[i] == '-' || buf[i] == '.'))
    nbr[j++] = buf[i++];
  nbr[j] = 0;
  return (atof(nbr));
}
