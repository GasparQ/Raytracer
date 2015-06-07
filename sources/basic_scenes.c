/*
** basic_scenes.c for function for the loading of basic_scenes in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sun Jun  7 14:10:17 2015 quentin gasparotto
** Last update Sun Jun  7 15:33:26 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int		init_spot(t_system *sys)
{
  sys->scene_list->spot_list = NULL;
  if (add_spot(sys->scene_list, get_vector3(-100.0, 100.0, 150.0),
	       WHITE, 1) == ERROR)
    return (ERROR);
  if (add_spot(sys->scene_list, get_vector3(-500.0, 0.0, 500.0),
	       WHITE, 1) == ERROR)
    return (ERROR);
  sys->scene_list->spot_nb = get_spot_nb(sys->scene_list->spot_list);
  return (CLEAN);
}

void		init_objects(t_system *sys)
{
  sys->scene_list->obj_list = NULL;
  add_object(&sys->scene_list->obj_list, sys->scene_list->img->bpp / 8, WHITE);
  add_plan(sys->scene_list->obj_list, (double [4]){0.0, 0.0, 0.0, 1.0});
  add_object(&sys->scene_list->obj_list, sys->scene_list->img->bpp / 8, RED);
  add_coord(sys->scene_list->obj_list, (double [6]){0, 0, 50, 0, 0, 0});
  add_phong(sys->scene_list->obj_list,
	    (double [8]){0.2, 1, 1, 400, 0, 0, 0, 0});
  add_sphere(sys->scene_list->obj_list, (double [1]){100});
  add_object(&sys->scene_list->obj_list->limit,
	     sys->scene_list->img->bpp / 8, GREEN);
  add_coord(sys->scene_list->obj_list->limit,
	    (double [6]){-75, -75, 175, 0, 0, 0});
  add_sphere(sys->scene_list->obj_list->limit, (double [1]){50});
  add_object(&sys->scene_list->obj_list, sys->scene_list->img->bpp / 8, BLUE);
  add_coord(sys->scene_list->obj_list, (double [6]){-100, 100, 30, 0, 0, 0});
  add_phong(sys->scene_list->obj_list,
	    (double [8]){0.2, 1, 1, 400, 0, 0.2, 1.12, 0});
  add_sphere(sys->scene_list->obj_list, (double [1]){75});
  add_object(&sys->scene_list->obj_list, sys->scene_list->img->bpp / 8, WHITE);
  add_coord(sys->scene_list->obj_list, (double [6]){150, 0, 300, 0, 0, 0});
  add_phong(sys->scene_list->obj_list,
	    (double [8]){0.2, 1, 1, 400, 0, 0, 1, 0.7});
  add_sphere(sys->scene_list->obj_list, (double [1]){150});
}

void	test_texture(t_system *sys)
{
  sys->scene_list->obj_list = NULL;
  add_object(&sys->scene_list->obj_list, sys->scene_list->img->bpp / 8, RED);
  add_coord(sys->scene_list->obj_list, (double [6]){-100, 0, 150, 0, 0, 45});
  add_sphere(sys->scene_list->obj_list, (double [1]){150});
  add_texture(sys->scene_list->obj_list, "images/earth_for_bump.xpm",
  	      sys->scene_list);
  add_bump(sys->scene_list->obj_list, "images/bump_earth.xpm",
  	   sys->scene_list, 0);
  add_object(&sys->scene_list->obj_list, sys->scene_list->img->bpp / 8, WHITE);
  add_plan(sys->scene_list->obj_list, (double [4]){0, 0, 0, 1});
  add_bump(sys->scene_list->obj_list, "images/bump_map_test.xpm",
  	   sys->scene_list, 1);
  add_object(&sys->scene_list->obj_list, sys->scene_list->img->bpp / 8, WHITE);
  add_cylinder(sys->scene_list->obj_list, (double [1]){75});
  add_coord(sys->scene_list->obj_list, (double [6]){0, -100, 0, 0, 0, 0});
  add_bump(sys->scene_list->obj_list, "images/wb.xpm", sys->scene_list, 1);
}

int	basic_scene(t_system *sys)
{
  if (add_scene(&sys->scene_list, sys->mlx) == -1)
    return (-1);
  if (add_eye(sys->scene_list, get_vector3(-500, 0, 150),
	      ORIGIN, (double [12]){500, 2, 0, 0, 0, 0, 1,
		  0, 0, 0, 0, 3}) == -1)
    return (-1);
  init_objects(sys);
  init_spot(sys);
  sys->scene_list->act_eye = sys->scene_list->eye;
  sys->scene_list->act_image = sys->scene_list->img;
  if (add_scene(&sys->scene_list, sys->mlx) == -1)
    return (-1);
  if (add_eye(sys->scene_list, get_vector3(-500, 0, 150),
	      ORIGIN, (double [12]){500, 2, 0, 0, 0, 0, 1,
		  0, 0, 0, 0, 0}) == -1)
    return (-1);
  test_texture(sys);
  init_spot(sys);
  sys->scene_list->act_eye = sys->scene_list->eye;
  sys->scene_list->act_image = sys->scene_list->img;
  return (0);
}
