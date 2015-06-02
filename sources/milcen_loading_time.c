/*
** loading_time.c for function for the load of each eyes in each scenes in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Sat May 30 20:46:53 2015 quentin gasparotto
** Last update Tue Jun  2 17:15:44 2015 adrien milcent
*/

#include <omp.h>
#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

void		loading_time(t_system *sys)
{
  t_scene	*scene;
  int   nb_t = 0;
  int	nb = 0;

  #pragma omp parallel private(nb)
  {
   scene = sys->scene_list;
   nb = 0;
   #pragma omp master
    {
      nb_t = omp_get_num_threads();
      printf("Nombre de thread dispo: %d\n", nb_t);
    }
   while (scene != NULL)
    {
      scene->act_image = scene->img;
      scene->act_eye = scene->eye;
      while (scene->act_image != NULL)
	{
          nb = omp_get_thread_num();
	  if (nb == 0)
	    {
	      scene->obj_list = duplicate_obj(scene->obj_list, scene->act_image->bpp);
	      load_image(scene, get_vector2(0, 0),
			 get_vector2(960, 540));
	    }
	  else if (nb == 1)
	    {
	      scene->obj_list = duplicate_obj(scene->obj_list, scene->act_image->bpp);
	      load_image(scene, get_vector2(0, 540),
			 get_vector2(960, 540));
	    }
	  else if (omp_get_thread_num() == 2)
	    {
	      scene->obj_list = duplicate_obj(scene->obj_list, scene->act_image->bpp);
	      load_image(scene, get_vector2(960, 0),
			 get_vector2(960, 540));
	    }
	  else if (omp_get_thread_num() == 3)
	    {
	      scene->obj_list = duplicate_obj(scene->obj_list, scene->act_image->bpp);
	      load_image(scene, get_vector2(960, 540),
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
	    mlx_put_image_to_window(sys->mlx, sys->wdw, scene->act_image->img, 0, 0);
	    if (scene->act_eye != NULL && scene->act_image != NULL)
	      {
	        scene->act_eye = scene->act_eye->next;
	        scene->act_image = scene->act_image->next;
              }
	  }
         #pragma omp barrier
	}
      #pragma omp barrier
      #pragma omp master
	{
          if (scene != NULL)
	    scene = scene->next;
	}
      #pragma omp barrier
    }
   #pragma omp barrier
  }
  printf("LEL\n");
}