NAME = minishell

SRCS = executor.c executor2.c \
		executor_fork.c executor_fork2.c executor_fork3.c\
		executor_builtins.c executor_builtins2.c executor_builtins3.c executor_builtins4.c executor_builtins5.c \
		utils.c utils2.c utils3.c utils4.c free.c \
		../g_n_l/g_n_l.c \
		../g_n_l/g_n_l_utils.c \
		../libft/ft_atoi.c ../libft/ft_isdigit.c

CFLAGS = -Wall -Wextra -Werror

CC = gcc

OBJ = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) main.c  $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all