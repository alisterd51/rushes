# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 21:02:42 by anclarma          #+#    #+#              #
#    Updated: 2022/01/09 14:39:23 by anclarma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libunit.a
NAME_B		= libunit_bonus.a
C_DIR		= srcs
O_DIR		= objs
C_FILES		= load_test.c			\
			  launch_tests.c		\
			  clean_tests.c			\
			  count_test.c
SRCS		= $(patsubst %, $(C_DIR)/%, $(C_FILES))
O_FILES		= $(C_FILES:.c=.o)
OBJS		= $(patsubst %, $(O_DIR)/%, $(O_FILES))
C_FILES_B	= load_test.c			\
			  launch_tests_bonus.c	\
			  clean_tests.c			\
			  count_test.c
SRCS_B		= $(patsubst %, $(C_DIR)/%, $(C_FILES_B))
O_FILES_B	= $(C_FILES_B:.c=.o)
OBJS_B		= $(patsubst %, $(O_DIR)/%, $(O_FILES_B))
CC			= cc
AR			= ar rc
RM			= rm -f
MKDIR		= mkdir -p
CFLAGS		= -Wall -Wextra -Werror	\
			  -MMD -MP -fPIE
LFLAGS		= -Wall -Wextra -Werror
CINCLUDES	= -Iincludes			\
			  -I../libft/includes
CLIBS		=

all:		$(NAME)

bonus:		$(NAME_B)
			cp $(NAME_B) $(NAME)

$(O_DIR)/%.o: $(C_DIR)/%.c
			$(CC) $(CFLAGS) $(CINCLUDES) -c $< -o $@

$(O_DIR):
			$(MKDIR) $(O_DIR)

$(NAME):	$(O_DIR) $(OBJS)
			$(AR) $@ $(OBJS)

$(NAME_B):	$(O_DIR) $(OBJS_B)
			$(AR) $@ $(OBJS_B)

clean:
			$(RM) -r $(O_DIR)
			$(RM) -r $(O_DIR_B)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(NAME_B)

re:			fclean all

-include	$(OBJS:.o=.d)
-include	$(OBJS_B:.o=.d)

.PHONY:		all bonus clean fclean re
