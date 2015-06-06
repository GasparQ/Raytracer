/*
** loading_time.c for function for the load of each eyes in each scenes in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Sat May 30 20:46:53 2015 quentin gasparotto
** Last update Sat Jun  6 19:28:57 2015 quentin gasparotto
*/

#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

double contrast[9] = {0, -1, 0, -1, 10, -1, 0, -1, 0};
double flou[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
double around[9] = {0, 10, 0, 10, -40, 10, 0, 10, 0};
double push_it[9] = {-2, -1, 0, -1, 1, 1, 0, 1, 2};
double board_it[9] = {0, 0, 0, -255, 255, 0, 0, 0, 0};
double normal[9] = {0, 0, 0, 0, -1, 0, 0, 0, 0};
double anti_flou[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
double sobel[9] = {-1, 2, 1, -2, 0, 2, -1, 2, 1};

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
      apply_filter(scene->act_image, scene);
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
