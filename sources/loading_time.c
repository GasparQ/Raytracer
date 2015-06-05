/*
** loading_time.c for function for the load of each eyes in each scenes in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Sat May 30 20:46:53 2015 quentin gasparotto
** Last update Fri Jun  5 14:06:46 2015 quentin gasparotto
*/

#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

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
      mlx_put_image_to_window(sys->mlx, sys->wdw,
			      scene->act_image->img, 0, 0);
      scene->act_eye = scene->act_eye->next;
      scene->act_image = scene->act_image->next;
    }
}

void		loading_time(t_system *sys)
{
  t_scene	*scene;

  scene = sys->scene_list->next;
  launch_scene(sys, sys->scene_list);
  //duplicate_obj(sys->scene_list->obj_list, sys->scene_list->img->bpp);
  while (scene != sys->scene_list)
    {
      launch_scene(sys, scene);
      scene = scene->next;
    }
}
