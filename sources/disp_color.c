/*
** disp_color.c for disp color in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1/sources
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Thu Mar 12 11:48:17 2015 quentin gasparotto
** Last update Sun Jun  7 14:30:22 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void		cell_shade_method(void *send_scene, t_vector2 pos,
				  t_streight strgt)
{
  basic_method(send_scene, pos, strgt);
}

void		recup_avg(t_scene *scene, t_streight *strgt,
			  int *final_intensity)
{
  t_object	*final_obj;

  scene->act_intensity = 0;
  final_obj = get_object(scene->obj_list, strgt);
  if (final_obj != NULL)
    {
      final_obj->effects = 0;
      resolve_light(get_isec_point(*strgt, final_obj), final_obj,
		    scene, *strgt);
      add_color_to_avg(final_obj->disp_color, scene->act_image->average,
		       scene->act_image->bpp / 8, 1);
    }
  else
    add_color_to_avg(scene->act_image->color, scene->act_image->average,
		     scene->act_image->bpp / 8, 1);
  (*final_intensity) += scene->act_intensity;
}

void	        antialias_method(void *send_scene, t_vector2 pos,
				 t_streight strgt)
{
  int		i;
  t_scene	*scene;
  t_vector3	save_point;
  int		final_intensity;

  save_point = strgt.point;
  scene = (t_scene *)send_scene;
  init_average(scene->act_image->average, scene->act_image->bpp / 8);
  final_intensity = 0;
  i = -1;
  while (++i < 9)
    {
      increment_strgt(&strgt, save_point, i);
      recup_avg(scene, &strgt, &final_intensity);
    }
  scene->act_image->i_tab[(int)pos.y * scene->act_image->wdth / 4 +
			  (int)pos.x] = final_intensity / 9;
  choose_color(scene->act_image, scene->act_image, pos, 1);
}

void		basic_method(void *send_scene, t_vector2 pos, t_streight strgt)
{
  t_scene	*scene;
  t_object	*final_obj;

  scene = (t_scene *)send_scene;
  strgt.dir.y += 0.25;
  strgt.dir.z += 0.25;
  scene->act_intensity = 0;
  final_obj = get_object(scene->obj_list, &strgt);
  if (final_obj != NULL)
    {
      final_obj->effects = 0;
      resolve_light(get_isec_point(strgt, final_obj), final_obj, scene, strgt);
      my_put_pixel_to_img((int)pos.x, (int)pos.y,
			  final_obj->disp_color, scene->act_image);
    }
  else
    my_put_pixel_to_img((int)pos.x, (int)pos.y,
			scene->act_image->color, scene->act_image);
  scene->act_image->i_tab[(int)pos.y * scene->act_image->wdth / 4 +
			  (int)pos.x] = scene->act_intensity;
}

void		disp_color(t_scene *scene, int x, int y)
{
  t_streight	strgt;

  init_streight(&strgt, scene->act_eye->distance, x, y);
  rotate_coord(&(strgt.dir), scene->act_eye->dir);
  strgt = get_streight(strgt.dir, scene->act_eye->pos);
  strgt.dir.y -= 0.25;
  strgt.dir.z -= 0.25;
  scene->act_image->render_method(scene, get_vector2(x, y), strgt);
}
