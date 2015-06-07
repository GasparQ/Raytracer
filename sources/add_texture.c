/*
** add_texture.c for function for adding a texture to an object in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Jun  3 11:06:10 2015 quentin gasparotto
** Last update Sun Jun  7 14:45:38 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int	add_texture(t_object *obj, char *filename, t_scene *scene)
{
  if (filename != NULL)
    {
      if ((obj->texture = malloc(sizeof(*obj->texture))) == NULL)
	return (-1);
      if (load_texture(obj->texture, filename, scene->mlx) == -1)
	return (-1);
      if ((obj->texture->color = malloc(obj->texture->bpp / 8)) == NULL)
	return (-1);
    }
  return (0);
}

int	add_bump(t_object *obj, char *filename, t_scene *scene, int mode)
{
  if (filename != NULL)
    {
      if ((obj->bump = malloc(sizeof(*obj->bump))) == NULL)
	return (-1);
      if (load_texture(obj->bump, filename, scene->mlx) == -1)
	return (-1);
      if ((obj->bump->color = malloc(obj->bump->bpp / 8)) == NULL)
	return (-1);
      obj->which_bump = (mode == 0) ? &height_map_bump : &bump_map_bump;
    }
  return (0);
}

int	add_proced(t_object *obj, char *filename, t_scene *scene, int *color)
{
  int	size;

  if (filename != NULL)
    {
      if ((obj->proced = malloc(sizeof(*obj->proced))) == NULL)
	return (-1);
      if (load_texture(obj->proced, filename, scene->mlx) == -1)
	return (-1);
      size = obj->proced->bpp / 8;
      if ((obj->proced->color = malloc(size)) == NULL)
	return (-1);
      if ((obj->color1 = malloc(size)) == NULL)
	return (-1);
      if ((obj->color2 = malloc(size)) == NULL)
	return (-1);
      scene->act_image = obj->proced;
      get_color(color[0], obj->color1, scene);
      get_color(color[1], obj->color2, scene);
    }
  return (0);
}
