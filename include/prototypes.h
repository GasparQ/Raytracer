/*
** minilibx_objects.h for rtv1 in /home/gaspar_q/rendu/Igraph/MUL_2014_rtv1/include
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Tue Feb  3 16:30:16 2015 quentin gasparotto
** Last update Fri Mar 20 20:22:42 2015 fernand veyrier
*/

#ifndef SYS_LIBX_H_
# define SYS_LIBX_H_

# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "/usr/include/X11/X.h"
# include "minilibx_system.h"

# define CLEAN		0
# define ERROR          -1
# define CLEARLY	3

# define MALLOC_ERR	"Malloc error\n"
# define MLX_FAIL	"Minilib X loading fail\n"
# define WDW_FAIL	"Window loading fail\n"
# define ENV_FAIL	"No environment\n"

# define F_ZERO		0.00001

# define WDW_WIDTH	1920
# define WDW_HEIGHT	1080

# define ESCAPE		65307
# define UP		65362
# define DOWN		65364
# define RIGHT		65363
# define LEFT		65361
# define RETURN		65293
# define Z_KEY	        0x007a
# define S_KEY		0x0073

# define ORIGIN		get_vector3(0, 0, 0)
# define SIMPLE		get_properties(0, 0, 0)

enum	COLORS
  {
    BLACK = 0x00000000,
    WHITE = 0x00FFFFFF,
    RED = 0x00FF0000,
    GREEN = 0x0000FF00,
    BLUE = 0x000000FF,
    YELLOW = 0x00FFFF00,
    MAGENTA = 0x00FF00FF,
    CYAN = 0x0000FFFF,
    BLUE_GREY = 0x009CF2FF,
    FLOOR= 0x004F51B0,
    PARAB= 0xFF0045,
    BOLAS= 0xDC6000,
    CONAS= 0x5E323C,
    SOLAS= 0xBA004A,
    CYL= 0xDC2400,
  };

/*
**	get_min_root.c
*/

double	get_min(double *roots, int size);

/*
**	unit_vec.c
*/

t_vector3	unit_vec(t_vector3 vec);

/*
**	extract_point.c
*/

t_vector3	extract_point(t_streight ray);

/*
**	get_vec_angle.c
*/

double	get_vec_cos(t_vector3 f, t_vector3 s);

/*
**	get_reflected_ray.c
*/

t_streight	get_reflected_ray(t_vector3 norm,
				  t_vector3 incident_ray,
				  t_vector3 point);

/*
**	get_properties.c
*/

double	*get_properties(double brightness, double opacity, double reflect);

/*
**	get_limit.c
*/

t_vector3	*get_limit(t_vector3 *limit, t_vector3 f, t_vector3 s);

/*
**	get_spot_nb.c
*/

int	get_spot_nb(t_system *sys);

/*
**	disp_color.c
*/

void	disp_color(t_system *sys, int x, int y);

/*
**	resolve_polynoms.c
*/

void	resolve_polynoms(double *param, double *k_tab);

/*
**	get_isec_point.c
*/

t_vector3	get_isec_point(t_streight streight, t_object *my_obj);

/*
**	average.c
*/

void	add_average(t_system *sys, t_spot *tmp,
		    double cos_a, t_object *act_obj);
void	init_average(int *average, int end);
void	average_to_color(int *average, unsigned char *color, int nb, int end);

/*
**      loading_screen.c
*/

void	init_load_img(t_system *sys, t_image *load_img);

/*
**      cartoonising.c
*/

void    cartoonising(t_system *sys);

/*
**	cmp_limit.c
*/

int	comp_limit(t_streight strgt, t_vector3 limit[2]);

/*
**	free_mesh.c
*/

void	free_sphere(t_mesh obj_mesh);
void	free_plan(t_mesh obj_mesh);
void	free_cylinder(t_mesh obj_mesh);
void	free_cone(t_mesh obj_mesh);
void	free_paraboloid(t_mesh obj_mesh);

/*
**	free_mesh_next.c
*/

void	free_holed_cube(t_mesh obj_mesh);

/*
**	add_paraboloid.c
*/

int	add_paraboloid(t_system *sys, double cte, int color);

/*
**	add_cone.c
*/

int	add_cone(t_system *sys, double phi, int color, t_vector3 limit[2]);

