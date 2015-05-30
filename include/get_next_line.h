/*
** get_next_line.h for get next line in /home/gaspar_q/rendu/CPE_2014_get_next_line/include
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Mon Nov 17 15:16:33 2014 quentin gasparotto
** Last update Sat May 30 13:02:07 2015 fernand veyrier
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
# define EYE		"[[:space:]]*<eye>[[:space:]]*$"
# define EYE_CLOSE	"[[:space:]]*</eye>[[:space:]]*$"
# define POSITION	"[[:space:]]*position[[:space:]]*=[[:space:]]*"
# define ROTATION	"[[:space:]]*rotation[[:space:]]*=[[:space:]]*"
# define POS_NEXT	"\\([[:digit:].]+,[[:digit:].]+,[[:digit:].]+\\)[[:space:]]*$"
# define COLOR_REG	"[[:space:]]*color[[:space:]]*=[[:space:]]*0x"
# define COLOR_NEXT	"[[:digit:]A-F]{,8}[[:space:]]*$"

typedef struct	s_parser
{
  regex_t	regex[20];
  regmatch_t	reg_struct;
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

#endif /* !GET_NEXT_LINE_H_  */
