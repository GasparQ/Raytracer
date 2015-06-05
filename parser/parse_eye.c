/*
** parse_eye.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer/parser
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sat May 30 20:37:02 2015 fernand veyrier
** Last update Fri Jun  5 14:53:16 2015 fernand veyrier
*/

#include "get_next_line.h"

int		parse_eye(t_system *sys, t_parser *pars)
{
  t_vector3	pos;
  t_vector3	rot;
  double	dist_render[2];

  dist_render[0] = 0;
  dist_render[1] = 2;
  pos = (t_vector3){0, 0, 0};
  rot = (t_vector3){0, 0, 0};
  if (pars->level != 1)
    return (fprintf(stderr, "Invalid XML (eye) line %i.\n", pars->line) * -1);
  printf("Found eye pos\n");
  while ((pars->buf = get_next_line(pars->fd))
	 && regexec(&pars->regex[16], pars->buf, 0, &pars->reg_struct, 0))
    {
      if (!regexec(&pars->regex[18], pars->buf, 0, &pars->reg_struct, 0))
	pos = get_vector(pars->buf);
      if (!regexec(&pars->regex[17], pars->buf, 0, &pars->reg_struct, 0))
	rot = get_vector(pars->buf);
      if (!regexec(&pars->regex[20], pars->buf, 0, &pars->reg_struct, 0))
	dist_render[0] = get_double_parser(pars->buf);
      if (!regexec(&pars->regex[22], pars->buf, 0, &pars->reg_struct, 0))
	dist_render[1] = get_double_parser(pars->buf);
    }
  add_eye(sys->scene_list, pos, rot, dist_render);
  return ((pars->buf == NULL) ? -30 : 0);
}

int		parse_eye_close(UNUSED t_system *sys, t_parser *pars)
{
  if (pars->level - 10 != 1)
    return (fprintf(stderr, "Invalid XML (eye) line %i.\n", pars->line) * -1);
  printf("Found eye close\n");
  return (-10);
}
