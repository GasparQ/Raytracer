/*
** parse_spot.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer/parser
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sat May 30 20:40:54 2015 fernand veyrier
** Last update Sun May 31 13:54:09 2015 fernand veyrier
*/

#include "get_next_line.h"

int		parse_spot(t_system *sys, t_parser *pars)
{
  t_vector3	pos;
  int		color;
  int		intensity;

  if (pars->level != 1)
    return (fprintf(stderr, "Invalid XML (spot) line %i.\n", pars->line) * -1);
  printf("Found spot\n");
  pos.x = 0;
  pos.y = 0;
  pos.y = 0;
  color = 0;
  intensity = 0;
  while ((pars->buf = get_next_line(pars->fd))
	 && regexec(&pars->regex[12], pars->buf, 0, &pars->reg_struct, 0))
    {
      if (!regexec(&pars->regex[18], pars->buf, 0, &pars->reg_struct, 0))
	pos = get_vector(pars->buf);
      if (!regexec(&pars->regex[19], pars->buf, 0, &pars->reg_struct, 0))
	color = get_color_parser(pars->buf);
      if (!regexec(&pars->regex[21], pars->buf, 0, &pars->reg_struct, 0))
	intensity = get_nbr_parser(pars->buf);
    }
  add_spot(sys->scene_list, pos, color, intensity);
  return ((pars->buf == NULL) ? -30 : 0);
}

int		parse_spot_close(UNUSED t_system *sys, t_parser *pars)
{
  if (pars->level - 6 != 1)
    return (fprintf(stderr, "Invalid XML (spot) line %i.\n", pars->line) * -1);
  printf("Found spot close\n");
  return (-6);
}
