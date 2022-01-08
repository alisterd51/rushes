# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anclarma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 19:28:48 by anclarma          #+#    #+#              #
#    Updated: 2022/01/08 16:29:41 by anclarma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libunit
LIBFT		= libft/libft.a
FRAMEWORK	= framework/libunit.a
C_DIR		= .
O_DIR		= objs
C_FILES		= tests/main.c					\
			  tests/strlen/00_launcher.c	\
			  tests/strlen/01_basic_test.c	\
			  tests/strlen/02_null_test.c	\
			  tests/strlen/03_bigger_str_test.c
SRCS		= $(patsubst %, $(C_DIR)/%, $(C_FILES))
O_FILES		= $(C_FILES:.c=.o)
OBJS		= $(patsubst %, $(O_DIR)/%, $(O_FILES))
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror		\
			  -MMD -MP
LFLAGS		= -Wall -Wextra -Werror
CINCLUDES	= -Itests/includes			\
			  -Ilibft/includes			\
			  -Iframework/includes
CLIBS		= -Lframework -Llibft -lunit -lft -lrt

all:		$(NAME)

$(O_DIR)/%.o: $(C_DIR)/%.c
			$(CC) $(CFLAGS) $(CINCLUDES) -c $< -o $@

$(O_DIR):
			mkdir $(O_DIR)
			mkdir $(O_DIR)/tests
			mkdir $(O_DIR)/tests/strlen

$(NAME):	$(LIBFT) $(FRAMEWORK) $(O_DIR) $(OBJS)
			$(CC) $(OBJS) $(LFLAGS) $(CLIBS) -o $@

$(LIBFT):
			make -C libft all

$(FRAMEWORK):
			make -C framework all

clean:
			make -C libft fclean
			make -C framework fclean
			rm -rf $(O_DIR)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

-include	$(OBJS:.o=.d)

.PHONY:		all clean fclean re
