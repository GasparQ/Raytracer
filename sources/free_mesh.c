/*
** free_mesh.c for free mesh in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Feb 25 12:09:15 2015 quentin gasparotto
** Last update Wed Mar 11 17:26:07 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void	free_sphere(t_mesh obj_mesh)
{
  free(obj_mesh.sphere);
}

void	free_plan(t_mesh obj_mesh)
{
  free(obj_mesh.plan);
}

void	free_cylinder(t_mesh obj_mesh)
{
  free(obj_mesh.cylinder);
}

void	free_cone(t_mesh obj_mesh)
{
  free(obj_mesh.cone);
}

void	free_paraboloid(t_mesh obj_mesh)
{
  free(obj_mesh.paraboloid);
}
