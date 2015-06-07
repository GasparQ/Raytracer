/*
** minilibx_system.h for minilibx system in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1/include
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Feb 11 16:05:05 2015 quentin gasparotto
** Last update Sun Jun  7 18:06:55 2015 quentin gasparotto
*/

#ifndef MINILIBX_SYS_H_
# define MINILIBX_SYS_H_

# include "mesh.h"

typedef struct	s_system
{
  void		*mlx;
  void		*wdw;
  t_scene	*scene_list;
  t_scene	*act_scene;
  t_image	load[10];
}		t_system;

#endif /* !MINILIBX_SYS_H_ */
