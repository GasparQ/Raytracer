/*
** loading_time.c for function for the load of each eyes in each scenes in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sat May 30 20:46:53 2015 quentin gasparotto
** Last update Sun May 31 18:18:45 2015 quentin gasparotto
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
	    antialiasing(scene->act_image, scene);
	  scene->act_eye = scene->act_eye->next;
	  scene->act_image = scene->act_image->next;
	}
      scene = scene->next;
    }
}
