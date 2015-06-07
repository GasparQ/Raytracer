/*
** loading_time.c for function for the load of each eyes in each scenes in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Sat May 30 20:46:53 2015 quentin gasparotto
** Last update Sun Jun  7 13:16:30 2015 adrien milcent
*/

#include <omp.h>
#include <pthread.h>
#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

void	check_max(int *x, int *y, int max)
{
  if (*x <= max && *y <= max)
    {
      if (*x == max)
	{
	  ++(*y);
	  *x = 0;
	}
      else
	++(*x);
    }
}

void	load_my_image(int nb, int nb_t, t_scene *copy)
{
  int	width;
  int	height;
  int	max;
  int	x;
  int	y;
  int	i;

  i = 0;
  x = 0;
  y = 0;
  max = (nb_t / 2) - 1;
  while (i != nb && i < nb_t)
    {
      check_max(&x, &y, max);
      ++i;
    }
  width = x * (WDW_WIDTH / (nb_t / 2));
  height = y * (WDW_HEIGHT / 2);
  load_image(copy, get_vector2(width, height),
	     get_vector2(WDW_WIDTH / (nb_t / 2), WDW_HEIGHT / 2));
}

void	copy_scene(t_scene **copy, t_scene **scene)
{
  (*scene)->act_image = (*scene)->img;
  (*scene)->act_eye = (*scene)->eye;
  (*copy) = init_scene();
  copy_list(*scene, *copy, NULL);
  (*copy) = (*copy)->next;
  (*copy)->act_image = (*copy)->img;
  (*copy)->act_eye = (*copy)->eye;
  (*scene)->act_image = (*scene)->img;
  (*scene)->act_eye = (*scene)->eye;
}

void		launch_scene(t_system *sys, t_scene *scene, int nb, int nb_t)
{
  t_scene	*copy;

  copy_scene(&copy, &scene);
  while (scene->act_eye != NULL)
    {
      nb = omp_get_thread_num();
      load_my_image(nb, nb_t, copy);
      #pragma omp barrier
      #pragma omp single
      {
        if (scene->act_image->render_method == &antialias_method)
          resolve_effects(scene->act_image, scene,
                          &resolve_antialiased_color);
        else if (scene->act_image->render_method == &cell_shade_method)
          resolve_effects(scene->act_image, scene, &resolve_cell_shading);
	apply_filter(scene->act_image, scene);
        mlx_put_image_to_window(sys->mlx, sys->wdw,
                                scene->act_image->img, 0, 0);
	if (scene->act_eye != NULL && scene->act_image != NULL)
	  {
            scene->act_eye = scene->act_eye->next;
            scene->act_image = scene->act_image->next;
          }
      }
    }
}

void	*loading_screen()
{
  int	i;

  i = 0;
  while (i < 100000)
    {
      printf("salut\n");
      ++i;
    }
  printf("finito\n");
  pthread_exit(NULL);
}

void		loading_time(t_system *sys)
{
  t_scene	*scene;
  pthread_t	t1;
  int		nb_t;
  int		nb;

  pthread_create(&t1, NULL, loading_screen, NULL);
  #pragma omp parallel private(nb)
  {
   nb = 0;
   nb_t = omp_get_num_threads();
   launch_scene(sys, sys->scene_list, nb, nb_t);
   scene = sys->scene_list->next;
   while (scene != sys->scene_list)
     {
       launch_scene(sys, scene, nb, nb_t);
       #pragma omp barrier
       #pragma omp single
       {
	 if (scene != NULL)
	   scene = scene->next;
       }
     }
  }
}
