/*
** expose_gestion.c for expose gestion in /home/gaspar_q/rendu/Igraph/MUL_2014_rtv1/sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Feb  3 17:19:37 2015 quentin gasparotto
** Last update Sun Jun  7 19:52:52 2015 quentin gasparotto
*/

#include "minilibx_system.h"
#include "prototypes.h"

static int keycode_action[8] = {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        ESCAPE,
        's',
        RETURN,
        'a'
};

static void (*act[8])(t_system *) = {
        &next_scene,
        &prev_scene,
        &next_img,
        &prev_img,
        &exit_ray_tracer,
        &save_file,
        &send_to_server,
        &save_and_send
};

int key_gestion(int keycode, t_system *sys)
{
    int i;

    i = 0;
    while (i < 8 && keycode_action[i] != keycode)
        ++i;
    if (i < 8)
        act[i](sys);
    if (i < 4)
        safe_put_image(sys, sys->act_scene->act_image->img, 0, 0);
    return (CLEAN);
}

int expose_gestion(t_system *sys)
{
    if (sys->act_scene->act_image != NULL)
        safe_put_image(sys, sys->act_scene->act_image->img, 0, 0);
    return (CLEAN);
}
