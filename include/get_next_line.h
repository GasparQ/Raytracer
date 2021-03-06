/*
** get_next_line.h for get next line in /home/gaspar_q/rendu/CPE_2014_get_next_line/include
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Mon Nov 17 15:16:33 2014 quentin gasparotto
** Last update Sun Jun  7 23:37:57 2015 fernand veyrier
*/

#ifndef GET_NXT_LINE_H_
# define GET_NXT_LINE_H_

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <regex.h>
# include "minilibx_system.h"
# include "prototypes.h"

# define LINE_LEN	4096
# define HEADER_NEXT	"\"[[:digit:].]+\"\\?>$"
# define HEADER		"^<\\?xml version[[:space:]]*=[[:space:]]*" HEADER_NEXT
# define OBJECT_OPEN	"[[:space:]]*<object[[:space:]]+color=\"0x"
# define OBJECT_NEXT	"[[:digit:]A-F]{,8}\">[[:space:]]*$"
# define OBJECT_CLOSE	"^[[:space:]]*</object>[[:space:]]*$"
# define MESH_OPEN	"^[[:space:]]*<mesh[[:space:]]+type[[:space:]]*=\""
# define MESH_OPEN_NEXT	"(tore|sphere|cylinder|cone|plane|paraboloid"
# define MESH_OPEN_LAST	"|holedcube|hyperboloid)\"[[:space:]]*>[[:space:]]*$"
# define MESH_CLOSE	"^[[:space:]]*</mesh>[[:space:]]*$"
# define COORD_OPEN	"^[[:space:]]*<coord>[[:space:]]*$"
# define COORD_CLOSE	"^[[:space:]]*</coord>[[:space:]]*$"
# define PHONG_OPEN	"^[[:space:]]*<phong>[[:space:]]*$"
# define PHONG_CLOSE	"^[[:space:]]*</phong>[[:space:]]*$"
# define LIMIT_OPEN	"^[[:space:]]*<limit>[[:space:]]*$"
# define LIMIT_CLOSE	"^[[:space:]]*</limit>[[:space:]]*$"
# define SCENE		"^[[:space:]]*<scene>[[:space:]]*$"
# define SCENE_CLOSE	"^[[:space:]]*</scene>[[:space:]]*$"
# define SPOT		"^[[:space:]]*<spot>[[:space:]]*$"
# define SPOT_CLOSE	"^[[:space:]]*</spot>[[:space:]]*$"
# define EYE		"^[[:space:]]*<eye>[[:space:]]*$"
# define EYE_CLOSE	"^[[:space:]]*</eye>[[:space:]]*$"
# define POSITION	"^[[:space:]]*position[[:space:]]*=[[:space:]]*"
# define ROTATION	"^[[:space:]]*rotation[[:space:]]*=[[:space:]]*"
# define POS_END	",[[:digit:].-]+\\)[[:space:]]*$"
# define POS_NEXT	"\\([[:digit:].-]+,[[:digit:].-]+" POS_END
# define COLOR_REG	"^[[:space:]]*color[[:space:]]*=[[:space:]]*0x"
# define COLOR_NEXT	"[[:digit:]A-F]{1,8}[[:space:]]*$"
# define DISTANCE_REG	"^[[:space:]]*distance[[:space:]]*=[[:space:]]*"
# define DISTANCE_NEXT	"[[:digit:].-]+[[:space:]]*$"
# define NBR_REG	"[[:digit:].-]+[[:space:]]*$"
# define AMB_REG	"^[[:space:]]*ambiant[[:space:]]*=[[:space:]]*"
# define DIF_REG	"^[[:space:]]*diffuse[[:space:]]*=[[:space:]]*"
# define SPEC_REG	"^[[:space:]]*specular[[:space:]]*=[[:space:]]*"
# define SPEC_RAD_REG	"^[[:space:]]*spe_radius[[:space:]]*=[[:space:]]*"
# define BRIGHT_REG	"^[[:space:]]*brightness[[:space:]]*=[[:space:]]*"
# define OPAC_REG	"^[[:space:]]*opacity[[:space:]]*=[[:space:]]*"
# define REFRAC_REG	"^[[:space:]]*refraction[[:space:]]*=[[:space:]]*"
# define REFLEC_REG	"^[[:space:]]*reflection[[:space:]]*=[[:space:]]*"
# define INTENSITY	"^[[:space:]]*intensity[[:space:]]*=[[:space:]]*"
# define RENDER_METHOD	"^[[:space:]]*render_method[[:space:]]*=[[:space:]]*"
# define TEXTURE_REG	"^[[:space:]]*<texture[[:space:]]+type[[:space:]]*=\""
# define TEXTURE_NEXT	"(map|bump|procedural)\"[[:space:]]*>[[:space:]]*$"
# define TEXTURE_CLOSE	"^[[:space:]]*</texture>[[:space:]]*$"
# define HYPER_PARAM(a)	"^[[:space:]]*"a"[[:space:]]*=[[:space:]]*"
# define MATRIX_NEXT	":space:]]*\\[(\\-?[[:digit:].]+[,]?){9,9}\\][[:space:]]*$"
# define MATRIX		"^[[:space:]]*filter[[:space:]]*=[[" MATRIX_NEXT
# define FILTER_MODE	"^[[:space:]]*filter_mode[[:space:]]*=[[:space:]]*"
# define ERR_NEXT	pars->line) * -1
# define ERR_PARSER(s)	fprintf(stderr, "Invalid XML ("s") line %i\n", ERR_NEXT
# define UNUSED		__attribute__((unused))

