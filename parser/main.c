/*
** main.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Tue May 26 17:05:55 2015 fernand veyrier
** Last update Sat May 30 20:25:56 2015 fernand veyrier
*/

#include "get_next_line.h"

int		check_extension(char *file)
{
  int		fd;

  if (strlen(file) < 4 || strncmp(file + strlen(file) - 4, ".xml", 4))
    {
      fprintf(stderr, "Only .xml extension is valid.\n");
      return (-1);
    }
  if ((fd = open(file, O_RDONLY)) == -1)
    {
      fprintf(stderr, "Error opening file.\n");
      return (-1);
    }
  return (fd);
}

t_vector3	get_vector(char *buf)
{
  int		i;
  int		j;
  t_vector3	vec;
  char		nbr[BUFSIZ];

  i = 0;
  while ((j = 0) == 0 && buf[i] && buf[i] != '(')
    ++i;
  while (buf[++i] != ',')
    nbr[j++] = buf[i];
  nbr[j] = 0;
  vec.x = atof(nbr);
  j = 0;
  ++i;
  while (buf[i] != ',')
    nbr[j++] = buf[i++];
  nbr[j] = 0;
  vec.y = atof(nbr);
  j = 0;
  ++i;
  while (buf[i] != ')')
    nbr[j++] = buf[i++];
  nbr[j] = 0;
  vec.z = atof(nbr);
  return (vec);
}

int		get_color_parser(char *buf)
{
  int		i;
  int		j;
  char		nbr[BUFSIZ];

  i = 0;
  j = 0;
  while (buf[i] && buf[i] != 'x')
    ++i;
  ++i;
  while (buf[i] && ((buf[i] >= '0' && buf[i] <= '9')
		    || (buf[i] >= 'A' && buf[i] <= 'F')))
    nbr[j++] = buf[i++];
  nbr[j] = 0;
  return (my_getnbr_base(nbr, "0123456789ABCDEF"));
}

int		get_nbr_parser(char *buf)
{
  int		i;
  int		j;
  char		nbr[BUFSIZ];

  i = 0;
  j = 0;
  while (buf[i] && !(buf[i] >= '0' && buf[i] <= '9') && buf[i] != '-')
    ++i;
  while (buf[i] && ((buf[i] >= '0' && buf[i] <= '9') || buf[i] == '-'))
    nbr[j++] = buf[i++];
  nbr[j] = 0;
  return (atoi(nbr));
}

double		get_double_parser(char *buf)
{
  int		i;
  int		j;
  char		nbr[BUFSIZ];

  i = 0;
  j = 0;
  while (buf[i] && !(buf[i] >= '0' && buf[i] <= '9') && buf[i] != '-')
    ++i;
  while (buf[i] && ((buf[i] >= '0' && buf[i] <= '9')
		    || buf[i] == '-' || buf[i] == '.'))
    nbr[j++] = buf[i++];
  nbr[j] = 0;
  return (atof(nbr));
}

int		parse_obj(t_system *sys, t_parser *pars)
{
  int		color;

  if (pars->level < 1)
    return (fprintf(stderr, "Invalid XML (obj) line %i.\n", pars->line) * -1);
  color = get_color_parser(pars->buf);
  printf("Found obj\n");
  /* add_object(&sys->scene_list->obj_list, color, (sys->scene_list->img == NULL ? */
  /* 					     4 : sys->scene_list->img->bpp / 8)); */
  return (11);
}

int		parse_obj_close(t_system *sys, t_parser *pars)
{
  if (pars->level - 11 < 1)
    return (fprintf(stderr, "Invalid XML (obj) line %i.\n", pars->line) * -1);
  printf("Found obj close\n");
  return (-11);
}

int		parse_mesh(t_system *sys, t_parser *pars)
{
  if (pars->level < 2)
    return (fprintf(stderr, "Invalid XML (mesh) line %i.\n", pars->line) * -1);
  printf("Found mesh\n");
  return (2);
}

int		parse_mesh_close(t_system *sys, t_parser *pars)
{
  if (pars->level - 2 < 2)
    return (fprintf(stderr, "Invalid XML (mesh) line %i.\n", pars->line) * -1);
  printf("Found mesh close\n");
  return (-2);
}

int		parse_coord(t_system *sys, t_parser *pars)
{
  t_vector3	pos;
  t_vector3	rot;
  double	coord[6];

  if (pars->level < 1)
    return (fprintf(stderr, "Invalid XML (coord) line %i.\n", pars->line) * -1);
  printf("Found coord\n");
  while ((pars->buf = get_next_line(pars->fd))
	 && regexec(&pars->regex[6], pars->buf, 0, &pars->reg_struct, 0))
    {
      if (!regexec(&pars->regex[18], pars->buf, 0, &pars->reg_struct, 0))
	pos = get_vector(pars->buf);
      if (!regexec(&pars->regex[17], pars->buf, 0, &pars->reg_struct, 0))
	rot = get_vector(pars->buf);
    }
  coord[0] = pos.x;
  coord[1] = pos.y;
  coord[2] = pos.z;
  coord[3] = rot.x;
  coord[4] = rot.y;
  coord[5] = rot.z;
  //add_coord(&sys->scene_list->obj_list, coord);
  return ((pars->buf == NULL) ? -30 : 0);
}

int		parse_coord_close(t_system *sys, t_parser *pars)
{
  if (pars->level - 3 < 1)
    return (fprintf(stderr, "Invalid XML (coord) line %i.\n", pars->line) * -1);
  printf("Found coord close\n");
  return (-3);
}

int		parse_phong(t_system *sys, t_parser *pars)
{
  double	params[10];
  regex_t	regex[8];
  char		nbr[BUFSIZ];
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
  //add_phong(sys->scene_list->obj_list, params);
  return ((pars->buf == NULL) ? -30 : 0);
}

int		parse_phong_close(t_system *sys, t_parser *pars)
{
  if (pars->level - 4 < 1)
    return (fprintf(stderr, "Invalid XML (phong) line %i.\n", pars->line) * -1);
  printf("Found phong close\n");
  return (-4);
}

int		parse_limit(t_system *sys, t_parser *pars)
{
  if (pars->level < 1)
    return (fprintf(stderr, "Invalid XML (limit) line %i.\n", pars->line) * -1);
  printf("Found limit\n");
  return (5);
}

int		parse_limit_close(t_system *sys, t_parser *pars)
{
  if (pars->level - 5 < 1)
    return (fprintf(stderr, "Invalid XML (limit) line %i.\n", pars->line) * -1);
  printf("Found limit close\n");
  return (-5);
}

int		parse_spot(t_system *sys, t_parser *pars)
{
  t_vector3	pos;
  int		color;

  if (pars->level != 1)
    return (fprintf(stderr, "Invalid XML (spot) line %i.\n", pars->line) * -1);
  printf("Found spot\n");
  pos.x = 0;
  pos.y = 0;
  pos.y = 0;
  color = 0;
  while ((pars->buf = get_next_line(pars->fd))
	 && regexec(&pars->regex[12], pars->buf, 0, &pars->reg_struct, 0))
    {
      if (!regexec(&pars->regex[18], pars->buf, 0, &pars->reg_struct, 0))
	pos = get_vector(pars->buf);
      if (!regexec(&pars->regex[19], pars->buf, 0, &pars->reg_struct, 0))
	color = get_color_parser(pars->buf);
    }
  //add_spot(sys->scene_list, pos, color);
  return ((pars->buf == NULL) ? -30 : 0);
}

int		parse_spot_close(t_system *sys, t_parser *pars)
{
  if (pars->level - 6 != 1)
    return (fprintf(stderr, "Invalid XML (spot) line %i.\n", pars->line) * -1);
  printf("Found spot close\n");
  return (-6);
}

int		parse_scene(t_system *sys, t_parser *pars)
{
  if (pars->level != 0)
    return (fprintf(stderr, "Invalid XML (scene) line %i.\n", pars->line) * -1);
  printf("Found scene\n");
  //add_scene(&sys->scene_list, sys->mlx);
  return (1);
}

int		parse_scene_close(t_system *sys, t_parser *pars)
{
  if (pars->level - 1 != 0)
    return (fprintf(stderr, "Invalid XML (spot) line %i.\n", pars->line) * -1);
  printf("Found scene close\n");
  return (-1);
}

int		parse_eye(t_system *sys, t_parser *pars)
{
  t_vector3	pos;
  t_vector3	rot;
  int		distance;

  if (pars->level != 1)
    return (fprintf(stderr, "Invalid XML (eye) line %i.\n", pars->line) * -1);
  printf("Found eye\n");
  while ((pars->buf = get_next_line(pars->fd))
	 && regexec(&pars->regex[16], pars->buf, 0, &pars->reg_struct, 0))
    {
      if (!regexec(&pars->regex[18], pars->buf, 0, &pars->reg_struct, 0))
	pos = get_vector(pars->buf);
      if (!regexec(&pars->regex[17], pars->buf, 0, &pars->reg_struct, 0))
	rot = get_vector(pars->buf);
      if (!regexec(&pars->regex[20], pars->buf, 0, &pars->reg_struct, 0))
	distance = get_nbr_parser(pars->buf);
    }
  //add_eye(sys->scene_list, pos, rot, distance);
  return ((pars->buf == NULL) ? -30 : 0);
}

