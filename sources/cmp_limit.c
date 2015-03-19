/*
** cmp_limit.c for compare isec point to limit point in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Feb 25 14:41:11 2015 quentin gasparotto
** Last update Thu Mar 12 12:13:43 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int		comp_limit(t_streight strgt, t_vector3 limit[2])
{
  t_vector3	isec_point;

  if (strgt.lambda < F_ZERO)
    return (0);
  isec_point.x = strgt.point.x + strgt.lambda * strgt.dir.x;
  isec_point.y = strgt.point.y + strgt.lambda * strgt.dir.y;
  isec_point.z = strgt.point.z + strgt.lambda * strgt.dir.z;
  if (isec_point.z >=  limit[0].z && isec_point.z <= limit[1].z)
    return (1);
  return (0);
}
