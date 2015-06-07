/*
** parse_limit_scene.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer/parser
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sat May 30 20:42:10 2015 fernand veyrier
** Last update Sun Jun  7 10:44:17 2015 fernand veyrier
*/

#include "get_next_line.h"

int		parse_limit(t_system *sys, t_parser *pars)
{
  t_object	*save;

  if (pars->level < 1)
    return (ERR_PARSER("limit"));
  save = sys->scene_list->obj_list;
  sys->scene_list->obj_list = sys->scene_list->obj_list->limit;
  follow_pattern(pars, sys);
  save->limit = sys->scene_list->obj_list;
  sys->scene_list->obj_list = save;
  return (pars->buf == NULL ? ERR_PARSER("limit") : 5);
}

int		parse_limit_close(UNUSED t_system *sys, t_parser *pars)
{
  if (pars->level - 5 < 1)
    return (fprintf(stderr, "Invalid XML (limit) line %i.\n",
		    pars->line) * -1);
  return (-5);
}

int		parse_scene(t_system *sys, t_parser *pars)
{
  if (pars->level != 0)
    return (fprintf(stderr, "Invalid XML (scene) line %i.\n",
		    pars->line) * -1);
  add_scene(&sys->scene_list, sys->mlx);
  return (1);
}

int		parse_scene_close(UNUSED t_system *sys, t_parser *pars)
{
  if (pars->level - 1 != 0)
    return (fprintf(stderr, "Invalid XML (spot) line %i.\n",
		    pars->line) * -1);
  return (-1);
}

int		parse_mesh_close(UNUSED t_system *sys, t_parser *pars)
{
  if (pars->level - 2 < 2)
    return (fprintf(stderr, "Invalid XML (mesh) line %i.\n", pars->line) * -1);
  return (-2);
}
