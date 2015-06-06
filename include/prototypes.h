/*
** prototypes.h for ray_tracer header in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
**
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
**
** Started on  Wed May 27 12:27:42 2015 quentin gasparotto
** Last update Sat Jun  6 17:33:03 2015 Alban Combaud
*/

#ifndef SYS_LIBX_H_
# define SYS_LIBX_H_

# include		<sys/wait.h>
# include		<unistd.h>
# include		<sys/types.h>
# include		<stdlib.h>
# include		<math.h>
# include		<mlx.h>
# include		"/usr/include/X11/X.h"
# include		"minilibx_system.h"
# include		"mesh.h"
# include		"get_next_line.h"

# define CLEAN		0
# define ERROR          -1
# define CLEARLY	3

# define MALLOC_ERR	"Malloc error\n"
# define MLX_FAIL	"Minilib X loading fail\n"
# define WDW_FAIL	"Window loading fail\n"
# define ENV_FAIL	"No environment\n"

#define ERR_OPEN	"Error: cannot open() file\n"
#define ERR_MLOC	"Error: cannot perform malloc\n"
#define USAGE		"usage : ./wr_file FILE LINE APPEND ? (0:TRUC 1:APPEND)\n"

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
# define SIMPLE		get_properties(0, 0, 0, 0)

# define ABS(i)		((i) < 0) ? -(i) : (i)

# define UNIT(v)	unit_vec((v))

# define REFLECT(v)	get_reflected_ray(UNIT(norm), (v), isec_point)
# define REFRACT(v, i)	get_refracted_ray(UNIT(norm), UNIT(v), isec_point, (i))

enum			COLORS
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
**	limit_detection.c
*/

int			check_border(t_image *image, int x, int y);
int			get_border(t_scene *scene);

/*
**	bumpping.c
*/

void			height_map_bump(t_vector2 text_pos, t_image *bump,
					t_vector3 *norm);
void			bump_map_bump(t_vector2 text_pos, t_image *bump,
				      t_vector3 *norm);

/*
**	plan_texture.c
*/

t_vector2		plane_mapping(t_vector3 isec_point, t_image *texture);
void			plane_bump(t_vector3 isec_point, t_object *touch,
				   t_vector3 *norm);

/*
**	perlin.c
*/

double			noise(t_vector3 point);

/*
**	sphere_texture.c
*/

double			get_bump_height(int x, int y, t_image *texture);
void			sphere_bump(t_vector3 isec_point, t_object *touch,
				    t_vector3 *norm);
t_vector2		sphere_map(t_vector3 isec_point, t_image *texture);
void			sphere_proced(t_vector3 isec_point, t_object *touch);

/*
**	file.c
*/

int			write_file(char *file, char *name);
int			put_to_server();

/*
**	add_texture.c
*/

int			add_proced(t_object *obj, char *filename,
				   t_scene *scene, int *color);
int			add_bump(t_object *obj, char *filename,
				 t_scene *scene, int mode);
int			add_texture(t_object *obj, char *filename,
				    t_scene *scene);

/*
**	obj_texture_next.c
*/

void			basic_color(t_vector3 isec_point, t_vector3 norm,
				    t_object *touch, void *send_scene);
void			text_to_cone(t_vector3 isec_point, t_vector3 norm,
				     t_object *touch, void *send_scene);
void			text_to_cylinder(t_vector3 isec_point, t_vector3 norm,
					 t_object *touch, void *send_scene);
void			text_to_plane(t_vector3 isec_point, t_vector3 norm,
				      t_object *touch, void *send_scene);
void			text_to_sphere(t_vector3 isec_point, t_vector3 norm,
				       t_object *touch, void *scene);

/*
**	load_texture.c
*/

int			load_texture(t_image *text, char *filename, void *mlx);
size_t			strlcpy(char *dst, char *src, size_t dstsize);

/*
**	export_bmp.c
*/

int			export_bmp(t_image *exp_img);

/*
**	strgt_inc.c
*/

