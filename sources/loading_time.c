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

pthread_mutex_t mutex;
int             g_percent = 0;

void *output_load(void *sys)
{
    int      nb_per;
    t_system *sys1;
    int      res;

    pthread_mutex_lock(&mutex);
    res = g_percent <= 100;
    pthread_mutex_unlock(&mutex);
    sys1 = (t_system *) sys;
    while (res)
    {
        pthread_mutex_lock(&mutex);
        nb_per = g_percent / 10;
        res    = g_percent <= 100;
        pthread_mutex_unlock(&mutex);
        safe_put_image(sys1, sys1->load[nb_per].img, (WDW_WIDTH / 2) - 240, (WDW_HEIGHT / 2) - 240);
    }
    return 0;
}

void loading_screen(int init)
{
    pthread_mutex_lock(&mutex);
    g_percent = g_percent + 10 * init;
    pthread_mutex_unlock(&mutex);
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
        pthread_mutex_lock(&mutex);
        g_percent = 0;
        pthread_mutex_unlock(&mutex);
        load_image(scene, get_vector2(0, 0), get_vector2(WDW_WIDTH, WDW_HEIGHT));
        pthread_mutex_lock(&mutex);
        if (scene->act_image->render_method == &antialias_method)
            resolve_effects(scene->act_image, scene, &resolve_antialiased_color);
        else if (scene->act_image->render_method == &cell_shade_method)
            resolve_effects(scene->act_image, scene, &resolve_cell_shading);
        pthread_mutex_unlock(&mutex);
        safe_put_image(sys, scene->act_image->img, 0, 0);
        pthread_mutex_lock(&mutex);
        apply_filter(scene->act_image, scene);
        pthread_mutex_unlock(&mutex);
        safe_put_image(sys, scene->act_image->img, 0, 0);
        scene->act_eye   = scene->act_eye->next;
        scene->act_image = scene->act_image->next;
    }
}

void loading_time(t_system *sys)
{
    t_scene   *scene;
    pthread_t t1;
    void      *ret;

    signal(SIGUSR1, &sig_1);
    loading_screen(0);
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&t1, NULL, output_load, (void *) sys);
    scene = sys->scene_list->next;
    launch_scene(sys, sys->scene_list);
    while (scene != sys->scene_list)
    {
        launch_scene(sys, scene);
        scene = scene->next;
    }
    pthread_mutex_lock(&mutex);
    g_percent = 101;
    pthread_mutex_unlock(&mutex);
    pthread_join(t1, &ret);
}
