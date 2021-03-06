/*
** rtv1.c for rtv1 main function in /home/gaspar_q/rendu/Igraph/MUL_2014_rtv1/sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Feb  3 16:31:47 2015 quentin gasparotto
** Last update Sun Jun  7 23:21:39 2015 quentin gasparotto
*/

#include "minilibx_system.h"
#include "prototypes.h"

int main(int ac, char **av, char **env)
{
    t_system sys;

    (void) ac;
    (void) av;
    if (env[0] == NULL)
        return (my_strerror(ENV_FAIL));
    safe_init();
    if (init_system(&sys, av[1]) == -1)
        return (my_strerror("Init fail\n"));
    loading_time(&sys);
    write_file("list.txt", NULL);
    sys.act_scene            = sys.scene_list;
    sys.act_scene->act_image = sys.act_scene->img;
    mlx_hook(sys.wdw, KeyPress, KeyPressMask, &key_gestion, &sys);
    mlx_expose_hook(sys.wdw, &expose_gestion, &sys);
    mlx_loop(sys.mlx);
    return (CLEAN);
}