void			increment_strgt(t_streight *strgt,
					t_vector3 save, int i);
void			init_streight(t_streight *strgt, double dist,
				      int x, int y);

/*
**	make_action_next.c
*/

void			send_to_server(t_system *sys);
void			save_file(t_system *sys);

/*
**	make_action.c
*/

void			prev_img(t_system *sys);
void			next_img(t_system *sys);
void			prev_scene(t_system *sys);
void			next_scene(t_system *sys);
void			exit_ray_tracer(t_system *sys);

/*
**	duplicate_objects.c
*/

t_object		*duplicate_obj(t_object *obj_list, int bpp, t_scene *scene);

/*
**	effects.c
*/

void			resolve_cell_shading(t_image *act_image,
					     t_image *nice_img,
					     t_vector2 pos);

/*
**	get_object.c
*/

t_object		*get_object(t_object *obj_list, t_streight *strgt);

/*
**	antialiasing.c
*/

int			cmp_colors(unsigned char *color1, unsigned char *color2,
				   int bpp, int limit);
void			choose_color(t_image *act_image, t_image *copy,
				     t_vector2 pos, int tell);
void			add_color_to_avg(unsigned char *color, int *average,
					 int limit);
void			resolve_antialiased_color(t_image *act_image,
						  t_image *nice_img,
						  t_vector2 pos);
int		        resolve_effects(t_image *act_image, t_scene *scene,
					void (*effect)(t_image *,
						       t_image *,
						       t_vector2));

/*
**	loading_time.c
*/

void			loading_time(t_system *sys);

/*
**	intensity_gestion.c
*/

void			light_solver(t_vector3 *use_vectors, t_scene *scene,
				     t_object *act_obj);
double			get_intensity(t_scene *scene, t_object *touch,
				      t_vector3 *use_vectors);
void			apply_phong(t_object *touch, double intensity,
				    t_scene *scene);

/*
**	scene_gestion.c
*/

int			init_img(t_image *img, t_vector2 dim, t_scene *scene, int render);
void			free_scene(t_scene *scene);
int			add_scene(t_scene **scene, void *mlx);
int			add_eye(t_scene *scene, t_vector3 position,
				t_vector3 rotation, double *prop);

/*
**	draw_hyperboloid.c
*/

double			draw_hyperboloid(t_streight strgt, t_object *my_obj);

/*
**	add_hyperboloid.c
*/

int			add_hyperboloid(t_object *act_obj, double *mesh_prop);

/*
**	get_refracted_ray.c
*/

t_streight		get_refracted_ray(t_vector3 norm,
					  t_vector3 incident_ray,
					  t_vector3 point, double coeff);

/*
**	transparency.c
*/

void			resolve_transparency(t_streight refracted_ray,
					     t_object *act, t_scene *scene);

/*
**	draw_moebius.c
*/

double			draw_moebius(t_streight strgt, t_object *my_obj);

/*
**	add_moebius.c
*/

int			add_moebius(t_object *act_obj, double *mesh_prop);

/*
**	add_tore.c
*/

int			add_tore(t_object *act_obj, double *mesh_prop);

/*
**	tore.c
*/

double			draw_tore(t_streight strgt, t_object *my_obj);

/*
**	sort_n_check.c
*/

void			sort_n_check(double tab[2]);

/*
**	tab_cpy.c
*/

void			tab_ncpy(double *src, double *dest, int n);

/*
**	cubic_solver.c
*/

void			cubic_solver(double *param, double *roots);

/*
**	quadratic_solver.c
*/

int			quadratic_solver(double *param, double *roots);

/*
**	get_min_root.c
*/

double			get_min(double *roots, int size);

/*
**	unit_vec.c
*/

t_vector3		unit_vec(t_vector3 vec);

/*
**	extract_point.c
*/

t_vector3		extract_point(t_streight ray);

/*
**	get_vec_angle.c
*/

double			get_vec_cos(t_vector3 f, t_vector3 s);

/*
**	get_reflected_ray.c
*/

