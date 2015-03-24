/*
** list_fn.c for list functions in /home/gaspar_q/rendu/Igraph/MUL_2014_rtv1/sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Feb  3 17:42:07 2015 quentin gasparotto
** Last update Tue Mar 24 19:46:26 2015 quentin gasparotto
*/

#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

int		my_put_in_list(t_object **list, t_object data)
{
  t_object	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    exit(my_strerror(MALLOC_ERR));
  elem->origin.x = data.origin.x;
  elem->origin.y = data.origin.y;
  elem->origin.z = data.origin.z;
  elem->rotation.x = data.rotation.x;
  elem->rotation.y = data.rotation.y;
  elem->rotation.z = data.rotation.z;
  elem->brightness = data.brightness;
  elem->opacity = data.opacity;
  elem->reflect = data.reflect;
  elem->disp_color = data.disp_color;
  elem->middle_ind = data.middle_ind;
  elem->next = *list;
  *list = elem;
  return (CLEAN);
}

void		free_spot_list(t_spot *list)
{
  t_spot	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      free(list->color);
      free(list);
      list = tmp;
    }
}

void		free_my_list(t_object *list)
{
  t_object	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      tmp = list->next;
      free(list->disp_color);
      list->free_mesh(list->mesh);
      free(list);
      list = tmp;
    }
}
