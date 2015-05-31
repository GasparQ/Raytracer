/*
** parse_phong.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer/parser
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sat May 30 20:39:37 2015 fernand veyrier
** Last update Sun May 31 14:32:00 2015 fernand veyrier
*/

#include "get_next_line.h"

int		parse_phong(t_system *sys, t_parser *pars)
{
  double	params[10];
  regex_t	regex[8];
  int		i;

  i = 0;
  while (i < 10)
    params[i++] = 0;
  i = 0;
  if (pars->level < 1)
    return (fprintf(stderr, "Invalid XML (phong) line %i.\n", pars->line) * -1);
  printf("Found phong\n");
  if (regcomp(&regex[0], AMB_REG NBR_REG, REG_EXTENDED)
      || regcomp(&regex[1], DIF_REG NBR_REG, REG_EXTENDED)
      || regcomp(&regex[2], SPEC_REG NBR_REG, REG_EXTENDED)
      || regcomp(&regex[3], SPEC_RAD_REG NBR_REG, REG_EXTENDED)
      || regcomp(&regex[4], BRIGHT_REG NBR_REG, REG_EXTENDED)
      || regcomp(&regex[5], OPAC_REG NBR_REG, REG_EXTENDED)
      || regcomp(&regex[6], REFRAC_REG NBR_REG, REG_EXTENDED)
      || regcomp(&regex[7], REFLEC_REG NBR_REG, REG_EXTENDED))
    return (fprintf(stderr, "Error in regex\n") * -1);
  while ((pars->buf = get_next_line(pars->fd))
	 && regexec(&pars->regex[8], pars->buf, 0, &pars->reg_struct, 0))
    {
      while (i < 8 && regexec(&regex[i], pars->buf, 0, &pars->reg_struct, 0))
	++i;
      if (i < 8)
	params[i] = get_double_parser(pars->buf);
      i = 0;
    }
  add_phong(sys->scene_list->obj_list, params);
  return ((pars->buf == NULL) ? -30 : 0);
}

int		parse_phong_close(UNUSED t_system *sys, t_parser *pars)
{
  if (pars->level - 4 < 1)
    return (fprintf(stderr, "Invalid XML (phong) line %i.\n", pars->line) * -1);
  printf("Found phong close\n");
  return (-4);
}
