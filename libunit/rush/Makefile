# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anclarma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 19:28:48 by anclarma          #+#    #+#              #
#    Updated: 2022/01/09 18:40:45 by anclarma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1		= libunit_tests
NAME2		= libunit_real-tests
LIBFT		= libft/libft.a
LIBFTF		= fake_libft/libftfake.a
FRAMEWORK	= framework/libunit.a

C_DIR1		= real-tests
C_FILES1	= main.c							\
			  strlen/00_launcher.c				\
			  strlen/01_basic_test.c			\
			  strlen/02_null_test.c				\
			  strlen/03_bigger_str_test.c		\
			  strlen/04_basic_test2.c			\
			  strlen/05_null_test2.c			\
			  strcmp/00_launcher.c				\
			  strcmp/01_basic_equal_test.c		\
			  strcmp/02_basic_non_equal_test.c	\
			  strcmp/03_null_test.c				\
			  strcmp/04_null_2_test.c			\
			  strcmp/05_null_3_test.c			\
			  strcmp/06_null_4_test.c			\
			  strjoin/00_launcher.c				\
			  strjoin/01_basic_test.c			\
			  strjoin/02_null_test_1.c			\
			  strjoin/03_null_test_2.c			\
			  strjoin/04_empty_str_test_1.c		\
			  strjoin/05_empty_str_test_2.c		\
			  strjoin/06_empty_str_test_3.c		\
			  isspace/00_launcher.c				\
			  isspace/01_basic_test_1.c			\
			  isspace/02_basic_test_2.c			\
			  isspace/03_basic_test_3.c			\
			  isspace/04_basic_test_4.c			\
			  isspace/05_basic_test_5.c			\
			  isspace/06_basic_test_6.c			\
			  isdigit/00_launcher.c				\
			  isdigit/01_basic_test_1.c			\
			  isdigit/02_basic_test_2.c			\
			  isdigit/03_basic_test_3.c			\
			  
SRCS1		= $(addprefix $(C_DIR1)/, $(C_FILES1))
OBJS1		= $(SRCS1:.c=.o)
DEPS1		= $(SRCS1:.c=.d)

C_DIR2		= tests
C_FILES2	= main.c							\
			  strlen/00_launcher.c				\
			  strlen/01_basic_test.c			\
			  strlen/02_null_test.c				\
			  strlen/03_bigger_str_test.c		\
			  all_return/00_launcher.c			\
			  all_return/01_ok.c				\
			  all_return/02_ko.c				\
			  all_return/03_segv.c				\
			  all_return/04_bus.c				\
			  all_return/05_abort.c				\
			  all_return/06_fpe.c				\
			  all_return/07_pipe.c				\
			  all_return/08_ill.c
SRCS2		= $(addprefix $(C_DIR2)/, $(C_FILES2))
OBJS2		= $(SRCS2:.c=.o)
DEPS2		= $(SRCS2:.c=.d)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror				\
			  -MMD -MP
LFLAGS		= -Wall -Wextra -Werror
CINCLUDES	= -I$(C_DIR1)/includes				\
			  -I$(C_DIR2)/includes				\
			  -Ilibft/includes					\
			  -Iframework/includes				\
			  -Ifake_libft/includes
CLIBS		= -Lframework -Llibft -Lfake_libft -lunit -lft -lftfake

all:		test real-test

bonus:		framework_bonus test real-test

test:		$(NAME2)
			./$(NAME2) ; true

real-test:	$(NAME1)
			./$(NAME1) ; true

%.o: %.c
			$(CC) $(CFLAGS) $(CINCLUDES) -c $< -o $@

$(NAME1):	$(LIBFT) $(LIBFTF) $(FRAMEWORK) $(OBJS1)
			$(CC) $(OBJS1) $(LFLAGS) $(CLIBS) -o $@

$(NAME2):	$(LIBFT) $(LIBFTF) $(FRAMEWORK) $(OBJS2)
			$(CC) $(OBJS2) $(LFLAGS) $(CLIBS) -o $@

$(LIBFT):
			make -C libft all

$(LIBFTF):
			make -C fake_libft all

$(FRAMEWORK):
			make -C framework all

framework_bonus:
			make -C framework bonus

clean:
			make -C libft fclean
			make -C fake_libft fclean
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
