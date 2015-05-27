##
## Makefile for rtv1 makefile in /home/gaspar_q/rendu/Igraph/MUL_2014_rtv1
## 
## Made by quentin gasparotto
## Login   <gaspar_q@epitech.net>
## 
## Started on  Tue Feb  3 16:08:16 2015 quentin gasparotto
## Last update Wed May 27 12:28:56 2015 quentin gasparotto
##

CC=	gcc -g

RM=	rm -f

NAME=	rtracer

SRCS=	./sources/rtv1.c \
	./sources/error.c \
	./sources/graph_func.c \
	./sources/list_fn.c \
	./sources/event_gestion.c \
	./sources/load_image.c \
	./sources/my_puterrchar.c \
	./sources/my_put_error.c \
	./sources/my_strlen.c \
	./sources/init_system.c \
	./sources/objects.c \
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
	./sources/average.c \
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
	./sources/draw_moebius.c \
	./sources/add_moebius.c \
	./sources/get_refracted_ray.c \
	./sources/transparency.c \
	./sources/add_hyperboloid.c \
	./sources/draw_hyperboloid.c \

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
