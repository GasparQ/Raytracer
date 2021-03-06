/*
** list_fn.c for list functions in /home/gaspar_q/rendu/Igraph/MUL_2014_rtv1/sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Feb  3 17:42:07 2015 quentin gasparotto
** Last update Sat Jun  6 20:14:24 2015 quentin gasparotto
*/

#include "minilibx_system.h"
#include "prototypes.h"

int		my_put_in_list(t_object **list, t_object data)
{
  t_object	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    exit(my_strerror(MALLOC_ERR));
  elem->origin = data.origin;
  elem->rotation = data.rotation;
  elem->phong = data.phong;
  elem->disp_color = data.disp_color;
  elem->limit = data.limit;
  elem->obj_color = data.obj_color;
  elem->texture = data.texture;
  elem->proced = data.proced;
  elem->color1 = data.color1;
  elem->color2 = data.color2;
  elem->apply_texture = data.apply_texture;
  elem->bump = data.bump;
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
      free_my_list(list->limit);
      free(list);
      list = tmp;
    }
}

void		free_image_list(t_image *img_list)
{
  t_image	*tmp;

  if (img_list == NULL)
    return ;
  if (img_list->prev != img_list)
    img_list->prev->next = NULL;
  else
    img_list->next = NULL;
  while (img_list != NULL)
    {
      tmp = img_list->next;
      free(img_list->color);
      free(img_list->average);
      free(img_list);
      img_list = tmp;
    }
}
