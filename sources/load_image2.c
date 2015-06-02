/*
** load_image.c for load the image in /home/gaspar_q/rendu/Igraph/MUL_2014_rtv1/sources
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Tue Feb  3 16:42:37 2015 quentin gasparotto
** Last update Tue Jun  2 17:28:39 2015 adrien milcent
*/

#include <omp.h>
#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

int	load_image(t_scene *scene, t_vector2 pos, t_vector2 dim)
{
  int	x;
  int	y;
  int	i;
  int	nb;

  #pragma omp parallel
  {
    #pragma omp barrier
    #pragma omp critical
    {
      nb = omp_get_thread_num();
    }
    /*    if (nb == 0)
      {
	printf("0, thread %d\n", nb);
	scene->obj_list = duplicate_obj(scene->obj_list, scene->act_image->bpp);
      }
    else if (nb == 1)
      {
	printf("1, thread %d\n", nb);
	scene->obj_list = duplicate_obj(scene->obj_list, scene->act_image->bpp);
      }
    else if (nb == 2)
      {
	printf("2, thread %d\n", nb);
	scene->obj_list = duplicate_obj(scene->obj_list, scene->act_image->bpp);
      }
    else if (nb == 3)
      {
	printf("3, thread %d\n", nb);
	scene->obj_list = duplicate_obj(scene->obj_list, scene->act_image->bpp);
	}*/
    #pragma omp for schedule(dynamic) private(x)
    for (y = 0; y < WDW_HEIGHT; y++)
      {
	for (x = 0; x < WDW_WIDTH; x++)
	  {
            disp_color(scene, x, y);
    	  }
	if (y % 200 == 0)
	  printf("%d / %d\n", y, WDW_HEIGHT);
      }
  }
  return (CLEAN);
}
