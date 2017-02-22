/*
** translate.c for function to translate coor in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sat Feb 14 16:30:56 2015 quentin gasparotto
** Last update Fri Mar 13 14:31:27 2015 quentin gasparotto
*/

#include "prototypes.h"

void	invert_translate(t_vector3 *coord, t_vector3 add_fact)
{
  coord->x -= add_fact.x;
  coord->y -= add_fact.y;
  coord->z -= add_fact.z;
}

void	translate(t_vector3 *coord, t_vector3 add_fact)
{
  coord->x += add_fact.x;
  coord->y += add_fact.y;
  coord->z += add_fact.z;
}
