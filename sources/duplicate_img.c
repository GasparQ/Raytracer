/*
** duplicate_img.c for function for the duplication of the images in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sun Jun  7 12:58:27 2015 quentin gasparotto
** Last update Sun Jun  7 13:19:53 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int		add_end_img(t_image **list, t_image img)
{
  t_image	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  *elem = img;
  if ((elem->average = malloc(sizeof(int) * img.bpp / 8)) == NULL)
    return (-1);
  if ((elem->color = malloc(img.bpp / 8)) == NULL)
    return (-1);
  copy_color(img.color, elem->color, img.bpp);
  if (*list == NULL)
    {
      elem->next = elem;
      elem->prev = elem;
      *list = elem;
    }
  else
    {
      elem->prev = (*list)->prev;
      elem->next = *list;
      (*list)->prev->next = elem;
      (*list)->prev = elem;
    }
  return (0);
}

t_image		*duplicate_img(t_image *list)
{
  t_image	*new_list;
  t_image	*tmp;

  new_list = NULL;
  if (add_end_img(&new_list, *list) == -1)
    return (NULL);
  tmp = list->next;
  while (tmp != list)
    {
      if (add_end_img(&new_list, *tmp) == -1)
	return (NULL);
      tmp = tmp->next;
    }
  return (new_list);
}
