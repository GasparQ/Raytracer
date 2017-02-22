/*
** duplicate_spot.c for function for the duplication of the spots in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sun Jun  7 12:45:49 2015 quentin gasparotto
** Last update Sun Jun  7 13:16:18 2015 quentin gasparotto
*/

#include "prototypes.h"

int		add_end_spot(t_spot **list, t_spot act, int bpp)
{
  t_spot	*elem;
  t_spot	*tmp;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  *elem = act;
  if ((elem->color = malloc(bpp / 8)) == NULL)
    return (-1);
  elem->next = NULL;
  copy_color(act.color, elem->color, bpp);
  if (*list != NULL)
    {
      tmp = *list;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elem;
    }
  else
    *list = elem;
  return (0);
}

t_spot		*duplicate_spot(t_spot *spot_list, int bpp)
{
  t_spot	*new_list;
  t_spot	*tmp;

  new_list = NULL;
  tmp = spot_list;
  while (tmp != NULL)
    {
      if (add_end_spot(&new_list, *tmp, bpp) == -1)
	return (NULL);
      tmp = tmp->next;
    }
  return (new_list);
}
