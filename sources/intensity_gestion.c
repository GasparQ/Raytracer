/*
** intensity_gestion.c for function for the light intensity in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sat May 30 14:00:16 2015 quentin gasparotto
** Last update Fri Jun  5 18:00:08 2015 quentin gasparotto
*/

#include "prototypes.h"

void		light_solver(t_vector3 *use_vectors, t_scene *scene,
			     t_object *act_obj)
{
  double	intensity;

  intensity = get_intensity(scene, act_obj, use_vectors);
  if (scene->act_image->render_method == &cell_shade_method)
    intensity = (1.5 * (int)((10.0 * intensity) / 1.5)) / 10.0;
  apply_phong(act_obj, intensity, scene);
  resolve_brightness(act_obj, scene, scene->act_image->bpp / 8);
  scene->act_intensity = intensity;
}

double		get_spot_intensity(t_spot *act_spot, t_object *obj_list,
				   t_streight light)
{
  int		tell;
  double	intensity;
  t_object	*hide;

  tell = 0;
  intensity = 0;
  while ((hide = get_object(obj_list, &light)) != NULL &&
	 light.lambda > F_ZERO && light.lambda < 1)
    {
      ++tell;
      if (hide->phong.opacity > F_ZERO)
	{
	  intensity += (act_spot->i * (1 - hide->phong.opacity));
	  light.point = get_isec_point(light, hide);
	}
      else
	return (0);
    }
  return ((tell == 0) ? act_spot->i : intensity);
}

void	apply_phong(t_object *touch, double intensity, t_scene *scene)
{
  int	rank;

  rank = 0;
  while (rank < scene->act_image->bpp / 8)
    {
      if ((double)touch->disp_color[rank] * intensity > 0xFF)
	touch->disp_color[rank] = 0xFF;
      else if ((double)touch->disp_color[rank] * intensity < 0x00)
	touch->disp_color[rank] = 0x00;
      else
	touch->disp_color[rank] *= intensity;
      ++rank;
    }
}

double		get_intensity(t_scene *scene, t_object *touch,
			      t_vector3 *use_vectors)
{
  t_spot	*tmp;
  double	sums[2];
  double        intensity;
  t_streight	light;
  t_streight	ref;

  sums[0] = 0;
  sums[1] = 0;
  tmp = scene->spot_list;
  while (tmp != NULL)
    {
      light.dir = get_vec_from_points(use_vectors[1], tmp->origin);
      light.point = use_vectors[1];
      intensity = get_spot_intensity(tmp, scene->obj_list, light);
      sums[0] += intensity * get_vec_cos(use_vectors[0], light.dir);
      ref = get_reflected_ray(unit_vec(use_vectors[0]),
			      light.dir,
			      use_vectors[1]);
      sums[1] += intensity * pow(get_vec_cos(ref.dir, use_vectors[2]),
				 touch->phong.spe_rad);
      resolve_brightness(touch, scene, scene->act_image->bpp / 8);
      tmp = tmp->next;
    }
  return (touch->phong.ambiant + touch->phong.diffuse * sums[0] +
	  touch->phong.specular * sums[1]);
}
