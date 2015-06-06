/*
** fill_new_list.c for fill in /home/combau_a/testclones/lel/MUL_2014_rtracer
**
** Made by Alban Combaud
** Login   <combau_a@epitech.net>
**
** Started on  Sat Jun  6 17:28:50 2015 Alban Combaud
** Last update Sat Jun  6 17:30:55 2015 Alban Combaud
*/

#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

t_scene		*init_scene(void)
{
  t_scene	*tmp;

  if ((tmp = malloc(sizeof(t_scene *) * 100)) == NULL)
    return (NULL);
  tmp->prev = tmp;
  tmp->next = tmp;
  return (tmp);
}

int		struct_img(t_image *tmp, t_image *tmp_image, int i)
{
  tmp->img = tmp_image->img;
  tmp->dat = tmp_image->dat;
  tmp->bpp = tmp_image->bpp;
  tmp->wdth = tmp_image->wdth;
  tmp->hght = tmp_image->hght;
  tmp->edn = tmp_image->edn;
  tmp->i_tab = tmp_image->i_tab;
  if ((tmp->average = malloc(sizeof(int *) * (tmp_image->bpp / 8)))
      == NULL)
    return (-1);
  if ((tmp->color =
       malloc(2 * (my_strlen_unsigned(tmp_image->color) + 100))) == NULL)
    return (-1);
  i = 0;
  while (tmp_image->color[i] != 0)
    {
      tmp->color[i] = tmp_image->color[i];
      i++;
    }
  tmp->color[i] = 0;
  tmp->render_method = tmp_image->render_method;
  return (0);
}

int		fill_img(t_scene *tmp_scene, t_image *tmp_image, int i)
{
  t_image	*tmp;
  t_image	*save;

  if ((tmp = malloc(sizeof(t_image *) * 100)) == NULL)
    return (-1);
  struct_img(tmp, tmp_image, i);
  tmp->next = tmp;
  tmp->prev = tmp;
  tmp_scene->img = tmp;
  save = tmp_image->next;
  while (save != tmp_image)
    {
      if ((tmp = malloc(sizeof(t_image *) * 100)) == NULL)
        return (-1);
      struct_img(tmp, save, i);
      tmp->prev = tmp_scene->img;
      tmp->next = tmp_scene->img->next;
      tmp_scene->img->next->prev = tmp;
      tmp_scene->img->next = tmp;
      save = save->next;
    }
  return (0);
}

int		fill_new_list(t_scene *new, t_scene *tmp, t_scene *tmp_scene)
{
  if (fill_spot(tmp->spot_list, tmp_scene, 0) == -1)
    return (-1);
  tmp_scene->spot_nb = tmp->spot_nb;
  tmp_scene->obj_list = duplicate_obj(tmp->obj_list, tmp->img->bpp, tmp);
  if (fill_eye(tmp_scene, tmp) == -1)
    return (-1);
  if (fill_img(tmp_scene, tmp->img, 0) == -1)
    return (-1);
  tmp_scene->mlx = tmp->mlx;
  tmp_scene->prev = new;
  tmp_scene->next = new->next;
  new->next->prev = tmp_scene;
  new->next = tmp_scene;
  return (0);
}

int		copy_list(t_scene *scene, t_scene *new, t_scene *tmp)
{
  t_scene	*tmp_scene;

  tmp = scene;
  if ((tmp_scene = malloc(sizeof(t_scene *) * 100)) == NULL)
    return (-1);
  if (fill_new_list(new, tmp, tmp_scene) == -1)
    return (-1);
  tmp = tmp->next;
  while (tmp != scene)
    {
      if (fill_new_list(new, tmp, tmp_scene) == -1)
        return (-1);
      tmp = tmp->next;
    }
  return (0);
}
