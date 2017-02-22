/*
** get_vec_cos.c for get an angle from 2 vectors in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sat Mar 14 17:54:55 2015 quentin gasparotto
** Last update Sat Mar 14 21:33:56 2015 quentin gasparotto
*/

#include "prototypes.h"

double		get_vec_cos(t_vector3 f, t_vector3 s)
{
  return (get_scal(f, s) / (vec_norm(f) * vec_norm(s)));
}
