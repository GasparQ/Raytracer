/*
** duplicate_scene.c for function for the duplication of the scenes in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sun Jun  7 12:37:59 2015 quentin gasparotto
** Last update Sun Jun  7 23:18:01 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int		add_end_scene(t_scene **list, t_scene scene)
{
  t_scene	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  *elem = scene;
  if (*list == NULL)
    {
      elem->next = elem;
      elem->prev = elem;
      *list = elem;
    }
  else
    {
      elem->next = (*list);
      elem->prev = (*list)->prev;
      elem->prev->next = elem;
      (*list)->prev = elem;
    }
  return (0);
}

int	fill_scene(t_scene *elem, t_scene ref)
{
  if (ref.spot_list == NULL || ref.obj_list == NULL ||
      ref.img == NULL || ref.eye == NULL)
    return (-1);
  *elem = ref;
  if ((elem->spot_list = duplicate_spot(ref.spot_list,
					ref.img->bpp)) == NULL ||
      (elem->obj_list = duplicate_obj(ref.obj_list,
				      ref.img->bpp, &ref)) == NULL ||
      (elem->eye = duplicate_eyes(ref.eye)) == NULL ||
      (elem->img = duplicate_img(ref.img)) == NULL)
    return (-1);
  elem->act_image = elem->img;
  elem->act_eye = elem->eye;
  return (0);
}

t_scene		*duplicate_scene(t_scene *scene_list)
{
  t_scene	*new_list;
  t_scene	new_scene;
  t_scene	*tmp;

  if (scene_list == NULL)
    return (NULL);
  new_list = NULL;
  tmp = scene_list->next;
  if (fill_scene(&new_scene, *scene_list) == -1)
    return (NULL);
  if (add_end_scene(&new_list, new_scene) == -1)
    return (NULL);
  while (tmp != scene_list)
    {
      if (fill_scene(&new_scene, *tmp) == -1)
	return (NULL);
      if (add_end_scene(&new_list, new_scene) == -1)
	return (NULL);
      tmp = tmp->next;
    }
  return (new_list);
}