t_streight		get_reflected_ray(t_vector3 norm,
					  t_vector3 incident_ray,
					  t_vector3 point);

/*
**	get_properties.c
*/

double			*get_properties(double brightness, double opacity,
					double reflect, double middle_ind);
void			add_phong(t_object *obj, double *phong_prop);
void			add_coord(t_object *obj, double *coord);

/*
**	get_limit.c
*/

t_vector3		*get_limit(t_vector3 *limit, t_vector3 f, t_vector3 s);

/*
**	get_spot_nb.c
*/

int			get_spot_nb(t_spot *sys);

/*
**	disp_color.c
*/

void			cell_shade_method(void *scene, t_vector2 pos,
					  t_streight strgt);
void		        antialias_method(void *scene, t_vector2 pos,
					 t_streight strgt);
void			basic_method(void *scene, t_vector2 pos,
				     t_streight strgt);
void			disp_color(t_scene *scene, int x, int y);

/*
**	resolve_polynoms.c
*/

int			resolve_polynoms(double *param, double *k_tab);

/*
**	get_isec_point.c
*/

t_vector3		get_isec_point(t_streight streight, t_object *my_obj);

/*
**	average.c
*/

void			add_average(t_scene *scene, t_spot *tmp,
				    double cos_a, t_object *act_obj);
void			init_average(int *average, int end);
void			average_to_color(int *average, unsigned char *color,
					 int nb, int end);

/*
**      loading_screen.c
*/

void			init_load_img(t_scene *scene, t_image *load_img);

/*
**	cmp_limit.c
*/

int			comp_limit(t_streight strgt, t_vector3 limit[2]);

/*
**	free_mesh.c
*/

void			free_sphere(t_mesh obj_mesh);
void			free_plan(t_mesh obj_mesh);
void			free_cylinder(t_mesh obj_mesh);
void			free_cone(t_mesh obj_mesh);
void			free_paraboloid(t_mesh obj_mesh);

/*
**	free_mesh_next.c
*/

void			free_holed_cube(t_mesh obj_mesh);
void			free_tore(t_mesh obj_mesh);
void			free_moebius(t_mesh obj_mesh);
void			free_hyperboloid(t_mesh obj_mesh);

/*
**	add_paraboloid.c
*/

int			add_paraboloid(t_object *act_obj, double *mesh_param);

/*
**	add_cone.c
*/

int			add_cone(t_object *act_obj, double *mesh_prop);

/*
**	add_cylinder.c
*/

int			add_cylinder(t_object *act_obj, double *mesh_prop);

/*
**	add_holed_cube.c
*/

int			add_holed_cube(t_object *act_obj, double *mesh_prop);
/* int			add_holed_cube(t_system *sys, double size, int color); */

/*
**	add_obj.c
*/

void			add_object(t_object **obj_list, int size, int color);

/*
**	get_vectors.c
*/

t_vector3		get_positive_point(t_vector3 point);
t_vector3		get_vec_from_points(t_vector3 a_point,
					    t_vector3 b_point);
t_vector3		get_vector3(double x, double y, double z);
t_vector2		get_vector2(double x, double y);

/*
**	get_streight.c
*/

t_streight		get_streight(t_vector3 dir, t_vector3 pos);

/*
**	scalaire.c
*/

double			get_scal(t_vector3 f_vec, t_vector3 s_vec);
double			vec_norm(t_vector3 vec);

/*
**	resolve_light.c
*/

void			resolve_light(t_vector3 isec_point,
				      t_object *act_object,
				      t_scene *scene, t_streight strgt);
void			resolve_brightness(t_object *act_obj,
					   t_scene *scene, int rank);

/*
**	obj_norms.c
*/

void			init_sphere_norm(t_vector3 *sphere_norm,
					 t_vector3 isec_point, t_object *obj);
void			init_plan_norm(t_vector3 *plan_norm,
				       t_vector3 isec_point, t_object *obj);
