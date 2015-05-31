/*
** init_system.c for system initialisation in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Feb 10 20:01:49 2015 quentin gasparotto
** Last update Sun May 31 18:53:00 2015 quentin gasparotto
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


  /*
  **	Ajout hyperboloide
  */

  /* add_object(&sys->scene_list->obj_list, sys->scene_list->img->bpp / 8, YELLOW); */

  /* add_coord(sys->scene_list->obj_list, (double [6]){0, 0, 10, 45, 45, 0}); */
  /* add_holed_cube(sys->scene_list->obj_list, (double [2]){10.0, 42.8}); */

  /* add_coord(sys->scene_list->obj_list, (double [6]){100, 0, 200, 90, 0, 0}); */
  /* add_hyperboloid(sys->scene_list->obj_list, (double [5]){50, 50, 90, -1, -1}); */

  /*
  **		Limite l'hyperboloide
  */

  /* add_object(&sys->scene_list->obj_list->limit, sys->scene_list->img->bpp / 8, YELLOW); */
  /* add_coord(sys->scene_list->obj_list->limit, (double [6]){100, 0, 200, 90, 0, 0}); */

  /* add_sphere(sys->scene_list->obj_list->limit, (double [1]){50}); */

  /* add_plan(sys->scene_list->obj_list->limit, (double [4]){0.0, 0.0, 0.0, 1.0}); */

  /*
  **	Ajout plan
  */

  add_object(&sys->scene_list->obj_list, sys->scene_list->img->bpp / 8, WHITE);
  add_plan(sys->scene_list->obj_list, (double [4]){0.0, 0.0, 0.0, 1.0});
 
  /* /\* add_object((t_vector3 [2]){get_vector3(0, 0, 1000), ORIGIN}, *\/ */
  /* /\* 	     (int [2]){sys->img.bpp / 8, RED}, *\/ */
  /* /\* 	     get_properties(0, 0.5, 0.8, 1), &sys->obj_list); *\/ */
  /* /\* add_cone(sys->obj_list, (double [1]){180.0}); *\/ */

  /* add_object((t_vector3 [2]){ORIGIN, ORIGIN}, */
  /* 	     (int [2]){sys->scene_list->img->bpp / 8, RED}, */
  /* 	     SIMPLE, &sys->scene_list->obj_list); */

  /* add_object(&sys->scene_list->obj_list, sys->scene_list->img->bpp / 8, RED); */
  /* add_moebius(sys->scene_list->obj_list, (double [3]){0, 2, 0}); */

  add_object(&sys->scene_list->obj_list, sys->scene_list->img->bpp / 8, RED);
  add_coord(sys->scene_list->obj_list, (double [6]){0, 0, 100, 0, 90, 0});
  add_phong(sys->scene_list->obj_list, (double [8]){0.2, 1, 1, 200, 0, 0, 0, 0});
  add_sphere(sys->scene_list->obj_list, (double [1]){50});

  add_object(&sys->scene_list->obj_list, sys->scene_list->img->bpp / 8, RED);
  add_coord(sys->scene_list->obj_list, (double [6]){150, 100, 100, 0, 90, 0});
  add_phong(sys->scene_list->obj_list, (double [8]){0.2, 1, 1, 50, 0, 0.4, 1.02, 0.5});
  add_sphere(sys->scene_list->obj_list, (double [1]){100});

  /* add_object(&sys->scene_list->obj_list, sys->scene_list->img->bpp / 8, RED); */
  /* add_coord(sys->scene_list->obj_list, (double [6]){0, 0, 100, 0, 90, 0}); */
  /* add_phong(sys->scene_list->obj_list, (double [7]){0, 0, 0, 0, 0.5, 1.5, 0}); */
  /* add_plan(sys->scene_list->obj_list, (double [4]){0.0, 0.0, 0.0, 1.0}); */

  /* add_object(&(sys->scene_list->obj_list->limit), sys->scene_list->img->bpp / 8, RED); */
  /* add_coord(sys->scene_list->obj_list->limit, (double [6]){0, 50, 0, 90, 0, 0}); */
  /* add_plan(sys->scene_list->obj_list->limit, (double [4]){0.0, 0.0, 0.0, 1.0}); */

  /* add_object(&(sys->scene_list->obj_list->limit), sys->scene_list->img->bpp / 8, RED); */
  /* add_coord(sys->scene_list->obj_list->limit, (double [6]){0, -50, 0, 90, 0, 0}); */
  /* add_plan(sys->scene_list->obj_list->limit, (double [4]){0.0, 0.0, 0.0, 1.0}); */

  /* add_object(&(sys->scene_list->obj_list), sys->scene_list->img->bpp / 8, YELLOW); */
  /* add_coord(sys->scene_list->obj_list, (double [6]){60, 0, 100, 90, 0, 0}); */
  /* add_cylinder(sys->scene_list->obj_list, (double [1]){50.0}); */

  /* add_object(&(sys->scene_list->obj_list->limit), sys->scene_list->img->bpp / 8, RED); */
  /* add_coord(sys->scene_list->obj_list->limit, (double [6]){0, 50, 0, 90, 0, 225}); */
  /* add_plan(sys->scene_list->obj_list->limit, (double [4]){0.0, 0.0, 0.0, 1.0}); */

  /* //add_paraboloid(sys->obj_list, (double [1]){20.0}); */
  /* //add_cone(sys->obj_list, (double [1]){120}); */
  /* //add_cylinder(sys->obj_list, (double [1]){10.0}); */
  /* //add_tore(sys->obj_list, (double [2]){25, 50}); */
  /* //add_sphere(sys->obj_list, (double [1]){100}); */
  //add_tore(sys->obj_list, (double [2]){25, 50});

  /* add_object((t_vector3 [2]){ORIGIN, ORIGIN}, */
  /* 	     (int [2]){sys->img.bpp / 8, BOLAS}, */
  /* 	     SIMPLE, &sys->obj_list); */
  /* add_tore(sys, 25, 50, RED); */
  /* add_object(sys, get_vector3(0, 0, 75), get_vector3(0, 90, -45), SIMPLE/\* get_properties(0, 0.5, 0, 1.33) *\/); */
  /* add_tore(sys, 25, 50, RED); */
  /* add_limit(sys, get_vector3(0, 50, 150), ORIGIN, SIMPLE); */
  /* add_lim_sphere(sys, 100.0, BOLAS); */
  /* add_holed_cube(sys, 100.0, RED); */
  /* add_object(sys, get_vector3(30, 0, 50), ORIGIN, SIMPLE); */
  /* add_sphere(sys, 50.0, BOLAS); */
  /* add_object(sys, get_vector3(140, -150, 100), get_vector3(0, 0, 0), get_properties(0, 0, 0.5, 1)); */
  /* add_cylinder(sys, 100.0, YELLOW, get_limit(limit, get_vector3(0, 0, -100), */
  /* 					     get_vector3(0, 0, 100))); */

  /* add_object(sys, get_vector3(-200, -20, 20), ORIGIN, SIMPLE); */
  /* add_sphere(sys, 20.0, BOLAS); */
  /* add_object(sys, get_vector3(-160, -60, 20), ORIGIN, SIMPLE); */
  /* add_sphere(sys, 20.0, BOLAS); */
  /* add_object(sys, get_vector3(-120, -100, 20), ORIGIN, SIMPLE); */
  /* add_sphere(sys, 20.0, BOLAS); */
