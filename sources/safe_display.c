//
// Created by gaspar-q on 22/02/17.
//

#include <sys/types.h>
#include <pthread.h>
#include <mlx.h>
#include <minilibx_system.h>

pthread_mutex_t mutex;

void safe_put_image(t_system *sys, void *img, int x, int y)
{
    pthread_mutex_lock(&mutex);
    mlx_put_image_to_window(sys->mlx, sys->wdw, img, x, y);
    pthread_mutex_unlock(&mutex);
}

void safe_init()
{
    pthread_mutex_init(&mutex, NULL);
}

void safe_clear(t_system *sys)
{
    pthread_mutex_lock(&mutex);
    mlx_clear_window(sys->mlx, sys->wdw);
    pthread_mutex_unlock(&mutex);
}