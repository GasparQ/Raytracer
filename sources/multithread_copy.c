/*
** multithread_copy.c for copy in /home/combau_a/testclones/lel/MUL_2014_rtracer
**
** Made by Alban Combaud
** Login   <combau_a@epitech.net>
**
** Started on  Sat Jun  6 17:22:20 2015 Alban Combaud
** Last update Sat Jun  6 20:20:20 2015 adrien milcent
*/

#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

int		struct_spot(t_spot *tmp, t_spot *tmp_spot, int i)
{
  i = 0;
  if ((tmp->color =
       malloc(100 + my_strlen_unsigned(tmp_spot->color) * sizeof(char)))
      == NULL)
    return (-1);
  while (tmp_spot->color[i] != 0)
    {
      tmp->color[i] = tmp_spot->color[i];
      i++;
    }
  tmp->color[i] = 0;
  tmp->i = tmp_spot->i;
  tmp->origin.x = tmp_spot->origin.x;
  tmp->origin.y = tmp_spot->origin.y;
  tmp->origin.z = tmp_spot->origin.z;
  return (0);
}

int		fill_spot(t_spot *tmp_spot, t_scene *tmp_scene, int i)
{
  t_spot	*tmp;

  if ((tmp = malloc(sizeof(t_spot *) * 100)) == NULL)
    return (-1);
  if (struct_spot(tmp, tmp_spot, i) == -1)
    return (-1);
  tmp->next = NULL;
  tmp_scene->spot_list = tmp;
  tmp_spot = tmp_spot->next;
  while (tmp_spot != NULL)
    {
      if ((tmp = malloc(sizeof(t_spot *) * 100)) == NULL)
        return (-1);
      if (struct_spot(tmp, tmp_spot, i) == -1)
        return (-1);
      tmp->next = tmp_scene->spot_list;
      tmp_scene->spot_list = tmp;
      tmp_spot = tmp_spot->next;
    }
  return (0);
}

void		struct_eye(t_eye *tmp2, t_eye *tmp_eye)
{
  int		i;

  i = 0;
  tmp2->pos.x = tmp_eye->pos.x;
  tmp2->pos.y = tmp_eye->pos.y;
  tmp2->pos.z = tmp_eye->pos.z;
  tmp2->dir.x = tmp_eye->dir.x;
  tmp2->dir.y = tmp_eye->dir.y;
  tmp2->dir.z = tmp_eye->dir.z;
  while (i < 9)
    {
      tmp2->convolution[i] = tmp_eye->convolution[i];
      ++i;
    }
  tmp2->distance = tmp_eye->distance;
}

int		fill_eye(t_scene *tmp_scene, t_scene *tmp)
{
  t_eye		*tmp2;
  t_eye		*tmp_eye;

  if ((tmp2 = malloc(sizeof(t_eye *) * 100)) == NULL)
    return (-1);
  struct_eye(tmp2, tmp->eye);
  tmp2->next = NULL;
  tmp_scene->eye = tmp2;
  tmp_eye = tmp->eye->next;
  while (tmp_eye != NULL)
    {
      if ((tmp2 = malloc(sizeof(t_eye *) * 100)) == NULL)
        return (-1);
      struct_eye(tmp2, tmp_eye);
      tmp2->next = tmp_scene->eye;
      tmp_scene->eye = tmp2;
      tmp_eye = tmp_eye->next;
    }
  return (0);
}

int		my_strlen_unsigned(unsigned char *str)
{
  int		i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}
