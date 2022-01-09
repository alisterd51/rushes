# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anclarma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 19:28:48 by anclarma          #+#    #+#              #
#    Updated: 2022/01/09 16:31:39 by anclarma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1		= libunit_tests
NAME2		= libunit_real-tests
LIBFT		= libft/libft.a
FRAMEWORK	= framework/libunit.a
C_DIR1		= tests
C_FILES1	= main.c						\
			  strlen/00_launcher.c			\
			  strlen/01_basic_test.c		\
			  strlen/02_null_test.c			\
			  strlen/03_bigger_str_test.c	\
			  all_return/00_launcher.c		\
			  all_return/01_ok.c			\
			  all_return/02_ko.c			\
			  all_return/03_segv.c			\
			  all_return/04_bus.c			\
			  all_return/05_abort.c			\
			  all_return/06_fpe.c
SRCS1		= $(addprefix $(C_DIR1)/, $(C_FILES1))
OBJS1		= $(SRCS1:.c=.o)
DEPS1		= $(SRCS1:.c=.d)
C_DIR2		= real-tests
C_FILES2	= main.c
SRCS2		= $(addprefix $(C_DIR2)/, $(C_FILES2))
OBJS2		= $(SRCS2:.c=.o)
DEPS2		= $(SRCS2:.c=.d)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror		\
			  -MMD -MP
LFLAGS		= -Wall -Wextra -Werror
CINCLUDES	= -I$(C_DIR1)/includes	\
			  -I$(C_DIR2)/includes	\
			  -Ilibft/includes			\
			  -Iframework/includes
CLIBS		= -Lframework -Llibft -lunit -lft

all:		test

bonus:		framework_bonus test

test:		$(NAME1)
			./$(NAME1) ; true

%.o: %.c
			$(CC) $(CFLAGS) $(CINCLUDES) -c $< -o $@

$(NAME1):	$(LIBFT) $(FRAMEWORK) $(OBJS1)
			$(CC) $(OBJS1) $(LFLAGS) $(CLIBS) -o $@

$(NAME2):	$(LIBFT) $(FRAMEWORK) $(OBJS2)
			$(CC) $(OBJS2) $(LFLAGS) $(CLIBS) -o $@

$(LIBFT):
			make -C libft all

$(FRAMEWORK):
			make -C framework all

framework_bonus:
			make -C framework bonus

clean:
			make -C libft fclean
			make -C framework fclean
			rm -rf $(OBJS1) $(DEPS1)
			rm -rf $(OBJS2) $(DEPS2)

fclean:		clean
			rm -f $(NAME1)
			rm -f $(NAME2)

re:			fclean all

-include	$(DEPS1)
-include	$(DEPS2)

.PHONY:		all clean fclean re
.SILENT:
