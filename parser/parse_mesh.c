/*
** parse_mesh.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer/parser
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sat May 30 20:46:43 2015 fernand veyrier
** Last update Tue Jun  2 09:53:55 2015 quentin gasparotto
*/

#include "get_next_line.h"

int		mesh_sphere(t_system *sys, t_parser *pars)
{
  double	radius;
  regex_t	regex;

  radius = 0;
  if (regcomp(&regex, "[[:space:]]*radius[[:space:]]*\
=[[:space:]]*[[:digit:].]+[[:space:]]*$", REG_EXTENDED))
    return (fprintf(stderr, "Regex error\n"));
  printf("Add mesh sphere\n");
  while ((pars->buf = get_next_line(pars->fd))
	 && regexec(&pars->regex[4], pars->buf, 0, &pars->reg_struct, 0))
    {
      if (!regexec(&regex, pars->buf, 0, &pars->reg_struct, 0))
	radius = get_double_parser(pars->buf);
    }
  return (add_sphere(sys->scene_list->obj_list, &radius));
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
	params[0] = get_double_parser(pars->buf);
    }
  params[1] = normal.x;
  params[2] = normal.y;
  params[3] = normal.z;
  printf("Add mesh plane\n");
  return (add_plan(sys->scene_list->obj_list, params));
}

int		mesh_tore(t_system *sys, t_parser *pars)
{
  double	params[2];
  regex_t	regex[2];

  params[0] = 0;
  params[1] = 0;
  if (regcomp(&regex[0], "[[:space:]]*radius_in[[:space:]]*\
=[[:space:]]*[[:digit:].-]+[[:space:]]*$", REG_EXTENDED)
      || regcomp(&regex[1], "[[:space:]]*radius_out[[:space:]]*\
=[[:space:]]*[[:digit:].-]+[[:space:]]*$", REG_EXTENDED))
    return (fprintf(stderr, "Regex error\n"));
  while ((pars->buf = get_next_line(pars->fd))
	 && regexec(&pars->regex[4], pars->buf, 0, &pars->reg_struct, 0))
    {
      if (!regexec(&regex[1], pars->buf, 0, &pars->reg_struct, 0))
	params[0] = get_double_parser(pars->buf);
      if (!regexec(&regex[0], pars->buf, 0, &pars->reg_struct, 0))
	params[1] = get_double_parser(pars->buf);
    }
  printf("Add mesh tore\n");
  return (add_tore(sys->scene_list->obj_list, params));
}

int		mesh_holedcube(t_system *sys, t_parser *pars)
{
  double	params[2];
  regex_t	regex[2];

  params[0] = 0;
  params[1] = 0;
  if (regcomp(&regex[0], "[[:space:]]*cote[[:space:]]*\
=[[:space:]]*[[:digit:].-]+[[:space:]]*$", REG_EXTENDED)
      || regcomp(&regex[1], "[[:space:]]*hole[[:space:]]*\
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
  printf("Add mesh holedcube\n");
  return (add_holed_cube(sys->scene_list->obj_list, params));
}

int		mesh_cone(t_system *sys, t_parser *pars)
{
  double	phi;
  regex_t	regex;

  phi = 0;
  if (regcomp(&regex, "[[:space:]]*phi[[:space:]]*\
=[[:space:]]*[[:digit:].]+[[:space:]]*$", REG_EXTENDED))
    return (fprintf(stderr, "Regex error\n"));
  while ((pars->buf = get_next_line(pars->fd))
	 && regexec(&pars->regex[4], pars->buf, 0, &pars->reg_struct, 0))
    {
      if (!regexec(&regex, pars->buf, 0, &pars->reg_struct, 0))
	phi = get_double_parser(pars->buf);
    }
  printf("Add mesh cone\n");
  return (add_cone(sys->scene_list->obj_list, &phi));
}

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
  printf("Add mesh cylinder\n");
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
  printf("Add mesh paraboloid\n");
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
  if (regcomp(&regex[0], "[[:space:]]*a[[:space:]]*\
=[[:space:]]*[[:digit:].-]+[[:space:]]*$", REG_EXTENDED)
      || regcomp(&regex[1], "[[:space:]]*b[[:space:]]*\
=[[:space:]]*[[:digit:].-]+[[:space:]]*$", REG_EXTENDED)
      || regcomp(&regex[2], "[[:space:]]*c[[:space:]]*\
=[[:space:]]*[[:digit:].-]+[[:space:]]*$", REG_EXTENDED)
      ||regcomp(&regex[3], "[[:space:]]*d[[:space:]]*\
=[[:space:]]*[[:digit:].-]+[[:space:]]*$", REG_EXTENDED)
      ||regcomp(&regex[4], "[[:space:]]*c_factor[[:space:]]*\
=[[:space:]]*[[:digit:].-]+[[:space:]]*$", REG_EXTENDED))
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
  printf("Add mesh hyperboloid\n");
  return (add_hyperboloid(sys->scene_list->obj_list, params));
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
    if (func[i](sys, pars) != CLEAN)
      return (-30);
  return ((pars->buf == NULL) ? -30 : 0);
}

int		parse_mesh_close(UNUSED t_system *sys, t_parser *pars)
{
  if (pars->level - 2 < 2)
    return (fprintf(stderr, "Invalid XML (mesh) line %i.\n", pars->line) * -1);
  printf("Found mesh close\n");
  return (-2);
}
