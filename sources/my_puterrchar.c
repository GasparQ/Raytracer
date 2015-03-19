/*
** my_puterrchar.c for my_puterrchar in /home/gaspar_q/rendu/Igraph/MUL_2014_rtv1/sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Feb  3 17:02:08 2015 quentin gasparotto
** Last update Tue Feb  3 17:02:38 2015 quentin gasparotto
*/

#include <unistd.h>

void	my_puterrchar(char c)
{
  write(2, &c, 1);
}
