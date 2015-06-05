/*
** main.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Tue May 26 17:05:55 2015 fernand veyrier
** Last update Fri Jun  5 14:49:57 2015 fernand veyrier
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
	  /* if (parse->level == -5) */
	  /*   return (0); */
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
      || regcomp(&regex[20], DISTANCE_REG DISTANCE_NEXT, REG_EXTENDED)
      || regcomp(&regex[21], INTENSITY NBR_REG, REG_EXTENDED)
      || regcomp(&regex[22], RENDER_METHOD, REG_EXTENDED))
    return (fprintf(stderr, "Regex error.\n"));
  return (0);
}

int		get_objects(t_system *sys, char *file)
{
  t_parser	parser;
  int		is_invalid;
  size_t	match;

  if ((parser.fd = check_extension(file)) == -1)
    return (-1);
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

/* int		main(int ac, char **av) */
/* { */
/*   t_system	*sys; */

/*   if (ac < 2) */
/*     return (-1); */
/*   get_objects(sys, av[1]); */
/*   return (0); */
/* } */
