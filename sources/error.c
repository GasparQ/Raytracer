/*
** error.c for error_gestion in /home/gaspar_q/rendu/Igraph/MUL_2014_rtv1/sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Feb  3 16:34:28 2015 quentin gasparotto
** Last update Wed Feb 11 16:12:41 2015 quentin gasparotto
*/

#include "prototypes.h"

int	my_strerror(char *error)
{
  my_put_error(error);
  return (ERROR);
}
