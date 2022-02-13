# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 10:04:58 by anclarma          #+#    #+#              #
#    Updated: 2022/02/13 11:32:57 by anclarma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= alum1
C_DIR		= srcs
O_DIR		= objs
C_FILES		= main.c					\
			  ft_lstadd_back.c			\
			  ft_lstnew.c				\
			  ft_lstclear.c				\
			  ft_lstdelone.c			\
			  ft_lstsize.c				\
			  ft_strlen.c				\
			  get_next_line.c			\
			  ft_strdup.c				\
			  ft_strjoin.c				\
			  ft_strisdigit.c			\
			  ft_putendl_fd.c			\
			  ft_putstr_fd.c			\
			  ft_putnbr_fd.c			\
			  ft_putchar_fd.c			\
			  ft_secure_atoi.c			\
			  ft_isspace.c				\
			  ft_isdigit.c				\
			  ft_atoi.c					\
			  ft_itoa.c					\
			  ft_lstlast.c				\
			  ft_bzero.c				\
			  game.c					\
			  ai_turn.c					\
			  human_turn.c				\
			  apply_move.c				\
			  alcu_utils.c
SRCS		= $(patsubst %, $(C_DIR)/%, $(C_FILES))
O_FILES		= $(C_FILES:.c=.o)
OBJS		= $(patsubst %, $(O_DIR)/%, $(O_FILES))
CC			= cc
MAKE		= make
RM			= rm -f
MKDIR		= mkdir -p
FSANITIZE	= -fsanitize=address -fsanitize=leak -fsanitize=undefined -g3
CFLAGS		= -Wall -Wextra -Werror		\
			  -MMD -MP #$(FSANITIZE)
LFLAGS		= -Wall -Wextra -Werror #$(FSANITIZE)
CINCLUDES	= -I ./includes
CLIBS		=

all:		$(NAME)

$(O_DIR)/%.o: $(C_DIR)/%.c
			$(CC) $(CFLAGS) $(CINCLUDES) -c $< -o $@

$(O_DIR):
			$(MKDIR) $(O_DIR)

$(NAME):	$(O_DIR) $(OBJS)
			$(CC) $(OBJS) $(LFLAGS) $(CLIBS) -o $@

clean:
			$(RM) -r $(O_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

-include	$(OBJS:.o=.d)

.PHONY:		all clean fclean re
