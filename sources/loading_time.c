/*
** loading_time.c for function for the load of each eyes in each scenes in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Sat May 30 20:46:53 2015 quentin gasparotto
** Last update Sun Jun  7 14:25:49 2015 quentin gasparotto
*/

#include <pthread.h>
#include "minilibx_system.h"
#include "prototypes.h"

int             g_percent = 0;
t_system        *g_sys = NULL;

void *output_load(void *sys)
{
    int      nb_per;
    t_system *sys1;
    int      res;

    res = g_percent <= 100;
    sys1 = (t_system *) sys;
    while (res)
    {
        nb_per = g_percent / 10;
        res    = g_percent <= 100;
        safe_put_image(sys1, sys1->load[nb_per].img, (WDW_WIDTH / 2) - 240, (WDW_HEIGHT / 2) - 240);
    }
    return 0;
}

void next_load_part()
{
    if (!g_sys)
        return;
    safe_put_image(g_sys, g_sys->load[g_percent / 10].img, (WDW_WIDTH / 2) - 240, (WDW_HEIGHT / 2) - 240);
    g_percent += 10;
}

void loading_screen(int init)
{
    g_percent = g_percent + 10 * init;
}

void sig_1(int i)
{
    (void) i;
    loading_screen(1);
}

void launch_scene(t_system *sys, t_scene *scene)
{
    scene->act_image = scene->img;
    scene->act_eye   = scene->eye;
    while (scene->act_eye != NULL)
    {
        g_percent = 0;
        load_image(scene, get_vector2(0, 0), get_vector2(WDW_WIDTH, WDW_HEIGHT));
        if (scene->act_image->render_method == &antialias_method)
            resolve_effects(scene->act_image, scene, &resolve_antialiased_color);
        else if (scene->act_image->render_method == &cell_shade_method)
            resolve_effects(scene->act_image, scene, &resolve_cell_shading);
        safe_put_image(sys, scene->act_image->img, 0, 0);
        apply_filter(scene->act_image, scene);
        safe_put_image(sys, scene->act_image->img, 0, 0);
        scene->act_eye   = scene->act_eye->next;
        scene->act_image = scene->act_image->next;
    }
}

void loading_time(t_system *sys)
{
    t_scene   *scene;

    signal(SIGUSR1, &sig_1);
    loading_screen(0);
    g_sys = sys;
    scene = sys->scene_list->next;
    launch_scene(sys, sys->scene_list);
    while (scene != sys->scene_list)
    {
        launch_scene(sys, scene);
        scene = scene->next;
    }
    g_percent = 101;
}
