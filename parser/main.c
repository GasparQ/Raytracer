/*
** main.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Tue May 26 17:05:55 2015 fernand veyrier
** Last update Thu May 28 18:35:59 2015 fernand veyrier
*/

#include "get_next_line.h"

# define HEADER		"^<\\?xml version[[:space:]]*=[[:space:]]*\"[[:digit:].]+\"\\?>$"
# define OBJECT_OPEN	"[[:space:]]*<object>[[:space:]]*$"
# define OBJECT_CLOSE	"[[:space:]]*</object>[[:space:]]*$"
# define MESH_OPEN	"[[:space:]]*<mesh[[:space:]]+type[[:space:]]*=\""
# define MESH_OPEN_NEXT	"(tore|sphere|cylinder|cone|plane|paraboloid"
# define MESH_OPEN_LAST	"|holedcube|hyperboloid)\"[[:space:]]*>[[:space:]]*$"
# define MESH_CLOSE	"[[:space:]]*</mesh>[[:space:]]*$"
# define COORD_OPEN	"[[:space:]]*<coord>[[:space:]]*$"
# define COORD_CLOSE	"[[:space:]]*</coord>[[:space:]]*$"
# define PHONG_OPEN	"[[:space:]]*<phong>[[:space:]]*$"
# define PHONG_CLOSE	"[[:space:]]*</phong>[[:space:]]*$"
# define LIMIT_OPEN	"[[:space:]]*<limit>[[:space:]]*$"
# define LIMIT_CLOSE	"[[:space:]]*</limit>[[:space:]]*$"
# define SCENE		"[[:space:]]*<scene>[[:space:]]*$"
# define SCENE_CLOSE	"[[:space:]]*</scene>[[:space:]]*$"
# define SPOT		"[[:space:]]*<spot>[[:space:]]*$"
# define SPOT_CLOSE	"[[:space:]]*</spot>[[:space:]]*$"

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

int		parse_obj(int level, t_system *sys, int line)
{
  if (level < 0)
    return (fprintf(stderr, "Invalid XML (obj) line %i.\n", line) * -1);
  printf("Found obj\n", level);
  return (1);
}

int		parse_obj_close(int level, t_system *sys, int line)
{
  level -= 1;
  if (level < 0)
    return (fprintf(stderr, "Invalid XML (obj) line %i.\n", line) * -1);
  printf("Found obj close\n");
  return (-1);
}

int		parse_mesh(int level, t_system *sys, int line)
{
  if (level < 1)
    return (fprintf(stderr, "Invalid XML (mesh) line %i.\n", line) * -1);
  printf("Found mesh\n");
  return (2);
}

int		parse_mesh_close(int level, t_system *sys, int line)
{
  if (level - 2 < 1)
    return (fprintf(stderr, "Invalid XML (mesh) line %i.\n", line) * -1);
  printf("Found mesh close\n");
  return (-2);
}

int		parse_coord(int level, t_system *sys, int line)
{
  if (level < 1)
    return (fprintf(stderr, "Invalid XML (coord) line %i.\n", line) * -1);
  printf("Found coord\n");
  return (3);
}

int		parse_coord_close(int level, t_system *sys, int line)
{
  if (level - 3 < 1)
    return (fprintf(stderr, "Invalid XML (coord) line %i.\n", line) * -1);
  printf("Found coord close\n");
  return (-3);
}

int		parse_phong(int level, t_system *sys, int line)
{
  if (level < 1)
    return (fprintf(stderr, "Invalid XML (phong) line %i.\n", line) * -1);
  printf("Found phong\n");
  return (4);
}

int		parse_phong_close(int level, t_system *sys, int line)
{
  if (level - 4 < 1)
    return (fprintf(stderr, "Invalid XML (phong) line %i.\n", line) * -1);
  printf("Found phong close\n");
  return (-4);
}

int		parse_limit(int level, t_system *sys, int line)
{
  if (level < 1)
    return (fprintf(stderr, "Invalid XML (limit) line %i.\n", line) * -1);
  printf("Found limit\n");
  return (5);
}

int		parse_limit_close(int level, t_system *sys, int line)
{
  if (level - 5 < 1)
    return (fprintf(stderr, "Invalid XML (limit) line %i.\n", line) * -1);
  printf("Found limit close\n");
  return (-5);
}

/*
** add_object(t_vector[2]{position, rotation}, int[2]{sys->img.bpp / 8, color}
**            get_properties(brightness, opacity, reflexion, refraction), sys->objlist)
*/
int		follow_pattern(const int fd, regex_t *regex,
			       regmatch_t reg_struct, t_system *sys)
{
  char		*buffer;
  int		is_invalid;
  int		level;
  int		line;
  int		(*func[10])();
  int		i;

  level = 0;
  line = 2;
  i = 0;
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
  while ((buffer = get_next_line(fd)) != NULL && level >= 0)
    {
      printf("[%s]\n", buffer);
      while (i < 10 && regexec(&regex[i + 1], buffer, 0, &reg_struct, 0))
	++i;
      if (i < 10)
	level += func[i](level, sys, line);
      ++line;
      i = 0;
    }
  if (level != 0)
    return (fprintf(stderr, "Corrupted XML file.\n"));
  return (0);
}

int		get_objects(const int fd, t_system *sys)
{
  int		is_invalid;
  regex_t	regex[11];
  regmatch_t	reg_struct;
  char		*buf;
  size_t	match;

  buf = get_next_line(fd);
  match = 0;
  if (regcomp(&regex[0], HEADER, REG_EXTENDED)
      || regcomp(&regex[1], OBJECT_OPEN, REG_EXTENDED)
      || regcomp(&regex[2], OBJECT_CLOSE, REG_EXTENDED)
      || regcomp(&regex[3], MESH_OPEN MESH_OPEN_NEXT MESH_OPEN_LAST, REG_EXTENDED)
      || regcomp(&regex[4], MESH_CLOSE, REG_EXTENDED)
      || regcomp(&regex[5], COORD_OPEN, REG_EXTENDED)
      || regcomp(&regex[6], COORD_CLOSE, REG_EXTENDED)
      || regcomp(&regex[7], PHONG_OPEN, REG_EXTENDED)
      || regcomp(&regex[8], PHONG_CLOSE, REG_EXTENDED)
      || regcomp(&regex[9], LIMIT_OPEN, REG_EXTENDED)
      || regcomp(&regex[10], LIMIT_CLOSE, REG_EXTENDED))
    return (fprintf(stderr, "Regex error.\n"));
  is_invalid = regexec(&regex[0], buf, match, &reg_struct, 0);
  if (is_invalid)
    return (fprintf(stderr, "Invalid XML header.\n"));
  return (follow_pattern(fd, regex, reg_struct, sys));
}

int		main(int ac, char **av)
{
  int		fd;
  char		*buf;
  t_system	*sys;

  if (ac < 2)
    return (-1);
  if ((fd = check_extension(av[1])) == -1)
    return (-1);
  get_objects(fd, sys);
  return (0);
}
