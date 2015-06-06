/*
** parse_mesh_next.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sat Jun  6 11:19:02 2015 fernand veyrier
** Last update Sat Jun  6 11:19:26 2015 fernand veyrier
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
  return (add_cone(sys->scene_list->obj_list, &phi));
}
