/*
** minilibx_system.h for minilibx system in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1/include
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Feb 11 16:05:05 2015 quentin gasparotto
** Last update Fri Mar 13 15:56:03 2015 quentin gasparotto
*/

#ifndef MINILIBX_SYS_H_
# define MINILIBX_SYS_H_

# include "mesh.h"

typedef struct	s_image
{
  void		*img;
  char		*dat;
  int		bpp;
  int		wdth;
  int		hght;
  int		edn;
}		t_image;

typedef struct	s_system
{
  void		*mlx;
  void		*wdw;
  t_image	img;
  t_image	load;
  t_eye		eye;
  unsigned char	*color;
  t_object	*obj_list;
  t_spot	*spot_list;
  int		spot_nb;
  t_object	*select;
  int		*average;
}		t_system;

#endif /* !MINILIBX_SYS_H_ */
