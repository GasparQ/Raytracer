/*
** scene_gestion.c for function for the scene gestion in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Fri May 29 11:09:31 2015 quentin gasparotto
** Last update Sat May 30 11:24:03 2015 quentin gasparotto
*/

#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

int	init_img(t_image *img, t_vector2 dim, t_scene *scene)
{
  int	bpp;
  int	endian;
  int	width;

  img->img = mlx_new_image(scene->mlx, dim.x, dim.y);
  img->dat = mlx_get_data_addr(img->img, &bpp, &width, &endian);
  img->bpp = bpp;
  img->edn = endian;
  img->wdth = width;
  img->hght = dim.x * dim.y * (bpp / 8) / img->wdth;
  img->next = NULL;
  if ((img->color = malloc(bpp / 8)) == NULL)
    return (-1);
  scene->act_image = img;
  get_color(BLACK, img->color, scene);
  if ((img->average = malloc(sizeof(int) * (bpp / 8))) == NULL)
    return (-1);
  return (0);
}

int		add_image(t_scene *scene)
{
  t_image	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  if (init_img(elem, get_vector2(WDW_WIDTH, WDW_HEIGHT), scene) == -1)
    return (-1);
  elem->next = scene->img;
  scene->img = elem;
  return (0);
}

int	add_eye(t_scene *scene, t_vector3 position,
		t_vector3 rotation, int distance)
{
  t_eye	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  elem->pos = position;
  elem->dir = rotation;
  elem->distance = distance;
  elem->next = scene->eye;
  scene->eye = elem;
  if (add_image(scene) == -1)
    return (-1);
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
  elem->next = *scene;
  *scene = elem;
  return (0);
}

void		free_scene(t_scene *scene)
{
  t_scene	*tmp;

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
