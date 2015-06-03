/*
** add_texture.c for function for adding a texture to an object in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Jun  3 11:06:10 2015 quentin gasparotto
** Last update Wed Jun  3 11:43:50 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int	add_texture(t_object *obj, char *filename, void *mlx)
{
  if ((obj->texture = malloc(sizeof(*obj->texture))) == NULL)
    return (-1);
  load_texture(obj->texture, filename, mlx);
  return (0);
}
