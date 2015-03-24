/*
** get_properties.c for get properties of the object in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sat Mar 14 13:09:31 2015 quentin gasparotto
** Last update Tue Mar 24 19:34:01 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

double		*get_properties(double brightness,
				double opacity, double reflect,
				double middle_ind)
{
  double	*properties_tab;

  if ((properties_tab = malloc(sizeof(double) * 4)) == NULL)
    exit(my_strerror(MALLOC_ERR));
  properties_tab[0] = brightness;
  properties_tab[1] = opacity;
  properties_tab[2] = reflect;
  properties_tab[3] = middle_ind;
  return (properties_tab);
}
