/*
** get_next_line.h for get next line in /home/gaspar_q/rendu/CPE_2014_get_next_line/include
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Mon Nov 17 15:16:33 2014 quentin gasparotto
** Last update Tue May 26 17:37:14 2015 fernand veyrier
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

# define	LINE_LEN 4096

char	*get_next_line(const int fd);
char	*my_realloc(char *ptr, int new_size);
int	my_strncpy(char *src, char *dest, int n);
int	init_buffer(char *buffer, int size);
int	extract_line(char *buffer, char *line);
int	search_for_char(char *buffer);

#endif /* !GET_NEXT_LINE_H_  */
