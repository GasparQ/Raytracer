/*
** add_obj.c for add an obj to obj list in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Feb 25 10:03:48 2015 quentin gasparotto
** Last update Wed Jun  3 19:46:42 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void		add_object(t_object **obj_list, int size, int color)
{
  t_object	new_obj;

  if (size > 0 && (new_obj.disp_color = malloc(size)) == NULL)
    exit(my_strerror(MALLOC_ERR));
  if (size > 0 && (new_obj.color1 = malloc(size)) == NULL)
    exit(my_strerror(MALLOC_ERR));
  if (size > 0 && (new_obj.color2 = malloc(size)) == NULL)
    exit(my_strerror(MALLOC_ERR));
  new_obj.obj_color = color;
  new_obj.origin = ORIGIN;
  new_obj.rotation = ORIGIN;
  add_phong(&new_obj, (double [8]){0.2, 1, 0, 0, 0, 0, 0, 0});
  new_obj.limit = NULL;
  new_obj.apply_texture = NULL;
  new_obj.texture = NULL;
  new_obj.proced = NULL;
  new_obj.bump = NULL;
  new_obj.apply_texture = &basic_color;
  my_put_in_list(obj_list, new_obj);
}
