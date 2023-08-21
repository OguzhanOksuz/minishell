NAME	=	minishell

CC		=	gcc
CFLAGS	=	-I $(H_DIR) -Wall -Wextra -Werror

AFLAGS	=	-I $(H_DIR) -Wall -Wextra -Werror -fsanitize=address
DFLAGS	=	-I $(H_DIR) -Wall -Wextra -Werror -fsanitize=thread

#----------------------------------

C_DIR	=	srcs
H_DIR	=	inc
O_DIR	=	obj

TOK_DIR	=	tokenizer
UTI_DIR	=	utils
BUI_DIR	=	builtin

#----------------------------------

MAIN	=	main.c			\
			ft_free.c

TOKEN	=	tokenizer.c

UTILS	=	arr_add_back.c	\
			ft_dupstr.c		\
			ft_substr.c		\
			ft_strlen.c		\
			ft_strncmp.c	\
			get_env_val.c

BUILTIN	=

SRCS	=	$(addprefix $(C_DIR)/$(UTI_DIR)/, $(UTILS))		\
			$(addprefix $(C_DIR)/$(BUI_DIR)/, $(BUILTIN))	\
			$(addprefix $(C_DIR)/$(TOK_DIR)/, $(TOKEN))		\
			$(addprefix $(C_DIR)/, $(MAIN))

OBJS	=	$(SRCS:.c=.o)

#----------------------------------

all			:	$(NAME)

$(NAME)		:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lreadline -o $(NAME)

data		:	$(OBJS)
	$(CC) $(DFLAGS) $(OBJS) -lreadline -o $(NAME)

adres		:	$(OBJS)
	$(CC) $(AFLAGS) $(OBJS) -lreadline -o $(NAME)

clean		:
	rm -rf $(OBJS)

fclean		:	clean
	rm -rf $(NAME)

re			:	fclean all

.PHONY: all clean fclean re
