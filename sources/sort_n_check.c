/*
** sort_n_check.c for sort and check a poly tab in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sat Mar 21 16:13:17 2015 quentin gasparotto
** Last update Sat Mar 21 17:03:48 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void		sort_n_check(double tab[2])
{
  double	transition;

  if (tab[0] == -4000000000 || tab[0] < 0)
    tab[0] = -1.0;
  if (tab[1] == -4000000000 || tab[1] < 0)
    tab[1] = -1.0;
  if (tab[1] < tab[0])
    {
      transition = tab[0];
      tab[0] = tab[1];
      tab[1] = transition;
    }
}
