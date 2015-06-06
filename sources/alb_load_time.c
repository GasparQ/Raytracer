/*
** loading_time.c for function for the load of each eyes in each scenes in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Sat May 30 20:46:53 2015 quentin gasparotto
** Last update Sat Jun  6 17:30:41 2015 Alban Combaud
*/

#include <omp.h>
#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

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
