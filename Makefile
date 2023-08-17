NAME	=	minishell

CC	=	gcc
CFLAGS	=	-I $(H_DIR) -Wall -Wextra -Werror

AFLAGS	=	-Wall -Wextra -Werror fsanitize=address
DFLAGS	=	-Wall -Wextra -Werror fsanitize=thread

#----------------------------------

C_DIR	=	./srcs
H_DIR	=	./inc
O_DIR	=	./objs

UTI_DIR	=	utils
BUI_DIR	=	builtin

#----------------------------------

UTILS	=	ft_strlen.c \
		ft_strncmp.c \
		get_env_val.c

BUILTIN	=

SRCS	=	$(addprefix $(C_DIR)/$(UTI_DIR)/, $(UTILS))	\
		$(addprefix $(C_DIR)/$(BUI_DIR)/, $(BUILTIN))

OBJS	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(INC) -o $(NAME)

clean	:
	rm -rf $(OBJS)

fclean	:	clean
	rm -rf $(NAME)

re	:	fclean all
