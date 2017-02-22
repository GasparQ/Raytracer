/*
** make_action.c for functions in fptr for the actions in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Mon Jun  1 21:12:02 2015 quentin gasparotto
** Last update Fri Jun  5 15:15:28 2015 quentin gasparotto
*/

#include "prototypes.h"

void	exit_ray_tracer(t_system *sys)
{
  free_scene(sys->scene_list);
  exit(3);
}

void	next_scene(t_system *sys)
{
  sys->act_scene = sys->act_scene->next;
  sys->act_scene->act_image = sys->act_scene->img;
}

void	prev_scene(t_system *sys)
{
  sys->act_scene = sys->act_scene->prev;
  sys->act_scene->act_image = sys->act_scene->img;
}

void	next_img(t_system *sys)
{
  if (sys->act_scene->act_image->next != NULL)
    sys->act_scene->act_image = sys->act_scene->act_image->next;
}

void	prev_img(t_system *sys)
{
  if (sys->act_scene->act_image->prev != NULL)
    sys->act_scene->act_image = sys->act_scene->act_image->prev;
}
