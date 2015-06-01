/*
** parse_limit_scene.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer/parser
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sat May 30 20:42:10 2015 fernand veyrier
** Last update Mon Jun  1 18:01:05 2015 quentin gasparotto
*/

#include "get_next_line.h"

int		parse_limit(t_system *sys, t_parser *pars)
{
  t_object	*save;

  if (pars->level < 1)
    return (fprintf(stderr, "Invalid XML (limit) line %i.\n", pars->line) * -1);
  /* save = pars->act_list; */
  /* pars->act_list = pars->act_list->limit; */
  /* follow_patern(pars, sys); */
  /* pars->act_list = save; */
  printf("Found limit\n");
  return (5);
}

int		parse_limit_close(UNUSED t_system *sys, t_parser *pars)
{
  if (pars->level - 5 < 1)
    return (fprintf(stderr, "Invalid XML (limit) line %i.\n", pars->line) * -1);
  printf("Found limit close\n");
  return (-5);
}

int		parse_scene(t_system *sys, t_parser *pars)
{
  if (pars->level != 0)
    return (fprintf(stderr, "Invalid XML (scene) line %i.\n", pars->line) * -1);
  printf("Found scene\n");
  add_scene(&sys->scene_list, sys->mlx);
  return (1);
}

int		parse_scene_close(UNUSED t_system *sys, t_parser *pars)
{
  if (pars->level - 1 != 0)
    return (fprintf(stderr, "Invalid XML (spot) line %i.\n", pars->line) * -1);
  printf("Found scene close\n");
  return (-1);
}
