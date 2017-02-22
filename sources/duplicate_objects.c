/*
** duplicate_objects.c for function for duplicate obj list in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Mon Jun  1 18:02:09 2015 quentin gasparotto
** Last update Sun Jun  7 15:24:14 2015 quentin gasparotto
*/

#include "prototypes.h"

int	check_texture(t_object *obj, t_object *elem, int bpp, t_scene *scene)
{
  if (obj->texture != NULL)
    {
      if ((elem->texture->color = malloc(bpp / 8)) == NULL)
	return (-1);
      get_color(0, elem->texture->color, scene);
    }
  if (obj->proced != NULL)
    {
      if ((elem->proced->color = malloc(bpp / 8)) == NULL)
	return (-1);
      if ((elem->color1 = malloc(bpp / 8)) == NULL)
	return (-1);
      if ((elem->color2 = malloc(bpp / 8)) == NULL)
	return (-1);
      copy_color(obj->color1, elem->color1, bpp);
      copy_color(obj->color2, elem->color2, bpp);
    }
  if (obj->bump != NULL)
    {
      if ((elem->bump->color = malloc(bpp / 8)) == NULL)
	return (-1);
    }
  return (0);
}

int		add_end_obj(t_object **obj_list, t_object *obj,
			    int bpp, t_scene *scene)
{
  t_object	*elem;
  t_object	*tmp;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  *elem = *obj;
  if (elem->limit != NULL &&
      (elem->limit = duplicate_obj(elem->limit, bpp, scene)) == NULL)
    return (-1);
  elem->next = NULL;
  if ((elem->disp_color = malloc(bpp / 8)) == NULL)
    return (-1);
  if (check_texture(obj, elem, bpp, scene) == -1)
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

t_object	*duplicate_obj(t_object *obj_list, int bpp, t_scene *scene)
{
  t_object	*new;

  new = NULL;
  while (obj_list != NULL)
    {
      if (add_end_obj(&new, obj_list, bpp, scene) == -1)
	return (NULL);
      obj_list = obj_list->next;
    }
  return (new);
}