int		parse_eye_close(t_system *sys, t_parser *pars)
{
  if (pars->level - 10 != 1)
    return (fprintf(stderr, "Invalid XML (eye) line %i.\n", pars->line) * -1);
  printf("Found eye close\n");
  return (-10);
}

void		init_functions(int (**func)())
{
  func[0] = parse_obj;
  func[1] = parse_obj_close;
  func[2] = parse_mesh;
  func[3] = parse_mesh_close;
  func[4] = parse_coord;
  func[5] = parse_coord_close;
  func[6] = parse_phong;
  func[7] = parse_phong_close;
  func[8] = parse_limit;
  func[9] = parse_limit_close;
  func[10] = parse_spot;
  func[11] = parse_spot_close;
  func[12] = parse_scene;
  func[13] = parse_scene_close;
  func[14] = parse_eye;
  func[15] = parse_eye_close;
}

int		follow_pattern(t_parser *pars, t_system *sys)
{
  int		is_invalid;
  int		(*func[16])();
  int		i;

  i = 0;
  init_functions(func);
  while ((pars->buf = get_next_line(pars->fd)) != NULL)
    {
      while (i < 16 && regexec(&pars->regex[i + 1], pars->buf,
			       0, &pars->reg_struct, 0))
	++i;
      if (i < 16)
	{
	  pars->level = (pars->line == 2) ? 0 : pars->level;
	  pars->level += func[i](sys, pars);
	  if (pars->level < 0)
	    break;
	}
      ++pars->line;
      i = 0;
    }
  if (pars->level != 0)
    return (fprintf(stderr, "Corrupted XML file.\n") * -1);
  return (0);
}

int		init_rules(regex_t *regex)
{
  if (regcomp(&regex[0], HEADER, REG_EXTENDED)
      || regcomp(&regex[1], OBJECT_OPEN OBJECT_NEXT, REG_EXTENDED)
      || regcomp(&regex[2], OBJECT_CLOSE, REG_EXTENDED)
      || regcomp(&regex[3], MESH_OPEN MESH_OPEN_NEXT MESH_OPEN_LAST,
		 REG_EXTENDED)
      || regcomp(&regex[4], MESH_CLOSE, REG_EXTENDED)
      || regcomp(&regex[5], COORD_OPEN, REG_EXTENDED)
      || regcomp(&regex[6], COORD_CLOSE, REG_EXTENDED)
      || regcomp(&regex[7], PHONG_OPEN, REG_EXTENDED)
      || regcomp(&regex[8], PHONG_CLOSE, REG_EXTENDED)
      || regcomp(&regex[9], LIMIT_OPEN, REG_EXTENDED)
      || regcomp(&regex[10], LIMIT_CLOSE, REG_EXTENDED)
      || regcomp(&regex[11], SPOT, REG_EXTENDED)
      || regcomp(&regex[12], SPOT_CLOSE, REG_EXTENDED)
      || regcomp(&regex[13], SCENE, REG_EXTENDED)
      || regcomp(&regex[14], SCENE_CLOSE, REG_EXTENDED)
      || regcomp(&regex[15], EYE, REG_EXTENDED)
      || regcomp(&regex[16], EYE_CLOSE, REG_EXTENDED)
      || regcomp(&regex[17], ROTATION POS_NEXT, REG_EXTENDED)
      || regcomp(&regex[18], POSITION POS_NEXT, REG_EXTENDED)
      || regcomp(&regex[19], COLOR_REG COLOR_NEXT, REG_EXTENDED)
      || regcomp(&regex[20], DISTANCE_REG DISTANCE_NEXT, REG_EXTENDED))
    return (fprintf(stderr, "Regex error.\n"));
  return (0);
}

int		get_objects(t_parser parser, t_system *sys)
{
  int		is_invalid;
  size_t	match;

  parser.buf = get_next_line(parser.fd);
  parser.level = -1;
  parser.line = 2;
  match = 0;
  if (init_rules(parser.regex) != 0)
    return (-1);
  is_invalid = regexec(&parser.regex[0], parser.buf,
		       match, &parser.reg_struct, 0);
  if (is_invalid)
    return (fprintf(stderr, "Invalid XML header.\n"));
  return (follow_pattern(&parser, sys));
}

int		main(int ac, char **av)
{
  t_parser	parser;
  t_system	*sys;

  if (ac < 2)
    return (-1);
  if ((parser.fd = check_extension(av[1])) == -1)
    return (-1);
  get_objects(parser, sys);
  return (0);
}
