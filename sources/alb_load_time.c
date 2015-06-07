/*
** loading_time.c for function for the load of each eyes in each scenes in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Sat May 30 20:46:53 2015 quentin gasparotto
** Last update Sun Jun  7 23:31:58 2015 quentin gasparotto
*/

#include <omp.h>
#include <pthread.h>
#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

int	g_percent = 0;

void		*output_load(void *sys)
{
  int		nb_per;
  t_system	*sys1;

  sys1 = (t_system *)sys;
  while (g_percent <= 100)
    {
      nb_per = g_percent / 10;
      mlx_put_image_to_window(sys1->mlx, sys1->wdw,
			      sys1->load[nb_per].img,
			      (WDW_WIDTH / 2) - 240, (WDW_HEIGHT / 2) - 240);
    }
  g_percent = 0;
  pthread_exit(NULL);
}

void		launch_scene(t_system *sys, t_scene *copy, int nb, int nb_t)
{
  while (copy->act_eye != NULL)
    {
      nb = omp_get_thread_num();
      load_my_image(nb, nb_t, copy);
      #pragma omp barrier
      #pragma omp single
      {
        if (copy->act_image->render_method == &antialias_method)
          resolve_effects(copy->act_image, copy,
                          &resolve_antialiased_color);
        else if (copy->act_image->render_method == &cell_shade_method)
          resolve_effects(copy->act_image, copy, &resolve_cell_shading);
	apply_filter(copy->act_image, copy);
        mlx_put_image_to_window(sys->mlx, sys->wdw,
                                copy->act_image->img, 0, 0);
      }
      if (copy->act_eye != NULL && copy->act_image != NULL)
	{
	  copy->act_eye = copy->act_eye->next;
	  copy->act_image = copy->act_image->next;
	}
    }
}

void		loading_screen(int nb_t)
{
  static int	nb_thread = 0;

  if (nb_thread == 0)
    nb_thread = nb_t;
  else
    {
      g_percent = g_percent + (20 / nb_thread);
    }
}

void	sig_1()
{
  loading_screen(-1);
}

void		loading_time(t_system *sys)
{
  pthread_t	t1;
  t_scene	*scene;
  t_scene	*copy;
  int		nb_t;
  int		nb;

  signal(SIGUSR1, sig_1);
  pthread_create(&t1, NULL, output_load, (void *)sys);
  #pragma omp parallel private(nb) private(copy) private(scene)
  {
   nb = 0;
   loading_screen(omp_get_num_threads());
   nb_t = omp_get_num_threads();
   copy = duplicate_scene(sys->scene_list);
   launch_scene(sys, copy, nb, nb_t);
   scene = copy->next;
   while (scene != copy)
     {
       #pragma omp barrier
       launch_scene(sys, scene, nb, nb_t);
       if (scene != NULL)
	 scene = scene->next;
     }
  }
  pthread_cancel(t1);
}
