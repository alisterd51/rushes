NAME		= libftfake.a
C_DIR		= srcs
O_DIR		= objs
C_FILES		= fake_strcmp.c				\
			  fake_strlen.c				\
			  fake_strjoin.c			\
			  fake_isspace.c			\
			  fake_isdigit.c			\
			  
SRCS		= $(patsubst %, $(C_DIR)/%, $(C_FILES))
O_FILES		= $(C_FILES:.c=.o)
OBJS		= $(patsubst %, $(O_DIR)/%, $(O_FILES))
CC			= gcc
AR			= ar rc
CFLAGS		= -Wall -Wextra -Werror		\
			  -MMD -MP
LFLAGS		= -Wall -Wextra -Werror
CINCLUDES	= -I ./includes
CLIBS		=

all:		$(NAME)

check:		all

$(O_DIR)/%.o: $(C_DIR)/%.c
			$(CC) $(CFLAGS) $(CINCLUDES) -c $< -o $@

$(O_DIR):
			mkdir $(O_DIR)

$(NAME):	$(O_DIR) $(OBJS)
			$(AR) $@ $(OBJS)

clean:
			rm -rf $(O_DIR)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

-include	$(OBJS:.o=.d)

.PHONY:		all clean fclean re
