/*
** duplicate_eye.c for function for the duplication of eyes in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sun Jun  7 12:53:57 2015 quentin gasparotto
** Last update Sun Jun  7 13:16:33 2015 quentin gasparotto
*/

#include "prototypes.h"

int	add_end_eye(t_eye **list, t_eye act_eye)
{
  t_eye	*elem;
  t_eye	*tmp;
  int	i;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  *elem = act_eye;
  i = 0;
  while (i < 9)
    {
      elem->convolution[i] = act_eye.convolution[i];
      ++i;
    }
  elem->next = NULL;
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

t_eye	*duplicate_eyes(t_eye *list)
{
  t_eye	*new_list;
  t_eye	*tmp;

  new_list = NULL;
  tmp = list;
  while (tmp != NULL)
    {
      if (add_end_eye(&new_list, *tmp) == -1)
	return (NULL);
      tmp = tmp->next;
    }
  return (new_list);
}
