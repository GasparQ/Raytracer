/*
** unit_vec.c for unitarise vecteur in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Thu Mar 19 17:45:17 2015 quentin gasparotto
** Last update Tue Mar 24 18:15:03 2015 quentin gasparotto
*/

#include "prototypes.h"

t_vector3	unit_vec(t_vector3 vec)
{
  double	lambda;
  t_vector3	united_vec;

  lambda = 1.0 / sqrt(pow(vec.x, 2.0) + pow(vec.y, 2.0) + pow(vec.z, 2.0));
  united_vec.x = lambda * vec.x;
  united_vec.y = lambda * vec.y;
  united_vec.z = lambda * vec.z;
  return (united_vec);
}
