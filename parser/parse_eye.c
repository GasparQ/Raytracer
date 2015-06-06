/*
** parse_eye.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer/parser
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sat May 30 20:37:02 2015 fernand veyrier
** Last update Sat Jun  6 23:27:34 2015 fernand veyrier
*/

#include "get_next_line.h"

void		parse_matrix(char *buf, double *matrix)
{
  int		i;
  int		j;
  int		k;
  char		nbr[BUFSIZ];

  i = -1;
  j = 0;
  k = 2;
  while (buf[++i])
    {
      while (j < BUFSIZ - 1 && buf[i] && buf[i] != ',')
	nbr[j++] = buf[i++];
      nbr[j] = 0;
      matrix[k++] = atof(nbr);
      j = 0;
    }
}

int		parse_eye(t_system *sys, t_parser *pars)
{
  t_vector3	pos;
  t_vector3	rot;
  double	dist_render[12];

  dist_render[0] = 0;
  dist_render[1] = 2;
  dist_render[2] = 0;
  dist_render[3] = 0;
  dist_render[4] = 0;
  dist_render[5] = 0;
  dist_render[6] = 1;
  dist_render[7] = 0;
  dist_render[8] = 0;
  dist_render[9] = 0;
  dist_render[10] = 0;
  dist_render[11] = 0;
  pos = (t_vector3){0, 0, 0};
  rot = (t_vector3){0, 0, 0};
  if (pars->level != 1)
    return (ERR_PARSER("eye"));
  while ((pars->buf = get_next_line(pars->fd))
	 && regexec(&pars->regex[16], pars->buf, 0, &pars->reg_struct, 0))
    {
      if (!regexec(&pars->regex[20], pars->buf, 0, &pars->reg_struct, 0))
	pos = get_vector(pars->buf);
      if (!regexec(&pars->regex[19], pars->buf, 0, &pars->reg_struct, 0))
	rot = get_vector(pars->buf);
      if (!regexec(&pars->regex[22], pars->buf, 0, &pars->reg_struct, 0))
	dist_render[0] = get_double_parser(pars->buf);
      if (!regexec(&pars->regex[24], pars->buf, 0, &pars->reg_struct, 0))
	dist_render[1] = get_double_parser(pars->buf);
      if (!regexec(&pars->regex[25], pars->buf, 0, &pars->reg_struct, 0))
	parse_matrix(pars->buf, dist_render);
      if (!regexec(&pars->regex[26], pars->buf, 0, &pars->reg_struct, 0))
	dist_render[11] = get_double_parser(pars->buf);
      ++pars->line;
    }
  add_eye(sys->scene_list, pos, rot, dist_render);
  return ((pars->buf == NULL) ? ERR_PARSER("eye") : 0);
}

int		parse_eye_close(UNUSED t_system *sys, t_parser *pars)
{
  if (pars->level - 10 != 1)
    return (fprintf(stderr, "Invalid XML (eye) line %i.\n", pars->line) * -1);
  return (-10);
}
