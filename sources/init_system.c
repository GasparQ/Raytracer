/*
** init_system.c for system initialisation in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Feb 10 20:01:49 2015 quentin gasparotto
** Last update Thu Mar 19 18:09:41 2015 quentin gasparotto
*/

#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

void	init_img(t_image *img, void *mlx, int wid, int hei)
{
  int	bpp;
  int	endian;
  int	width;

  img->img = mlx_new_image(mlx, wid, hei);
  img->dat = mlx_get_data_addr(img->img, &bpp, &width, &endian);
  img->bpp = bpp;
  img->edn = endian;
  img->wdth = width;
  img->hght = hei * wid * (bpp / 8) / img->wdth;
}

int	init_mlx(t_system *sys)
{
  if ((sys->mlx = mlx_init()) == NULL)
    return (my_strerror(MLX_FAIL));
  sys->wdw = mlx_new_window(sys->mlx, WDW_WIDTH, WDW_HEIGHT, "rtv1");
  if (sys->wdw == NULL)
    return (my_strerror(WDW_FAIL));
  init_img(&(sys->img), sys->mlx, WDW_WIDTH, WDW_HEIGHT);
  init_img(&(sys->load), sys->mlx, 20, 20);
  return (CLEAN);
}

void		init_objects(t_system *sys)
{
  t_vector3	limit[2];

  sys->obj_list = NULL;
  add_object(sys, get_vector3(-160, -100, 20), ORIGIN, SIMPLE);
  add_sphere(sys, 20.0, BOLAS);
  add_object(sys, get_vector3(-200, -20, 20), ORIGIN, SIMPLE);
  add_sphere(sys, 20.0, BOLAS);
  add_object(sys, get_vector3(-160, -60, 20), ORIGIN, SIMPLE);
  add_sphere(sys, 20.0, BOLAS);
  add_object(sys, get_vector3(-120, -100, 20), ORIGIN, SIMPLE);
  add_sphere(sys, 20.0, BOLAS);
  add_object(sys, get_vector3(100, 0, 0), get_vector3(0, -70, 0), SIMPLE);
  add_plan(sys, WHITE, 0.0, get_vector3(0, 0, 1));
  add_object(sys, ORIGIN, ORIGIN, get_properties(0, 0, 0.6));
  add_plan(sys, SOLAS, 0.0, get_vector3(0, 0, 1));
  add_object(sys, get_vector3(-100, 350, 50), get_vector3(90, 0, -60), SIMPLE);
  add_cylinder(sys, 50.0, YELLOW, get_limit(limit, get_vector3(0, 0, -100),
  					 get_vector3(0, 0, 100)));
  add_object(sys, get_vector3(-40, 80, 0), get_vector3(103, 0, 0), SIMPLE);
  add_cone(sys, 50.0, CONAS, get_limit(limit, get_vector3(0, 0, -200), ORIGIN)
);
  add_object(sys, get_vector3(-50, 150, 100), get_vector3(180, 0, 0), SIMPLE);
  add_paraboloid(sys, 20.0, PARAB);
}

int		init_spot(t_system *sys)
{
  sys->spot_list = NULL;
  if (add_spot(sys, get_vector3(-500.0, 0.0, 1000.0), WHITE) == ERROR)
    return (ERROR);
  if (add_spot(sys, get_vector3(-100.0, 100.0, 0.0), WHITE) == ERROR)
    return (ERROR);
  if (add_spot(sys, get_vector3(-100.0, -150.0, 50.0), WHITE) == ERROR)
    return (ERROR);
  if (add_spot(sys, get_vector3(-100.0, 0.0, 0.0), WHITE) == ERROR)
    return (ERROR);
  sys->spot_nb = get_spot_nb(sys);
  return (CLEAN);
}

int	init_system(t_system *sys)
{
  if (init_mlx(sys) == ERROR)
    return (ERROR);
  init_objects(sys);
  init_spot(sys);
  if ((sys->color = malloc(sys->img.bpp / 8)) == NULL)
    return (my_strerror(MALLOC_ERR));
  if ((sys->average = malloc(sizeof(int) * sys->img.bpp / 8)) == NULL)
    return (my_strerror(MALLOC_ERR));
  init_load_img(sys, &sys->load);
  sys->eye.pos.x = -500.0;
  sys->eye.pos.y = 0.0;
  sys->eye.pos.z = 10.0;
  sys->eye.distance = 500;
  sys->eye.dir.x = 0.0;
  sys->eye.dir.y = 0.0;
  sys->eye.dir.z = 10.0;
  get_color(BLACK, sys->color, sys);
  return (CLEAN);
}
