/*
** get_limit.c for get limits in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Fri Mar 13 19:00:16 2015 quentin gasparotto
** Last update Fri Mar 13 19:01:42 2015 quentin gasparotto
*/

#include "prototypes.h"

t_vector3	*get_limit(t_vector3 *limit, t_vector3 f, t_vector3 s)
{
  limit[0] = f;
  limit[1] = s;
  return (limit);
}
