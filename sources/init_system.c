/*
** init_system.c for system initialisation in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Tue Feb 10 20:01:49 2015 quentin gasparotto
** Last update Mon Jun  1 22:54:12 2015 quentin gasparotto
*/

#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

int	init_mlx(t_system *sys)
{
  if ((sys->mlx = mlx_init()) == NULL)
    return (my_strerror(MLX_FAIL));
  sys->wdw = mlx_new_window(sys->mlx, WDW_WIDTH, WDW_HEIGHT, "rtv1");
  if (sys->wdw == NULL)
    return (my_strerror(WDW_FAIL));
  return (CLEAN);
}

void		init_objects(t_system *sys)
{
  sys->scene_list->obj_list = NULL;
  add_object(&sys->scene_list->obj_list, sys->scene_list->img->bpp / 8, WHITE);
  add_plan(sys->scene_list->obj_list, (double [4]){0.0, 0.0, 0.0, 1.0});
  add_object(&sys->scene_list->obj_list, sys->scene_list->img->bpp / 8, RED);
  add_coord(sys->scene_list->obj_list, (double [6]){0, 0, 150, 0, 0, 0});
  add_phong(sys->scene_list->obj_list,
	    (double [8]){0.2, 1, 1, 400, 0, 0, 0, 0});
  add_sphere(sys->scene_list->obj_list, (double [1]){100});
  add_object(&sys->scene_list->obj_list->limit,
	     sys->scene_list->img->bpp / 8, GREEN);
  add_coord(sys->scene_list->obj_list->limit,
	    (double [6]){-75, -75, 175, 0, 0, 0});
  add_sphere(sys->scene_list->obj_list->limit, (double [1]){50});
  add_object(&sys->scene_list->obj_list, sys->scene_list->img->bpp / 8, BLUE);
  add_coord(sys->scene_list->obj_list, (double [6]){-100, 100, 80, 0, 0, 0});
  add_phong(sys->scene_list->obj_list,
	    (double [8]){0.2, 1, 1, 400, 0, 0.6, 1.02, 0});
  add_sphere(sys->scene_list->obj_list, (double [1]){75});
}

int		init_spot(t_system *sys)
{
  sys->scene_list->spot_list = NULL;
  if (add_spot(sys->scene_list, get_vector3(-200.0, -200.0, 500.0),
	       WHITE, 0.6) == ERROR)
    return (ERROR);
  if (add_spot(sys->scene_list, get_vector3(-200.0, 200.0, 500.0),
	       BLUE, 0.1) == ERROR)
    return (ERROR);
  sys->scene_list->spot_nb = get_spot_nb(sys->scene_list->spot_list);
  return (CLEAN);
}

int	init_system(t_system *sys, char *file)
{
  if (init_mlx(sys) == ERROR)
    return (ERROR);
  sys->scene_list = NULL;
  if (file == NULL)
    {
      if (add_scene(&sys->scene_list, sys->mlx) == -1)
	return (-1);
      if (add_eye(sys->scene_list, get_vector3(-600, 0, 150),
		  ORIGIN, (double [2]){500, 0}) == -1)
	return (-1);
      if (add_eye(sys->scene_list, get_vector3(-600, 0, 150),
		  ORIGIN, (double [2]){500, 1}) == -1)
	return (-1);
      if (add_eye(sys->scene_list, get_vector3(-600, 0, 150),
		  ORIGIN, (double [2]){500, 2}) == -1)
	return (-1);
      sys->scene_list->act_eye = sys->scene_list->eye;
      sys->scene_list->act_image = sys->scene_list->img;
      init_objects(sys);
      init_spot(sys);
    }
  else if (get_objects(sys, file) != 0)
    return (-1);
  return (CLEAN);
}
