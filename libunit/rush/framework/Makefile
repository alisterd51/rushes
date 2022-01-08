# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 21:02:42 by anclarma          #+#    #+#              #
#    Updated: 2022/01/08 11:25:11 by anclarma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libunit.a
C_DIR		= srcs
O_DIR		= objs
C_FILES		= load_test.c			\
			  launch_tests.c
SRCS		= $(patsubst %, $(C_DIR)/%, $(C_FILES))
O_FILES		= $(C_FILES:.c=.o)
OBJS		= $(patsubst %, $(O_DIR)/%, $(O_FILES))
CC			= cc
RM			= rm -f
MKDIR		= mkdir -p
CFLAGS		= -Wall -Wextra -Werror	\
			  -MMD -MP
LFLAGS		= -Wall -Wextra -Werror
CINCLUDES	= -Iincludes
CLIBS		=

all:		$(NAME)

test:		$(NAME)

$(O_DIR)/%.o: $(C_DIR)/%.c
			$(CC) $(CFLAGS) $(CINCLUDES) -c $< -o $@

$(O_DIR):
			$(MKDIR) $(O_DIR)

$(NAME):	$(LIBFT) $(O_DIR) $(OBJS)
			$(AR) $@ $(OBJS) $(LIBFT)

clean:
			$(RM) -r $(O_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

-include	$(OBJS:.o=.d)

.PHONY:		all clean fclean re
