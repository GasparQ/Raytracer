/*
** main.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Tue May 26 17:05:55 2015 fernand veyrier
** Last update Sat Jun  6 11:44:58 2015 fernand veyrier
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

int		init_functions(int (**func)())
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
  func[16] = parse_texture;
  func[17] = parse_texture_close;
  return (0);
}

int		follow_pattern(t_parser *pars, t_system *sys)
{
  int		(*func[18])();
  int		i;
  int		ret;

  i = init_functions(func);
  while ((pars->buf = get_next_line(pars->fd)) != NULL)
    {
      while (i < 18 && regexec(&pars->regex[i + 1], pars->buf,
			       0, &pars->reg_struct, 0))
	++i;
      if (i < 18)
	{
	  pars->level = (pars->line == 2) ? 0 : pars->level;
	  ret = func[i](sys, pars);
	  pars->level += ret;
	  if (ret == -5 && pars->level > 0)
	    return (0);
	  if (pars->level < 0)
	    break;
	}
      ++pars->line;
      i = 0;
    }
  return ((pars->level != 0) ?
	  fprintf(stderr, "Corrupted XML file.\n") * -1 : 0);
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
