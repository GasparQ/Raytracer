/*
** my.h for  in /home/veyrie_f/rendu/MUL_2014_rtracer/parser
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sat May 30 20:49:01 2015 fernand veyrier
** Last update Sat May 30 20:53:42 2015 fernand veyrier
*/

#ifndef MY_H_
# define MY_H_

int		my_strncpy(char *src, char *dest, int n);
int		init_buffer(char *buffer, int size);
int		search_for_char(char *buffer);
char		*my_realloc(char *ptr, int new_size);
char		*get_line(char *save_char, int rank, char *char_read, int rank_read);
char		*read_file(const int fd, int *rank_read, int nb_read);
char		*get_next_line(const int fd);
int		main(int ac, char **av);
int		init(char *base, int *nbr, int *j, int *i);

#endif /* !MY_H_ */
