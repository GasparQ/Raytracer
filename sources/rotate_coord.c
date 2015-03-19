/*
** rotate_coord.c for function to rotate any coord from vector3 rotation in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sat Feb 14 15:37:39 2015 quentin gasparotto
** Last update Fri Mar 13 14:27:22 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void	x_rotate(t_vector3 coord, double angle, t_vector3 *ret)
{
  ret->y = coord.y * cos(angle) - coord.z * sin(angle);
  ret->z = coord.y * sin(angle) + coord.z * cos(angle);
}

void	y_rotate(t_vector3 coord, double angle, t_vector3 *ret)
{
  ret->x = coord.x * cos(angle) + coord.z * sin(angle);
  ret->z = -coord.x * sin(angle) + coord.z * cos(angle);
}

void	z_rotate(t_vector3 coord, double angle, t_vector3 *ret)
{
  ret->x = coord.x * cos(angle) - coord.y * sin(angle);
  ret->y = coord.x * sin(angle) + coord.y * cos(angle);
}

void	invert_rotate_coord(t_vector3 *coord, t_vector3 axis_rotation)
{
  z_rotate(*coord, -axis_rotation.z * M_PI / 180.0, coord);
  y_rotate(*coord, -axis_rotation.y * M_PI / 180.0, coord);
  x_rotate(*coord, -axis_rotation.x * M_PI / 180.0, coord);
}

void	rotate_coord(t_vector3 *coord, t_vector3 axis_rotation)
{
  x_rotate(*coord, axis_rotation.x * M_PI / 180.0, coord);
  y_rotate(*coord, axis_rotation.y * M_PI / 180.0, coord);
  z_rotate(*coord, axis_rotation.z * M_PI / 180.0, coord);
}
