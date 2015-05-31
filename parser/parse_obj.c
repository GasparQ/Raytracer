/*
** parse_obj.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer/parser
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sat May 30 20:44:32 2015 fernand veyrier
** Last update Sun May 31 14:33:00 2015 fernand veyrier
*/

#include "get_next_line.h"

int		parse_obj(t_system *sys, t_parser *pars)
{
  int		color;

  if (pars->level < 1)
    return (fprintf(stderr, "Invalid XML (obj) line %i.\n", pars->line) * -1);
  color = get_color_parser(pars->buf);
  printf("Found obj\n");
  add_object(&sys->scene_list->obj_list, color, (sys->scene_list->img == NULL ?
  					     4 : sys->scene_list->img->bpp / 8));
  return (11);
}

int		parse_obj_close(UNUSED t_system *sys, t_parser *pars)
{
  if (pars->level - 11 < 1)
    return (fprintf(stderr, "Invalid XML (obj) line %i.\n", pars->line) * -1);
  printf("Found obj close\n");
  return (-11);
}
