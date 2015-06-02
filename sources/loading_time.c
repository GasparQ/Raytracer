#include "../include/minilibx_system.h"
#include "../include/prototypes.h"

void		loading_time(t_system *sys)
{
  t_scene	*scene;

  scene = sys->scene_list;
  duplicate_obj(sys->scene_list->obj_list, sys->scene_list->img->bpp);
  while (scene != NULL)
    {
      scene->act_image = scene->img;
      scene->act_eye = scene->eye;
      while (scene->act_image != NULL)
	{
	  load_image(scene, get_vector2(0, 0),
		     get_vector2(WDW_WIDTH, WDW_HEIGHT));
	  if (scene->act_image->render_method == &antialias_method)
	    resolve_effects(scene->act_image, scene,
	  		    &resolve_antialiased_color);
	  else if (scene->act_image->render_method == &cell_shade_method)
	    resolve_effects(scene->act_image, scene, &resolve_cell_shading);
	  mlx_put_image_to_window(sys->mlx, sys->wdw,
				  scene->act_image->img, 0, 0);
	  scene->act_eye = scene->act_eye->next;
	  scene->act_image = scene->act_image->next;
	}
      scene = scene->next;
    }
}
