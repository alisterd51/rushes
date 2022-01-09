# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anclarma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 19:28:48 by anclarma          #+#    #+#              #
#    Updated: 2022/01/09 11:45:04 by anclarma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1		= libunit_tests
NAME2		= libunit_real-tests
LIBFT		= libft/libft.a
FRAMEWORK	= framework/libunit.a
C_DIR		= .
O_DIR1		= objs_tests
C_FILES1	= tests/main.c								\
			  tests/strlen/00_launcher.c				\
			  tests/strlen/01_basic_test.c				\
			  tests/strlen/02_null_test.c				\
			  tests/strlen/03_bigger_str_test.c			\
			  tests/all_return/00_all_return_launcher.c	\
			  tests/all_return/01_all_return_ok.c		\
			  tests/all_return/02_all_return_ko.c		\
			  tests/all_return/03_all_return_segv.c		\
			  tests/all_return/04_all_return_bus.c
SRCS1		= $(patsubst %, $(C_DIR)/%, $(C_FILES1))
O_FILES1	= $(C_FILES1:.c=.o)
OBJS1		= $(patsubst %, $(O_DIR1)/%, $(O_FILES1))
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror		\
			  -MMD -MP
LFLAGS		= -Wall -Wextra -Werror
CINCLUDES	= -Itests/includes			\
			  -Ilibft/includes			\
			  -Iframework/includes
CLIBS		= -Lframework -Llibft -lunit -lft -lrt

all:		test

test:		$(NAME1) $(NAME2)
			./$(NAME1)
			./$(NAME2)

$(O_DIR1)/%.o: $(C_DIR)/%.c
			$(CC) $(CFLAGS) $(CINCLUDES) -c $< -o $@

$(O_DIR1):
			mkdir $(O_DIR1)
			mkdir $(O_DIR1)/tests
			mkdir $(O_DIR1)/tests/strlen
			mkdir $(O_DIR1)/tests/all_return

$(NAME1):	$(LIBFT) $(FRAMEWORK) $(O_DIR1) $(OBJS1)
			$(CC) $(OBJS1) $(LFLAGS) $(CLIBS) -o $@

$(LIBFT):
			make -C libft all

$(FRAMEWORK):
			make -C framework all

clean:
			make -C libft fclean
			make -C framework fclean
			rm -rf $(O_DIR1)

fclean:		clean
			rm -f $(NAME1)
			rm -f $(NAME2)

re:			fclean all

-include	$(OBJS:.o=.d)

.PHONY:		all clean fclean re