/*   add_object(sys, get_vector3(100, 0, 0), get_vector3(0, -70, 0), SIMPLE); */
/*   add_plan(sys, WHITE, 0.0, get_vector3(0, 0, 1)); */
/*   add_object(sys, ORIGIN, ORIGIN, get_properties(0, 0, 0.6)); */
/*   add_plan(sys, SOLAS, 0.0, get_vector3(0, 0, 1)); */
/*   add_object(sys, get_vector3(-100, 350, 50), get_vector3(90, 0, -60), SIMPLE); */
/*   add_cylinder(sys, 50.0, YELLOW, get_limit(limit, get_vector3(0, 0, -100), */
/*   					 get_vector3(0, 0, 100))); */
  /* add_object(sys, get_vector3(0, 0, 1000), ORIGIN, get_properties(0, 0, 0.5, 1)); */
  /* add_cone(sys, 120.0, CONAS, get_limit(limit, get_vector3(0, 0, -1000), ORIGIN)); */
/*   add_object(sys, get_vector3(-50, 150, 100), get_vector3(180, 0, 0), SIMPLE); */
/*   add_paraboloid(sys, 20.0, PARAB); */
}

int		init_spot(t_system *sys)
{
  sys->scene_list->spot_list = NULL;
  /* if (add_spot(sys, get_vector3(-500.0, 0.0, 1000.0), WHITE) == ERROR) */
  /*   return (ERROR); */
  /* if (add_spot(sys, get_vector3(-100.0, 100.0, 0.0), WHITE) == ERROR) */
  /*   return (ERROR); */
  /* if (add_spot(sys, get_vector3(-100.0, -150.0, 50.0), WHITE) == ERROR) */
  /*   return (ERROR); */
  /* if (add_spot(sys, get_vector3(-100.0, 0.0, 0.0), WHITE) == ERROR) */
  /*   return (ERROR); */
  /* if (add_spot(sys, get_vector3(0.0, 0.0, 500.0), WHITE) == ERROR) */
  /*   return (ERROR); */
  /* if (add_spot(sys, get_vector3(-500.0, 0.0, 500.0), WHITE) == ERROR) */
  /*   return (ERROR); */
  /* if (add_spot(sys, get_vector3(-100.0, 100.0, 200.0), WHITE) == ERROR) */
  /*   return (ERROR); */
  /* if (add_spot(sys, get_vector3(-100.0, 500.0, 500.0), WHITE) == ERROR) */
  /*   return (ERROR); */
  /* if (add_spot(sys, get_vector3(-1000.0, 1000.0, 300.0), WHITE) == ERROR) */
  /*   return (ERROR); */
  if (add_spot(sys->scene_list, get_vector3(-200.0, 500.0, 200.0), WHITE, 1) == ERROR)
    return (ERROR);
  if (add_spot(sys->scene_list, get_vector3(-200.0, -500.0, 200.0), WHITE, 1) == ERROR)
    return (ERROR);
  /* if (add_spot(sys->scene_list, get_vector3(-200.0, -550.0, 200.0), WHITE, 1) == ERROR) */
  /*   return (ERROR); */
  sys->scene_list->spot_nb = get_spot_nb(sys->scene_list->spot_list);
  return (CLEAN);
}