typedef struct	s_parser
{
  regex_t	regex[30];
  regmatch_t	reg_struct;
  t_object	*act_list;
  char		*buf;
  int		fd;
  int		level;
  int		line;
}		t_parser;

char		*get_next_line(const int fd);
char		*my_realloc(char *ptr, int new_size);
int		my_strncpy(char *src, char *dest, int n);
int		init_buffer(char *buffer, int size);
int		extract_line(char *buffer, char *line);
int		search_for_char(char *buffer);
int		check_neg(char *s);
int		check_base(char *base, int n);
int		my_getnbr_base(char *str, char *base);
int		parse_coord(t_system *sys, t_parser *pars);
int		parse_coord_close(t_system *sys, t_parser *pars);
int		parse_eye(t_system *sys, t_parser *pars);
int		parse_eye_close(t_system *sys, t_parser *pars);
int		parse_limit(t_system *sys, t_parser *pars);
int		parse_limit_close(t_system *sys, t_parser *pars);
int		parse_scene(t_system *sys, t_parser *pars);
int		parse_scene_close(t_system *sys, t_parser *pars);
int		parse_mesh(t_system *sys, t_parser *pars);
int		parse_mesh_close(t_system *sys, t_parser *pars);
int		parse_obj(t_system *sys, t_parser *pars);
int		parse_obj_close(t_system *sys, t_parser *pars);
int		parse_phong(t_system *sys, t_parser *pars);
int		parse_phong_close(t_system *sys, t_parser *pars);
int		parse_spot(t_system *sys, t_parser *pars);
int		parse_spot_close(t_system *sys, t_parser *pars);
t_vector3	get_vector(char *buf);
int		get_color_parser(char *buf);
int		get_nbr_parser(char *buf);
double		get_double_parser(char *buf);
int		check_extension(char *file);
int		init_functions(int (**func)());
int		follow_pattern(t_parser *pars, t_system *sys);
int		init_rules(regex_t *regex);
int		get_objects(t_system *sys, char *file);
int		parse_texture(t_system *sys, t_parser *pars);
int		parse_texture_close(t_system *sys, t_parser *pars);
int		mesh_sphere(t_system *sys, t_parser *pars);
int		mesh_plane(t_system *sys, t_parser *pars);
int		mesh_tore(t_system *sys, t_parser *pars);
int		mesh_holedcube(t_system *sys, t_parser *pars);
int		mesh_cone(t_system *sys, t_parser *pars);
void		get_name(t_parser *pars, char *file);
int		parse_texture_map(t_system *sys, t_parser *pars);
int		parse_texture_bump(t_system *sys, t_parser *pars);

#endif /* !GET_NXT_LINE_H_  */