/*
**	add_cylinder.c
*/

int	add_cylinder(t_system *sys, double radius,
		     int color, t_vector3 limit[2]);

/*
**	add_holed_cube.c
*/

int	add_holed_cube(t_system *sys, double size, int color);

/*
**	add_object.c
*/

void	add_object(t_system *sys, t_vector3 origin,
		   t_vector3 rotation, double *properties);

/*
**	get_vector3.c
*/

t_vector3	get_vec_from_points(t_vector3 a_point, t_vector3 b_point);
t_vector3	get_vector3(double x, double y, double z);

/*
**	get_streight.c
*/

t_streight	get_streight(t_vector3 dir, t_vector3 pos);

/*
**	scalaire.c
*/

double	get_scal(t_vector3 f_vec, t_vector3 s_vec);
double	vec_norm(t_vector3 vec);

/*
**	resolve_light.c
*/

void	resolve_light(t_vector3 isec_point,
		      t_object *act_object,
		      t_system *sys, t_streight strgt);
void	resolve_brightness(t_object *act_obj, t_spot *act_spot, int rank);

/*
**	obj_norms.c
*/

void	init_sphere_norm(t_vector3 *sphere_norm, t_vector3 isec_point,
			 t_object *obj);
void	init_plan_norm(t_vector3 *plan_norm, t_vector3 isec_point,
		       t_object *obj);
void	init_cylinder_norm(t_vector3 *cylinder_norm, t_vector3 isec_point,
			   t_object *obj);
void	init_cone_norm(t_vector3 *cone_norm, t_vector3 isec_point,
		       t_object *obj);
void	init_paraboloid_norm(t_vector3 *paraboloid_norm, t_vector3 isec_point,
			     t_object *obj);

/*
**	obj_norms_next.c
*/

void	init_holed_cube_norm(t_vector3 *holed_cube_norm, t_vector3 isec_point,
			     t_object *obj);

/*
**	add_spot.c
*/

int	add_spot(t_system *sys, t_vector3 pos, int color);

/*
**	translate.c
*/

void	translate(t_vector3 *coord, t_vector3 add_fact);
void	invert_translate(t_vector3 *coord, t_vector3 add_fact);

/*
**	rotate_coord.c
*/

void	rotate_coord(t_vector3 *coord, t_vector3 axis_rotation);
void	invert_rotate_coord(t_vector3 *coord, t_vector3 axis_rotation);

/*
**	matrice_multiplication.c
*/

t_vector3	mult_mat(t_vector3 coord, t_vector3 *mat);

/*
**	bomb_ray.c
*/

t_object	*bomb_ray(t_streight *ray, t_object *obj_list);

/*
**	add_sphere.c
*/

int	add_sphere(t_system *sys, double rad, int color);

/*
**	add_plan.c
*/

int	add_plan(t_system *sys, int color, double d, t_vector3 norm);

/*
**	objects.c
*/

double	draw_sphere(t_streight strgt, t_object *my_obj);
double	draw_plan(t_streight strgt, t_object *my_obj);
double	draw_cylinder(t_streight strgt, t_object *my_obj);
double	draw_cone(t_streight strgt, t_object *my_obj);
double	draw_paraboloid(t_streight strgt, t_object *my_obj);
double	draw_holed_cube(t_streight strgt, t_object *my_obj);

/*
**	init_system.c
*/

int	init_system(t_system *sys);

/*
**	list_fn.c
*/

int	my_put_in_list(t_object **list, t_object data);
void	free_my_list(t_object *list);
void	free_spot_list(t_spot *list);

/*
**	expose_gestion.c
*/

int	expose_gestion(t_system *sys);

/*
**	graph_func.c
*/

void	my_put_pixel_to_img(int x, int y, unsigned char *color, t_image *img);
void	get_color(int color, unsigned char *color_tab, t_system *sys);

/*
**	error.c
*/

int	my_strerror(char *error);

/*
**	load_image.c
*/

int	load_image(t_system *sys);

/*
**	event_gestion.c
*/

int	expose_gestion(t_system *sys);
int	key_gestion(int keycode, t_system *sys);

/*
**	lib
*/

int	my_strlen(char *str);
void	my_puterrchar(char c);
void	my_put_error(char *str);

#endif /* !SYS_LIBX_H_ */
