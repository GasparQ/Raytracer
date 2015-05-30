/*
** parse_mesh.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer/parser
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sat May 30 20:46:43 2015 fernand veyrier
** Last update Sat May 30 20:47:00 2015 fernand veyrier
*/

#include "get_next_line.h"

int		parse_mesh(t_system *sys, t_parser *pars)
{
  if (pars->level < 2)
    return (fprintf(stderr, "Invalid XML (mesh) line %i.\n", pars->line) * -1);
  printf("Found mesh\n");
  return (2);
}

int		parse_mesh_close(t_system *sys, t_parser *pars)
{
  if (pars->level - 2 < 2)
    return (fprintf(stderr, "Invalid XML (mesh) line %i.\n", pars->line) * -1);
  printf("Found mesh close\n");
  return (-2);
}
