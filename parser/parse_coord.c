/*
** parse_coord.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer/parser
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sat May 30 20:43:10 2015 fernand veyrier
** Last update Sat May 30 20:43:29 2015 fernand veyrier
*/

#include "get_next_line.h"

int		parse_coord(t_system *sys, t_parser *pars)
{
  t_vector3	pos;
  t_vector3	rot;
  double	coord[6];

  if (pars->level < 1)
    return (fprintf(stderr, "Invalid XML (coord) line %i.\n", pars->line) * -1);
  printf("Found coord\n");
  while ((pars->buf = get_next_line(pars->fd))
	 && regexec(&pars->regex[6], pars->buf, 0, &pars->reg_struct, 0))
    {
      if (!regexec(&pars->regex[18], pars->buf, 0, &pars->reg_struct, 0))
	pos = get_vector(pars->buf);
      if (!regexec(&pars->regex[17], pars->buf, 0, &pars->reg_struct, 0))
	rot = get_vector(pars->buf);
    }
  coord[0] = pos.x;
  coord[1] = pos.y;
  coord[2] = pos.z;
  coord[3] = rot.x;
  coord[4] = rot.y;
  coord[5] = rot.z;
  //add_coord(&sys->scene_list->obj_list, coord);
  return ((pars->buf == NULL) ? -30 : 0);
}

int		parse_coord_close(t_system *sys, t_parser *pars)
{
  if (pars->level - 3 < 1)
    return (fprintf(stderr, "Invalid XML (coord) line %i.\n", pars->line) * -1);
  printf("Found coord close\n");
  return (-3);
}