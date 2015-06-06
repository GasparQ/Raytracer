/*
** loading_time.c for function for the load of each eyes in each scenes in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Sat May 30 20:46:53 2015 quentin gasparotto
** Last update Sat Jun  6 16:41:51 2015 Alban Combaud
*/

#include <omp.h>
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
  t_spot	*tmp;

  i = 0;
  if ((tmp_scene->spot_list = malloc(sizeof(t_spot *) * 100)) == NULL)
    return (-1);
  if ((tmp_scene->spot_list->color =
       malloc(100 + my_strlen_unsigned(tmp_spot->color) * sizeof(char)))
      == NULL)
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
  tmp_scene->spot_list->next = NULL;
  tmp_spot = tmp_spot->next;
  while (tmp_spot != NULL)
    {
      i = 0;
      if ((tmp = malloc(sizeof(t_spot *) * 100)) == NULL)
	return (-1);
      if ((tmp->color =
	   malloc(100 + my_strlen_unsigned(tmp_spot->color) * sizeof(char)))
      == NULL)
	return (-1);
      while (tmp_spot->color[i] != 0)
	{
	  tmp->color[i] = tmp_spot->color[i];
	  i++;
	}
      tmp->color[i] = 0;
      tmp->i = tmp_spot->i;
      tmp->origin.x = tmp_spot->origin.x;
      tmp->origin.y = tmp_spot->origin.y;
      tmp->origin.z = tmp_spot->origin.z;
      tmp->next = tmp_scene->spot_list;
      tmp_scene->spot_list = tmp;
      tmp_spot = tmp_spot->next;
    }
  return (0);
}

int		fill_eye(t_scene *tmp_scene, t_scene *tmp)
{
  t_eye		*tmp2;
  t_eye		*tmp_eye;

  if ((tmp_scene->eye = malloc(sizeof(t_eye *) * 100)) == NULL)
    return (-1);
  if (tmp->eye != NULL)
    {
      tmp_scene->eye->pos.x = tmp->eye->pos.x;
      tmp_scene->eye->pos.y = tmp->eye->pos.y;
      tmp_scene->eye->pos.z = tmp->eye->pos.z;
      tmp_scene->eye->dir.x = tmp->eye->dir.x;
      tmp_scene->eye->dir.y = tmp->eye->dir.y;
      tmp_scene->eye->dir.z = tmp->eye->dir.z;
      tmp_scene->eye->distance = tmp->eye->distance;
      tmp_scene->eye->next = NULL;
      tmp_eye = tmp->eye->next;
      while (tmp_eye != NULL)
	{
	  if ((tmp2 = malloc(sizeof(t_eye *) * 100)) == NULL)
	    return (-1);
	  tmp2->pos.x = tmp_eye->pos.x;
	  tmp2->pos.y = tmp_eye->pos.y;
	  tmp2->pos.z = tmp_eye->pos.z;
	  tmp2->dir.x = tmp_eye->dir.x;
	  tmp2->dir.y = tmp_eye->dir.y;
	  tmp2->dir.z = tmp_eye->dir.z;
	  tmp2->distance = tmp_eye->distance;
	  tmp2->next = tmp_scene->eye;
	  tmp_scene->eye = tmp2;
	  tmp_eye = tmp_eye->next;
	}
    }
  return (0);
}

int		fill_img(t_scene *tmp_scene, t_image *tmp_image, int i)
{
  t_image	*tmp;
  t_image	*save;

  if ((tmp_scene->img = malloc(sizeof(t_image *) * 100)) == NULL)
    return (-1);
  tmp_scene->img->img = tmp_image->img;
  tmp_scene->img->dat = tmp_image->dat;
  tmp_scene->img->bpp = tmp_image->bpp;
  tmp_scene->img->wdth = tmp_image->wdth;
  tmp_scene->img->hght = tmp_image->hght;
  tmp_scene->img->edn = tmp_image->edn;
  tmp_scene->img->i_tab = tmp_image->i_tab;
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
  tmp_scene->img->render_method = tmp_image->render_method;
  tmp_scene->img->next = tmp_scene->img;
  tmp_scene->img->prev = tmp_scene->img;
  save = tmp_image->next;
  while (save != tmp_image)
    {
      if ((tmp = malloc(sizeof(t_image *) * 100)) == NULL)
	return (-1);
      tmp->i_tab = tmp_image->i_tab;
      tmp->img = tmp_image->img;
      tmp->dat = tmp_image->dat;
      tmp->bpp = tmp_image->bpp;
      tmp->wdth = tmp_image->wdth;
      tmp->hght = tmp_image->hght;
      tmp->edn = tmp_image->edn;
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
      tmp_scene->img->render_method = tmp_image->render_method;
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

void    launch_scene(t_system *sys, t_scene *scene, int nb)
{
  t_scene	*copy;

  scene->act_image = scene->img;
  scene->act_eye = scene->eye;
  copy = init_scene();
  copy_list(scene, copy, NULL);
  copy = copy->next;
  copy->act_image = copy->img;
  copy->act_eye = copy->eye;
  scene->act_image = scene->img;
  scene->act_eye = scene->eye;
  while (scene->act_eye != NULL)
    {
      nb = omp_get_thread_num();
      printf("nb = %d\n", nb);
      printf("a\n");
      if (nb == 0)
	{
	  load_image(copy, get_vector2(0, 0),
		     get_vector2(960, 540));
	}
      else if (nb == 1)
	{
	  load_image(copy, get_vector2(0, 540),
		     get_vector2(960, 540));
	}
      else if (nb == 2)
	{
	  load_image(copy, get_vector2(960, 0),
		     get_vector2(960, 540));
	}
      else if (nb == 3)
	{
	  load_image(copy, get_vector2(960, 540),
		     get_vector2(960, 540));
	}
      #pragma omp barrier
      #pragma omp master
      {
        if (scene->act_image->render_method == &antialias_method)
          resolve_effects(scene->act_image, scene,
                          &resolve_antialiased_color);
        else if (scene->act_image->render_method == &cell_shade_method)
          resolve_effects(scene->act_image, scene, &resolve_cell_shading);
        //get_border(scene);
        mlx_put_image_to_window(sys->mlx, sys->wdw,
                                scene->act_image->img, 0, 0);
	if (scene->act_eye != NULL && scene->act_image != NULL)
	  {
            scene->act_eye = scene->act_eye->next;
            scene->act_image = scene->act_image->next;
          }
      }
     #pragma omp barrier
    }
}

void            loading_time(t_system *sys)
{
  t_scene       *scene;
   int		nb_t;
  int		nb;

#pragma omp parallel private(nb)
  {
   nb = 0;
   launch_scene(sys, sys->scene_list, nb);
#pragma omp master
    {
      nb_t = omp_get_num_threads();
      printf("Nombre de thread dispo: %d\n", nb_t);
    }
   scene = sys->scene_list->next;
    //duplicate_obj(sys->scene_list->obj_list, sys->scene_list->img->bpp);
    while (scene != sys->scene_list)
      {
  printf("pass2\n");
  launch_scene(sys, scene, nb);
       #pragma omp barrier
       #pragma omp master
 	 {
	   if (scene != NULL)
	     scene = scene->next;
	 }
       #pragma omp barrier
     }
  }
}