void			init_cylinder_norm(t_vector3 *cylinder_norm,
					   t_vector3 isec_point, t_object *obj);
void			init_cone_norm(t_vector3 *cone_norm,
				       t_vector3 isec_point, t_object *obj);
void			init_paraboloid_norm(t_vector3 *paraboloid_norm,
					     t_vector3 isec_point,
					     t_object *obj);

/*
**	obj_norms_next.c
*/

void			init_holed_cube_norm(t_vector3 *holed_cube_norm,
					     t_vector3 isec_point,
					     t_object *obj);
void			init_tore_norm(t_vector3 *norm, t_vector3 isec_point,
				       t_object *obj);
void			init_moebius_norm(t_vector3 *norm, t_vector3 isec_point,
					  t_object *obj);
void			init_hyper_norm(t_vector3 *norm,
					t_vector3 isec_point, t_object *obj);

/*
**	add_spot.c
*/

int			add_spot(t_scene *scene, t_vector3 pos, int color, double i);

/*
**	translate.c
*/

void			translate(t_vector3 *coord, t_vector3 add_fact);
void			invert_translate(t_vector3 *coord, t_vector3 add_fact);

/*
**	rotate_coord.c
*/

void			rotate_coord(t_vector3 *coord, t_vector3 axis_rotation);
void			invert_rotate_coord(t_vector3 *coord,
					    t_vector3 axis_rotation);

/*
**	matrice_multiplication.c
*/

t_vector3		mult_mat(t_vector3 coord, t_vector3 *mat);

/*
**	bomb_ray.c
*/

t_object		*bomb_ray(t_streight *ray, t_object *obj_list);

/*
**	add_sphere.c
*/

int			add_sphere(t_object *act_obj, double *mesh_prop);

/*
**	add_plan.c
*/

int			add_plan(t_object *act_obj, double *mesh_prop);

/*
**	objects.c
*/

double			draw_sphere(t_streight strgt, t_object *my_obj);
double			draw_plan(t_streight strgt, t_object *my_obj);
double			draw_cylinder(t_streight strgt, t_object *my_obj);
double			draw_cone(t_streight strgt, t_object *my_obj);
double			draw_paraboloid(t_streight strgt, t_object *my_obj);
double			draw_holed_cube(t_streight strgt, t_object *my_obj);

/*
**	init_system.c
*/

int			init_system(t_system *sys, char *file);

/*
**	list_fn.c
*/

void			free_image_list(t_image *img_list);
int			my_put_in_list(t_object **list, t_object data);
void			free_my_list(t_object *list);
void			free_spot_list(t_spot *list);

/*
**	expose_gestion.c
*/

int			expose_gestion(t_system *sys);

/*
**	graph_func.c
*/

void			copy_color(unsigned char *src, unsigned char *dest, int bpp);
void			copy_img(t_image src, t_image *dest);
void			get_pix_color(int x, int y, t_image image, unsigned char *color);
void			my_put_pixel_to_img(int x, int y, unsigned char *color,
					    t_image *img);
void			get_color(int color, unsigned char *color_tab,
				  t_scene *scene);

/*
**	error.c
*/

int			my_strerror(char *error);

/*
**	load_image.c
*/

int			load_image(t_scene *scene, t_vector2 pos, t_vector2 dim);

/*
**	event_gestion.c
*/

int			expose_gestion(t_system *sys);
int			key_gestion(int keycode, t_system *sys);

/*
**	lib
*/

int			my_strlen(char *str);
void			my_puterrchar(char c);
void			my_put_error(char *str);

/*
**	multithread_copy.c
*/

int			fill_spot(t_spot *tmp_spot, t_scene *tmp_scene, int i);
int			fill_eye(t_scene *tmp_scene, t_scene *tmp);
int			my_strlen_unsigned(unsigned char *str);

/*
**	fill_new_list.c
*/

t_scene			*init_scene(void);
int			copy_list(t_scene *scene, t_scene *new, t_scene *tmp);

#endif /* !SYS_LIBX_H_ */
