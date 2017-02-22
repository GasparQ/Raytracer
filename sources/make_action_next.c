/*
** make_action_next.c for actions next in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Jun  2 17:27:10 2015 quentin gasparotto
** Last update Sat Jun  6 12:22:18 2015 quentin gasparotto
*/

#include "prototypes.h"

void	save_file(t_system *sys)
{
  if (export_bmp(sys->act_scene->act_image) == -1)
    {
      fprintf(stderr, "Export fail\n");
    }
}

void	send_to_server(UNUSED t_system *sys)
{
  if (put_to_server() == 1)
    fprintf(stderr, "Online Problem\n");
}

void		send_scene(t_scene *scene)
{
  t_image	*img;

  img = scene->img->next;
  if (export_bmp(scene->img) == -1)
    fprintf(stderr, "Export fail\n");
  while (img != scene->img)
    {
      if (export_bmp(scene->img) == -1)
	fprintf(stderr, "Export fail\n");
      img = img->next;
    }
}

void		save_and_send(t_system *sys)
{
  t_scene	*scene;

  scene = sys->scene_list->next;
  send_scene(sys->scene_list);
  while (scene != sys->scene_list)
    {
      send_scene(scene);
      scene = scene->next;
    }
  send_to_server(sys);
}