int	init_system(t_system *sys, char *file)
{
  if (init_mlx(sys) == ERROR)
    return (ERROR);
  sys->scene_list = NULL;
  if (add_scene(&sys->scene_list, sys->mlx) == -1)
    return (-1);
  if (add_eye(sys->scene_list, get_vector3(-500, 0, 150), ORIGIN, (double [2]){500, 1}) == -1)
    return (-1);
  /* if (add_eye(sys->scene_list, get_vector3(-100, 0, 10), ORIGIN, 500) == -1) */
  /*   return (-1); */
  /* if (add_eye(sys->scene_list, get_vector3(-5, 0, 5), ORIGIN, 500) == -1) */
  /*   return (-1); */
  sys->scene_list->act_eye = sys->scene_list->eye;
  sys->scene_list->act_image = sys->scene_list->img;
  if (file == NULL)
    init_objects(sys);
  else if (get_objects(sys, file) != 0)
    return (-1);
  init_spot(sys);
  /* if ((sys->color = malloc(sys->img.bpp / 8)) == NULL) */
  /*   return (my_strerror(MALLOC_ERR)); */
  /* if ((sys->average = malloc(sizeof(int) * sys->img.bpp / 8)) == NULL) */
  /*   return (my_strerror(MALLOC_ERR)); */
  /* init_load_img(sys, &sys->load); */
  /* sys->eye.pos.x = -500.0; */
  /* sys->eye.pos.y = 0.0; */
  /* sys->eye.pos.z = 250.0; */
  /* sys->eye.distance = 500; */
  /* sys->eye.dir.x = 0.0; */
  /* sys->eye.dir.y = 0.0; */
  /* sys->eye.dir.z = 0.0; */
  return (CLEAN);
}
