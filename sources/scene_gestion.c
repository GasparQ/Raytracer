/*
** scene_gestion.c for function for the scene gestion in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Fri May 29 11:09:31 2015 quentin gasparotto
** Last update Sat Jun  6 19:25:39 2015 quentin gasparotto
*/

#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

static void (*filters[4])(t_image *, t_vector2, void *) = {&get_coeff,
							   &sepia,
							   &black_n_white,
							   &revert};

int		init_img(t_image *img, t_vector2 dim, t_scene *scene, int render)
{
  int		bpp;
  int		endian;
  int		width;
  t_image	*save;

  img->img = mlx_new_image(scene->mlx, dim.x, dim.y);
  img->dat = mlx_get_data_addr(img->img, &bpp, &width, &endian);
  img->bpp = bpp;
  img->edn = endian;
  img->wdth = width;
  img->hght = dim.x * dim.y * (bpp / 8) / img->wdth;
  img->next = NULL;
  if ((img->i_tab = malloc(sizeof(double) * img->wdth / 4 * img->hght)) == NULL)
    return (-1);
  if ((img->color = malloc(bpp / 8)) == NULL)
    return (-1);
  save = scene->act_image;
  scene->act_image = img;
  get_color(BLACK, img->color, scene);
  scene->act_image = save;
  if ((img->average = malloc(sizeof(int) * (bpp / 8))) == NULL)
    return (-1);
  img->render_method =
    (render == 0) ? &antialias_method :
    ((render == 1) ? &cell_shade_method : &basic_method);
  return (0);
}

int		add_image(t_scene *scene, int render)
{
  t_image	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  if (init_img(elem, get_vector2(WDW_WIDTH, WDW_HEIGHT), scene, render) == -1)
    return (-1);
  scene->act_image = elem;
  if (scene->img != NULL)
    {
      elem->next = scene->img;
      elem->prev = scene->img->prev;
      elem->prev->next = elem;
      scene->img->prev = elem;
    }
  else
    {
      elem->prev = elem;
      elem->next = elem;
    }
  scene->img = elem;
  return (0);
}

int	add_eye(t_scene *scene, t_vector3 position,
		t_vector3 rotation, double *prop)
{
  t_eye	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  elem->pos = position;
  elem->dir = rotation;
  elem->distance = prop[0];
  elem->next = scene->eye;
  scene->eye = elem;
  if (add_image(scene, (int)prop[1]) == -1)
    return (-1);
  elem->convolution[0] = prop[2];
  elem->convolution[1] = prop[3];
  elem->convolution[2] = prop[4];
  elem->convolution[3] = prop[5];
  elem->convolution[4] = prop[6];
  elem->convolution[5] = prop[7];
  elem->convolution[6] = prop[8];
  elem->convolution[7] = prop[9];
  elem->convolution[8] = prop[10];
  elem->filter_meth = filters[(prop[11] < 4) ? (int)prop[11] : 0];
  return (0);
}

int		add_scene(t_scene **scene, void *mlx)
{
  t_scene	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (my_strerror("Malloc err\n"));
  elem->spot_list = NULL;
  elem->spot_nb = 0;
  elem->obj_list = NULL;
  elem->eye = NULL;
  elem->img = NULL;
  elem->mlx = mlx;
  if (*scene != NULL)
    {
      elem->next = *scene;
      elem->prev = (*scene)->prev;
      elem->prev->next = elem;
      (*scene)->prev = elem;
    }
  else
    {
      elem->prev = elem;
      elem->next = elem;
    }
  *scene = elem;
  return (0);
}

void		free_scene(t_scene *scene)
{
  t_scene	*tmp;

  if (scene->prev != scene)
    scene->prev->next = NULL;
  else
    scene->next = NULL;
  while (scene != NULL)
    {
      tmp = scene->next;
      free_my_list(scene->obj_list);
      free_spot_list(scene->spot_list);
      free_image_list(scene->img);
      free(scene);
      scene = tmp;
    }
}
