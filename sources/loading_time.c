/*
** loading_time.c for function for the load of each eyes in each scenes in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Sat May 30 20:46:53 2015 quentin gasparotto
** Last update Tue Jun  2 14:09:36 2015 adrien milcent
*/

#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

void		loading_time(t_system *sys)
{
  t_scene	*scene;

  scene = sys->scene_list;
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
}
