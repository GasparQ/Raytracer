/*
** get_spot_nb.c for get the nb of spots; in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Fri Mar 13 14:08:35 2015 quentin gasparotto
** Last update Fri May 29 11:53:53 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int		get_spot_nb(t_spot *spot_list)
{
  t_spot	*tmp;
  int		i;

  tmp = spot_list;
  i = 0;
  while (tmp != NULL)
    {
      i = i + 1;
      tmp = tmp->next;
    }
  return (i);
}
