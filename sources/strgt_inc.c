/*
** strgt_inc.c for strgt incrementation in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Jun  2 12:41:44 2015 quentin gasparotto
** Last update Tue Jun  2 12:44:21 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void	init_streight(t_streight *strgt, double dist, int x, int y)
{
  strgt->dir.x = dist;
  strgt->dir.y = WDW_WIDTH / 2.0 - (double)x;
  strgt->dir.z = WDW_HEIGHT / 2.0 - (double)y;
}

void	increment_strgt(t_streight *strgt, t_vector3 save, int i)
{
  strgt->point = save;
  strgt->dir.y += (i % 3) * 0.25;
  strgt->dir.z += (i / 3) * 0.25;
}
