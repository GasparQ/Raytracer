/*
** scalaire.c for calc the scal in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Mon Feb 16 16:33:20 2015 quentin gasparotto
** Last update Mon Feb 16 16:36:50 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

double		get_scal(t_vector3 f_vec, t_vector3 s_vec)
{
  double	scal;

  scal = f_vec.x * s_vec.x + f_vec.y * s_vec.y + f_vec.z * s_vec.z;
  return (scal);
}

double		vec_norm(t_vector3 vec)
{
  double	norm;

  norm = sqrt(pow(vec.x, 2.0) + pow(vec.y, 2.0) + pow(vec.z, 2.0));
  return (norm);
}
