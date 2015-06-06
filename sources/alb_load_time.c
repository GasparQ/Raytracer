/*
** loading_time.c for function for the load of each eyes in each scenes in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Sat May 30 20:46:53 2015 quentin gasparotto
** Last update Sat Jun  6 11:06:26 2015 Alban Combaud
*/

#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

t_scene         *init_scene(void)
{
  t_scene       *tmp;

  if ((tmp = malloc(sizeof(t_scene *) * 100)) == NULL)
    return (NULL);
  tmp->prev = tmp;
  tmp->next = tmp;
  return (tmp);
}

int             my_strlen_unsigned(unsigned char *str)
{
  int           i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}

int		fill_spot(t_spot *tmp_spot, t_scene *tmp_scene, int i)
{
  while (tmp_spot != NULL)
    {
      i = 0;
      if ((tmp_scene->spot_list = malloc(sizeof(t_spot *) * 100)) == NULL)
	return (-1);
      if ((tmp_scene->spot_list->color =
	   malloc(my_strlen_unsigned(tmp_spot->color) * sizeof(char))) == NULL)
	return (-1);
      while (tmp_spot->color[i] != 0)
	{
	  tmp_scene->spot_list->color[i] = tmp_spot->color[i];
	  i++;
	}
      tmp_scene->spot_list->color[i] = 0;
      tmp_scene->spot_list->i = tmp_spot->i;
      tmp_scene->spot_list->origin.x = tmp_spot->origin.x;
      tmp_scene->spot_list->origin.y = tmp_spot->origin.y;
      tmp_scene->spot_list->origin.z = tmp_spot->origin.z;
      tmp_spot = tmp_spot->next;
    }
  return (0);
}

int		fill_eye(t_scene *tmp_scene, t_scene *tmp)
{
  if ((tmp_scene->eye = malloc(sizeof(t_eye *) * 100)) == NULL)
    return (-1);
  tmp_scene->eye->pos.x = tmp->eye->pos.x;
  tmp_scene->eye->pos.y = tmp->eye->pos.y;
  tmp_scene->eye->pos.z = tmp->eye->pos.z;
  tmp_scene->eye->dir.x = tmp->eye->dir.x;
  tmp_scene->eye->dir.y = tmp->eye->dir.y;
  tmp_scene->eye->dir.z = tmp->eye->dir.z;
  return (0);
}

int		fill_img(t_scene *tmp_scene, t_image *tmp_image, int i)
{
  if ((tmp_scene->img = malloc(sizeof(t_image *) * 100)) == NULL)
    return (-1);
  tmp_scene->img->img = tmp_image->img;
  tmp_scene->img->dat = tmp_image->dat;
  tmp_scene->img->bpp = tmp_image->bpp;
  tmp_scene->img->wdth = tmp_image->wdth;
  tmp_scene->img->hght = tmp_image->hght;
  tmp_scene->img->edn = tmp_image->edn;
  if ((tmp_scene->img->average = malloc(sizeof(int *) * (tmp_image->bpp / 8)))
      == NULL)
    return (-1);
  if ((tmp_scene->img->color =
       malloc(2 * (my_strlen_unsigned(tmp_image->color) + 100))) == NULL)
    return (-1);
  i = 0;
  while (tmp_image->color[i] != 0)
    {
      tmp_scene->img->color[i] = tmp_image->color[i];
      i++;
    }
  tmp_scene->img->color[i] = 0;
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
  t_scene       *tmp_scene;

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

void    launch_scene(t_system *sys, t_scene *scene)
{
  scene->act_image = scene->img;
  scene->act_eye = scene->eye;
  while (scene->act_eye != NULL)
    {
      load_image(scene, get_vector2(0, 0),
                 get_vector2(WDW_WIDTH, WDW_HEIGHT));
      if (scene->act_image->render_method == &antialias_method)
        resolve_effects(scene->act_image, scene,
                        &resolve_antialiased_color);
      else if (scene->act_image->render_method == &cell_shade_method)
        resolve_effects(scene->act_image, scene, &resolve_cell_shading);
      //get_border(scene);
      mlx_put_image_to_window(sys->mlx, sys->wdw,
                              scene->act_image->img, 0, 0);
      scene->act_eye = scene->act_eye->next;
      scene->act_image = scene->act_image->next;
    }
}

void            loading_time(t_system *sys)
{
  t_scene       *scene;
  t_scene	*copy;

  scene = sys->scene_list->next;
  launch_scene(sys, sys->scene_list);
  //duplicate_obj(sys->scene_list->obj_list, sys->scene_list->img->bpp);
  while (scene != sys->scene_list)
    {
      launch_scene(sys, scene);
      scene = scene->next;
    }
  scene = sys->scene_list;
  copy = init_scene();
  copy_list(scene, copy, NULL);
}
