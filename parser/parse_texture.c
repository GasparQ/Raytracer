/*
** parse_texture.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Fri Jun  5 15:32:58 2015 fernand veyrier
** Last update Fri Jun  5 17:53:18 2015 fernand veyrier
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

int		parse_texture_procedural(t_system *sys, t_parser *pars)
{
  int		colors[2];

  printf("parsing procedural\n");
  //return (add_proced(sys->scene_list->obj_list, file, sys->scene_list, colors));
}

int		parse_texture(t_system *sys, t_parser *pars)
{
  char		type[BUFSIZ];
  char		*type_list[3];
  int		(*func[8])();
  int		i;
  int		j;

  i = 0;
  j = 0;
  type_list[0] = "map";
  type_list[1] = "bump";
  type_list[2] = "procedural";
  func[0] = parse_texture_map;
  func[1] = parse_texture_bump;
  func[2] = parse_texture_procedural;
  if (pars->level < 2)
    return (fprintf(stderr, "Invalid XML (texture) line %i.\n", pars->line) * -1);
  printf("Found texture\n");
  while (pars->buf[i] && pars->buf[i] != '"')
    ++i;
  ++i;
  while (i < BUFSIZ - 1 && pars->buf[i] && pars->buf[i] != '"')
    type[j++] = pars->buf[i++];
  type[j] = 0;
  i = 0;
  while (i < 3 && strncmp(type_list[i], type, strlen(type_list[i]) - 1))
    ++i;
  if (i < 3)
    if (func[i](sys, pars) != CLEAN)
      return (-30);
  return (pars->buf == NULL ? -30 : 0);
}

int		parse_texture_close(UNUSED t_system *sys, t_parser *pars)
{
  if (pars->level - 12 < 1)
    return (fprintf(stderr, "Invalid XML (texture) line %i.\n", pars->line) * -1);
  printf("Found texture close\n");
  return (-12);
}
