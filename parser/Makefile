##
## Makefile for  in /home/veyrie_f/rendu/MUL_2014_rtracer/parser
##
## Made by fernand veyrier
## Login   <veyrie_f@epitech.net>
##
## Started on  Sat May 30 20:49:01 2015 fernand veyrier
## Last update Sat May 30 20:54:39 2015 fernand veyrier
##

CC		= gcc

RM		= rm -f

NAME		= parser

SRCS		= parse_mesh.c 		\
		  parse_coord.c 	\
		  parse_phong.c 	\
		  parse_obj.c 		\
		  parse_limit_scene.c 	\
		  main.c 		\
		  getters.c 		\
		  get_next_line.c 	\
		  parse_eye.c 		\
		  parse_spot.c 		\
		  my_getnbr_base.c 	\
		  char_function.c 	\
		  ../sources/my_strlen.c

OBJS		= $(SRCS:.c=.o)

CFLAGS		= -I./include -I../include -Wall -Wextra -W

$(NAME):	$(OBJS)

		$(CC) -o $(NAME) $(OBJS) $(LIB) 

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
