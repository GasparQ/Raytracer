/*
** parse_texture.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Fri Jun  5 15:32:58 2015 fernand veyrier
** Last update Sat Jun  6 14:23:40 2015 fernand veyrier
*/

#include "get_next_line.h"

int		parse_texture_procedural(t_system *sys, t_parser *pars)
{
  int		color[2];
  char		file[BUFSIZ];
  regex_t	regex[3];

  if (regcomp(&regex[0], "[[:space:]]*file[[:space:]]*=[[:space:]]*\".*\"\
[[:space:]]*$", REG_EXTENDED)
      || regcomp(&regex[1], "[[:space:]]*color_one[[:space:]]*=[[:space:]]*\
0x[[:digit:]A-F]{,8}[[:space:]]*$", REG_EXTENDED)
      || regcomp(&regex[2], "[[:space:]]*color_two[[:space:]]*=[[:space:]]*\
0x[[:digit:]A-F]{,8}[[:space:]]*$", REG_EXTENDED))
    return (fprintf(stderr, "Regex error\n"));
  file[color[color[0] = 1] = 0] = 0;
  while ((pars->buf = get_next_line(pars->fd))
	 && regexec(&pars->regex[18], pars->buf, 0, &pars->reg_struct, 0))
    {
      if (!regexec(&regex[0], pars->buf, 0, &pars->reg_struct, 0))
	get_name(pars, file);
      if (!regexec(&regex[1], pars->buf, 0, &pars->reg_struct, 0))
	color[0] = get_color_parser(pars->buf);
      if (!regexec(&regex[2], pars->buf, 0, &pars->reg_struct, 0))
	color[1] = get_color_parser(pars->buf);
      ++pars->line;
    }
  return (add_proced(sys->scene_list->obj_list, file, sys->scene_list, color));
}

void		parse_texture_init(char **type_list, int (**func)())
{
  type_list[0] = "map";
  type_list[1] = "bump";
  type_list[2] = "procedural";
  func[0] = parse_texture_map;
  func[1] = parse_texture_bump;
  func[2] = parse_texture_procedural;
}

int		parse_texture(t_system *sys, t_parser *pars)
{
  char		type[BUFSIZ];
  char		*type_list[3];
  int		(*func[3])();
  int		i;
  int		j;

  i = 0;
  j = 0;
  parse_texture_init(type_list, func);
  if (pars->level < 2)
    return (fprintf(stderr, "Invalid XML (texture) line %i.\n",
		    pars->line) * -1);
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
      return (fprintf(stderr, "Invalid data (texture file valid ?)\n") * -1);
  return (pars->buf == NULL ? ERR_PARSER("texture") : 0);
}

int		parse_texture_close(UNUSED t_system *sys, t_parser *pars)
{
  if (pars->level - 12 < 1)
    return (fprintf(stderr, "Invalid XML (texture) line %i.\n",
		    pars->line) * -1);
  return (-12);
}
