/*
** parse_mesh.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer/parser
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sat May 30 20:46:43 2015 fernand veyrier
** Last update Sat Jun  6 11:20:17 2015 fernand veyrier
*/

#include "get_next_line.h"

int		mesh_cylinder(t_system *sys, t_parser *pars)
{
  double	radius;
  regex_t	regex;

  radius = 0;
  if (regcomp(&regex, "[[:space:]]*radius[[:space:]]*\
=[[:space:]]*[[:digit:].]+[[:space:]]*$", REG_EXTENDED))
    return (fprintf(stderr, "Regex error\n"));
  while ((pars->buf = get_next_line(pars->fd))
	 && regexec(&pars->regex[4], pars->buf, 0, &pars->reg_struct, 0))
    {
      if (!regexec(&regex, pars->buf, 0, &pars->reg_struct, 0))
	radius = get_double_parser(pars->buf);
    }
  return (add_cylinder(sys->scene_list->obj_list, &radius));
}

int		mesh_paraboloid(t_system *sys, t_parser *pars)
{
  double	radius;
  regex_t	regex;

  radius = 0;
  if (regcomp(&regex, "[[:space:]]*cte[[:space:]]*\
=[[:space:]]*[[:digit:].]+[[:space:]]*$", REG_EXTENDED))
    return (fprintf(stderr, "Regex error\n"));
  while ((pars->buf = get_next_line(pars->fd))
	 && regexec(&pars->regex[4], pars->buf, 0, &pars->reg_struct, 0))
    {
      if (!regexec(&regex, pars->buf, 0, &pars->reg_struct, 0))
	radius = get_double_parser(pars->buf);
    }
  return (add_paraboloid(sys->scene_list->obj_list, &radius));
}

int		mesh_hyperboloid(t_system *sys, t_parser *pars)
{
  double	params[5];
  int		i;
  regex_t	regex[5];

  i = 0;
  while (i < 5)
    params[i++] = 0;
  if (regcomp(&regex[0], HYPER_PARAM("a") NBR_REG, REG_EXTENDED)
      || regcomp(&regex[1], HYPER_PARAM("b") NBR_REG, REG_EXTENDED)
      || regcomp(&regex[2], HYPER_PARAM("c") NBR_REG, REG_EXTENDED)
      || regcomp(&regex[3], HYPER_PARAM("d") NBR_REG, REG_EXTENDED)
      || regcomp(&regex[4], HYPER_PARAM("c_factor")
		 NBR_REG, REG_EXTENDED))
    return (fprintf(stderr, "Regex error\n"));
  while ((pars->buf = get_next_line(pars->fd))
	 && regexec(&pars->regex[4], pars->buf, 0, &pars->reg_struct, 0))
    {
      i = 0;
      while (i < 5 && regexec(&regex[i], pars->buf, 0, &pars->reg_struct, 0))
	++i;
      if (i < 5)
	params[i] = get_double_parser(pars->buf);
    }
  return (add_hyperboloid(sys->scene_list->obj_list, params));
}

void		parse_mesh_init(char **shape_list, int (**func)())
{
  shape_list[0] = "sphere";
  shape_list[1] = "plane";
  shape_list[2] = "holedcube";
  shape_list[3] = "cone";
  shape_list[4] = "tore";
  shape_list[5] = "cylinder";
  shape_list[6] = "paraboloid";
  shape_list[7] = "hyperboloid";
  func[0] = mesh_sphere;
  func[1] = mesh_plane;
  func[2] = mesh_holedcube;
  func[3] = mesh_cone;
  func[4] = mesh_tore;
  func[5] = mesh_cylinder;
  func[6] = mesh_paraboloid;
  func[7] = mesh_hyperboloid;
}

int		parse_mesh(t_system *sys, t_parser *pars)
{
  int		i;
  int		j;
  char		shape[BUFSIZ];
  char		*shape_list[9];
  int		(*func[8])();

  i = 0;
  j = 0;
  parse_mesh_init(shape_list, func);
  if (pars->level < 2)
    return (fprintf(stderr, "Invalid XML (mesh) line %i.\n", pars->line) * -1);
  while (pars->buf[i] && pars->buf[i] != '"')
    ++i;
  ++i;
  while (i < BUFSIZ - 1 && pars->buf[i] && pars->buf[i] != '"')
    shape[j++] = pars->buf[i++];
  shape[j] = 0;
  i = 0;
  while (i < 8 && strncmp(shape_list[i], shape, strlen(shape_list[i]) - 1))
    ++i;
  if (i < 8)
    if (func[i](sys, pars) != CLEAN)
      return (-30);
  return ((pars->buf == NULL) ? -30 : 0);
}
