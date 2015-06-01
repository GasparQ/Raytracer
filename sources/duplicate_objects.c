/*
** duplicate_objects.c for function for duplicate obj list in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Mon Jun  1 18:02:09 2015 quentin gasparotto
** Last update Mon Jun  1 18:21:21 2015 adrien milcent
*/

#include "../include/prototypes.h"

int		add_end_obj(t_object **obj_list, t_object obj, int bpp)
{
  t_object	*elem;
  t_object	*tmp;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  *elem = obj;
  elem->next = NULL;
  if ((elem->disp_color = malloc(bpp / 8)) == NULL)
    return (-1);
  if (*obj_list != NULL)
    {
      tmp = *obj_list;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elem;
    }
  else
    *obj_list = elem;
  return (0);
}

t_object	*duplicate_obj(t_object *obj_list, int bpp)
{
  t_object	*new;

  new = NULL;
  while (obj_list != NULL)
    {
      if (add_end_obj(&new, *obj_list, bpp) == -1)
	return (NULL);
      obj_list = obj_list->next;
    }
  return (new);
}
