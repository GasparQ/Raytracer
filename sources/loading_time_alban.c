/*
** loading_time.c for function for the load of each eyes in each scenes in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Sat May 30 20:46:53 2015 quentin gasparotto
** Last update Fri Jun  5 14:23:05 2015 Alban Combaud
*/

#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

void	copy_list(t_scene *, t_scene *, t_scene *);

int		my_strlen_unsigned(unsigned char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void		copy_list(t_scene *scene, t_scene *new, t_scene *tmp)
{
  t_scene	*tmp_scene;
  t_spot	*tmp_spot;
  int		i;

  tmp_scene = NULL;
  tmp = scene->next;
  while (tmp != scene)
    {
      tmp_scene = malloc(sizeof(t_scene *) * 100);
      tmp_spot = tmp->spot_list;
      while (tmp_spot != NULL)
	{
	  i = 0;
	  tmp_scene->spot_list->color = malloc(my_strlen_unsigned(tmp_spot->color) * sizeof(char *));
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
	}
      tmp_scene->spot_nb = tmp->spot_nb;
      tmp_scene->obj_list = duplicate_obj(tmp->obj_list, tmp->img->bpp);
      tmp_scene->eye->pos.x = tmp->eye->pos.x;
      tmp_scene->eye->pos.y = tmp->eye->pos.y;
      tmp_scene->eye->pos.z = tmp->eye->pos.z;
      tmp_scene->eye->dir.x = tmp->eye->dir.x;
      tmp_scene->eye->dir.y = tmp->eye->dir.y;
      tmp_scene->eye->dir.z = tmp->eye->dir.z;
      tmp_scene->prev = new;
      tmp_scene->next = new->next;
      new->next->prev = tmp_scene;
      new->next = tmp_scene;
      tmp = tmp->next;
    }
}

t_scene		*init_scene(void)
{
  t_scene	*tmp;

  tmp = malloc(sizeof(t_scene *));
  tmp->prev = tmp;
  tmp->next = tmp;
  return (tmp);
}

void		loading_time(t_system *sys)
{
  t_scene	*scene;
  t_scene	*copy;

  scene = sys->scene_list;
  //duplicate_obj(sys->scene_list->obj_list, sys->scene_list->img->bpp);
  while (scene != NULL)
    {
      scene->act_image = scene->img;
      scene->act_eye = scene->eye;
      while (scene->act_image != NULL)
	{
	  load_image(scene, get_vector2(0, 0),
		     get_vector2(WDW_WIDTH, WDW_HEIGHT));
	  if (scene->act_image->render_method == &antialias_method)
	    resolve_effects(scene->act_image, scene,
	  		    &resolve_antialiased_color);
	  else if (scene->act_image->render_method == &cell_shade_method)
	    resolve_effects(scene->act_image, scene, &resolve_cell_shading);
	  mlx_put_image_to_window(sys->mlx, sys->wdw,
				  scene->act_image->img, 0, 0);
	  scene->act_eye = scene->act_eye->next;
	  scene->act_image = scene->act_image->next;
	}
      scene = scene->next;
    }
  scene = sys->scene_list;
  copy = init_scene();
  copy_list(scene, copy, NULL);
  scene = copy->next;
  printf("work\n");
  while (copy != scene)
    {
      printf("copy_spot = %f\n", copy->spot_list->i);
      copy = copy->next;
    }
}
