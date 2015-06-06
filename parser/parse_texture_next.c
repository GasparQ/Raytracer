/*
** parse_texture_next.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sat Jun  6 11:23:17 2015 fernand veyrier
** Last update Sat Jun  6 11:23:56 2015 fernand veyrier
*/

#include "get_next_line.h"

void		get_name(t_parser *pars, char *file)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (pars->buf[i] && pars->buf[i] != '"')
    ++i;
  ++i;
  while (i < BUFSIZ - 1 && pars->buf[i] && pars->buf[i] != '"')
    file[j++] = pars->buf[i++];
  file[j] = 0;
}

int		parse_texture_map(t_system *sys, t_parser *pars)
{
  char		file[BUFSIZ];
  regex_t	regex;

  if (regcomp(&regex, "[[:space:]]*file[[:space:]]*=[[:space:]]*\".*\"\
[[:space:]]*$", REG_EXTENDED))
    return (fprintf(stderr, "Regex error\n"));
  file[0] = 0;
  while ((pars->buf = get_next_line(pars->fd))
	 && regexec(&pars->regex[18], pars->buf, 0, &pars->reg_struct, 0))
    {
      if (!regexec(&regex, pars->buf, 0, &pars->reg_struct, 0))
	{
	  get_name(pars, file);
	}
    }
  return (add_texture(sys->scene_list->obj_list, file, sys->scene_list));
}

int		parse_texture_bump(t_system *sys, t_parser *pars)
{
  int		mode;
  char		file[BUFSIZ];
  regex_t	regex[2];

  if (regcomp(&regex[0], "[[:space:]]*file[[:space:]]*=[[:space:]]*\".*\"\
[[:space:]]*$", REG_EXTENDED))
    return (fprintf(stderr, "Regex error\n"));
  if (regcomp(&regex[1], "[[:space:]]*bump[[:space:]]*=[[:space:]]*\
[[:digit:].]+[[:space:]]*$", REG_EXTENDED))
    return (fprintf(stderr, "Regex error\n"));
  mode = 0;
  file[0] = 0;
  while ((pars->buf = get_next_line(pars->fd))
	 && regexec(&pars->regex[18], pars->buf, 0, &pars->reg_struct, 0))
    {
      if (!regexec(&regex[0], pars->buf, 0, &pars->reg_struct, 0))
	get_name(pars, file);
      if (!regexec(&regex[1], pars->buf, 0, &pars->reg_struct, 0))
	mode = get_nbr_parser(pars->buf);
    }
  return (add_bump(sys->scene_list->obj_list, file, sys->scene_list, mode));
}
