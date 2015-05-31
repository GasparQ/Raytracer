/*
** parse_mesh.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer/parser
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sat May 30 20:46:43 2015 fernand veyrier
** Last update Sun May 31 11:57:14 2015 fernand veyrier
*/

#include "get_next_line.h"

int		mesh_sphere(t_system *sys, t_parser *pars)
{
  double	radius;
  regex_t	regex;

  radius = 0;
  if (regcomp(&regex, "[[:space:]]*radius[[:space:]]*\
=[[:space:]]*[[:digit:].]+[[:space:]]*$", REG_EXTENDED))
    return (fprintf(stderr, "Regex error HERE\n"));
  printf("Add mesh sphere\n");
  while ((pars->buf = get_next_line(pars->fd))
	 && regexec(&pars->regex[4], pars->buf, 0, &pars->reg_struct, 0))
    {
      if (!regexec(&regex, pars->buf, 0, &pars->reg_struct, 0))
	radius = get_double_parser(pars->buf);
    }
  //add_sphere(sys->scene_list->obj_list, &radius);
}

int		mesh_plane(t_system *sys, t_parser *pars)
{
  double	params[4];
  t_vector3	normal;
  int		i;
  regex_t	regex[2];

  i = 0;
  while (i < 4)
    params[i++] = 0;
  if (regcomp(&regex[0], "[[:space:]]*normal[[:space:]]*\
=[[:space:]]" POS_NEXT, REG_EXTENDED)
      || regcomp(&regex[1], "[[:space:]]*cst[[:space:]]*\
=[[:space:]]*[[:digit:].-]+[[:space:]]*$", REG_EXTENDED))
    return (fprintf(stderr, "Regex error\n"));
  while ((pars->buf = get_next_line(pars->fd))
	 && regexec(&pars->regex[4], pars->buf, 0, &pars->reg_struct, 0))
    {
      if (!regexec(&regex[0], pars->buf, 0, &pars->reg_struct, 0))
	normal = get_vector(pars->buf);
      if (!regexec(&regex[1], pars->buf, 0, &pars->reg_struct, 0))
	params[3] = get_double_parser(pars->buf);
    }
  params[0] = normal.x;
  params[1] = normal.y;
  params[2] = normal.z;
  //add_plane(sys->scene_list->obj_list, params);
  printf("Add mesh plane\n");
}

int		mesh_tore(t_system *sys, t_parser *pars)
{
  double	params[2];
  regex_t	regex[2];

  params[0] = 0;
  params[1] = 0;
  if (regcomp(&regex[1], "[[:space:]]*radius_in[[:space:]]*\
=[[:space:]]*[[:digit:].-]+[[:space:]]*$", REG_EXTENDED)
      || regcomp(&regex[1], "[[:space:]]*radius_out[[:space:]]*\
=[[:space:]]*[[:digit:].-]+[[:space:]]*$", REG_EXTENDED))
    return (fprintf(stderr, "Regex error\n"));
  while ((pars->buf = get_next_line(pars->fd))
	 && regexec(&pars->regex[4], pars->buf, 0, &pars->reg_struct, 0))
    {
      if (!regexec(&regex[0], pars->buf, 0, &pars->reg_struct, 0))
	params[0] = get_double_parser(pars->buf);
      if (!regexec(&regex[1], pars->buf, 0, &pars->reg_struct, 0))
	params[1] = get_double_parser(pars->buf);
    }
  printf("Add mesh tore\n");
  //add_tore(sys->scene_list->obj_list, params);
}

int		mesh_holedcube(t_system *sys, t_parser *pars)
{
  printf("Add mesh holedcube\n");
}

int		mesh_cone(t_system *sys, t_parser *pars)
{
  printf("Add mesh cone\n");
}

int		mesh_cylinder(t_system *sys, t_parser *pars)
{
  printf("Add mesh cylinder\n");
}

int		mesh_paraboloid(t_system *sys, t_parser *pars)
{
  printf("Add mesh paraboloid\n");
}

int		mesh_hyperboloid(t_system *sys, t_parser *pars)
{
  double	params[4];
  int		i;
  regex_t	regex[4];

  i = 0;
  while (i < 4)
    params[i++] = 0;
  if (regcomp(&regex[0], "[[:space:]]*a[[:space:]]*\
=[[:space:]]*[[:digit:].-]+[[:space:]]*$", REG_EXTENDED)
      || regcomp(&regex[1], "[[:space:]]*b[[:space:]]*\
=[[:space:]]*[[:digit:].-]+[[:space:]]*$", REG_EXTENDED)
      || regcomp(&regex[2], "[[:space:]]*c[[:space:]]*\
=[[:space:]]*[[:digit:].-]+[[:space:]]*$", REG_EXTENDED)
      ||regcomp(&regex[3], "[[:space:]]*d[[:space:]]*\
=[[:space:]]*[[:digit:].-]+[[:space:]]*$", REG_EXTENDED))
    return (fprintf(stderr, "Regex error\n"));
  while ((pars->buf = get_next_line(pars->fd))
	 && regexec(&pars->regex[4], pars->buf, 0, &pars->reg_struct, 0))
    {
      i = 0;
      while (i < 4 && regexec(&regex[i], pars->buf, 0, &pars->reg_struct, 0))
	++i;
      if (i < 4)
	params[i] = get_double_parser(pars->buf);
    }
  printf("Add mesh hyperboloid\n");
  //add_hyperboloid(sys->scene_list->obj_list, params);
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
  shape_list[0] = "sphere";
  shape_list[1] = "plane";
  shape_list[2] = "holedcube";
  shape_list[3] = "cone";
  shape_list[4] = "tore";
  shape_list[5] = "cylinder";
  shape_list[6] = "paraboloid";
  shape_list[7] = "hyperboloid";
  shape_list[8] = 0;
  func[0] = mesh_sphere;
  func[1] = mesh_plane;
  func[2] = mesh_holedcube;
  func[3] = mesh_cone;
  func[4] = mesh_tore;
  func[5] = mesh_cylinder;
  func[6] = mesh_paraboloid;
  func[7] = mesh_hyperboloid;
  if (pars->level < 2)
    return (fprintf(stderr, "Invalid XML (mesh) line %i.\n", pars->line) * -1);
  printf("Found mesh\n");
  while (pars->buf[i] && pars->buf[i] != '"')
    ++i;
  ++i;
  while (i < BUFSIZ && pars->buf[i] && pars->buf[i] != '"')
    shape[j++] = pars->buf[i++];
  shape[j] = 0;
  i = 0;
  while (i < 8 && strncmp(shape_list[i], shape, strlen(shape_list[i]) - 1))
    ++i;
  if (i < 8)
    func[i](sys, pars);
  return ((pars->buf == NULL) ? -30 : 0);
}

int		parse_mesh_close(t_system *sys, t_parser *pars)
{
  if (pars->level - 2 < 2)
    return (fprintf(stderr, "Invalid XML (mesh) line %i.\n", pars->line) * -1);
  printf("Found mesh close\n");
  return (-2);
}
