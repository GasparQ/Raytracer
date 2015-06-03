/*
** make_action_next.c for actions next in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Jun  2 17:27:10 2015 quentin gasparotto
** Last update Wed Jun  3 18:12:54 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void	save_file(t_system *sys)
{
  if (export_bmp(sys->act_scene->act_image) == -1)
    {
      fprintf(stderr, "Export fail\n");
    }
}

void	send_to_server(t_system *sys)
{
  if (put_to_server() == 0)
    fprintf(stderr, "Online Problem\n");
}
