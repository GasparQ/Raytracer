/*
** get_streight.c for get streight in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Mon Feb 16 22:39:38 2015 quentin gasparotto
** Last update Mon Feb 16 23:30:25 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

t_streight	get_streight(t_vector3 dir, t_vector3 pos)
{
  t_streight	streight;

  streight.point.x = pos.x;
  streight.point.y = pos.y;
  streight.point.z = pos.z;
  streight.dir.x = dir.x;
  streight.dir.y = dir.y;
  streight.dir.z = dir.z;
  return (streight);
}
