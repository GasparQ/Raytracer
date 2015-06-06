
CC=	gcc -g -fopenmp

RM=	rm -f

NAME=	rt

SRCS=	./sources/rtracer.c \
	./sources/error.c \
	./sources/graph_func.c \
	./sources/list_fn.c \
	./sources/event_gestion.c \
	./sources/load_image.c \
	./sources/my_puterrchar.c \
	./sources/my_put_error.c \
	./sources/fill_new_list.c \
	./sources/my_strlen.c \
	./sources/init_system.c \
	./sources/objects.c \
	./sources/multithread_copy.c \
	./sources/add_sphere.c \
	./sources/add_plan.c \
	./sources/add_spot.c \
	./sources/bomb_ray.c \
	./sources/translate.c \
	./sources/rotate_coord.c \
	./sources/resolve_light.c \
	./sources/scalaire.c \
	./sources/get_streight.c \
	./sources/add_obj.c \
	./sources/get_vectors.c \
	./sources/add_cylinder.c \
	./sources/add_cone.c \
	./sources/free_mesh.c \
	./sources/cmp_limit.c \
	./sources/loading_screen.c \
	./sources/obj_norms.c \
	./sources/get_isec_point.c \
	./sources/add_paraboloid.c \
	./sources/resolve_polynoms.c \
	./sources/disp_color.c \
	./sources/get_spot_nb.c \
	./sources/get_limit.c \
	./sources/get_properties.c \
	./sources/get_reflected_ray.c \
	./sources/get_vec_cos.c \
	./sources/extract_point.c \
	./sources/unit_vec.c \
	./sources/add_holed_cube.c \
	./sources/holed_cube.c \
	./sources/free_mesh_next.c \
	./sources/obj_norms_next.c \
	./sources/quadratic_solver.c \
	./sources/sort_n_check.c \
	./sources/cubic_solver.c \
	./sources/get_min_root.c \
	./sources/tab_cpy.c \
	./sources/add_tore.c \
	./sources/tore.c \
	./sources/get_refracted_ray.c \
	./sources/transparency.c \
	./sources/add_hyperboloid.c \
	./sources/draw_hyperboloid.c \
	./sources/scene_gestion.c \
	./sources/intensity_gestion.c \
	./sources/alb_load_time.c \
	./sources/antialiasing.c \
	./sources/get_object.c \
	./sources/effects.c \
	./sources/duplicate_objects.c \
	./sources/make_action.c \
	./sources/make_action_next.c \
	./sources/strgt_inc.c \
	./sources/export_bmp.c \
	./sources/load_texture.c \
	./sources/add_texture.c \
	./sources/obj_texture.c \
	./sources/obj_texture_next.c \
	./sources/sphere_texture.c \
	./sources/perlin.c \
	./sources/plan_texture.c \
	./sources/bumpping.c \
	./sources/limit_detection.c \
	./parser/parse_mesh.c 		\
	./parser/parse_mesh_next.c	\
	./parser/parse_coord.c 		\
	./parser/parse_phong.c 		\
	./parser/parse_obj.c 		\
	./parser/parse_limit_scene.c 	\
	./parser/main.c 		\
	./parser/getters.c 		\
	./parser/get_next_line.c 	\
	./parser/parse_eye.c 		\
	./parser/parse_spot.c 		\
	./parser/my_getnbr_base.c 	\
	./parser/char_function.c 	\
	./parser/parse_texture.c	\
	./parser/parse_texture_next.c	\
	./parser/init.c			\
	./online/file.c			\

OBJS=	$(SRCS:.c=.o)

CFLAGS=	-Wall -Wextra -I ./include

RT_FLAGS= -L/usr/lib64/ -lmlx -L/usr/lib64/X11 -lXext -lX11 -lm

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(RT_FLAGS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
