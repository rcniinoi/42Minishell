# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 10:14:28 by pmikada           #+#    #+#              #
#    Updated: 2023/03/03 22:59:07 by rchiewli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
CFLAGS	= -Wall -Wextra -Werror
READLINE =-L/usr/local/opt/readline/lib -I/usr/local/opt/readline/include -lreadline
#READLINE = -I/usr/local/opt/readline/include -lreadline -L/usr/local/opt/readline
CC		= gcc -g
MAIN	= main.c
SRCS	= newnewsh/shdec.c \
			newnewsh/sub_main.c \
			newnewsh/lexor.c \
			newnewsh/lexor_utils.c \
			newnewsh/lex_errorchker.c \
			newnewsh/parser.c \
			newnewsh/parser_utils.c \
			newnewsh/parser_utils2.c \
			newnewsh/expander.c \
			newnewsh/expander_utils.c \
			newnewsh/expander_utils2.c \
			newnewsh/expander_util3.c \
			newnewsh/expanderutil.c \
			newnewsh/free.c \
			sigasig/sighand.c \
			executor2/executor.c executor2/executor2.c \
			executor2/executor_fork.c executor2/executor_fork2.c executor2/executor_fork3.c\
			executor2/executor_builtins.c executor2/executor_builtins2.c executor2/executor_builtins3.c executor2/executor_builtins4.c executor2/executor_builtins5.c \
			executor2/utils.c executor2/utils2.c executor2/utils3.c executor2/utils4.c executor2/free.c \
			g_n_l/g_n_l.c \
			g_n_l/g_n_l_utils.c

# MFILES	=./main/main4test.c

LIBFT= libft/libft.a

OBJ	= $(SRCS:%.c=%.o)

%.o :%.c
	$(CC) $(CFLAGS)  -I/usr/local/opt/readline/include -c -o $@ $<

all: $(NAME)
# all: $(NAME)

# ft_pf:
# 	@make -C ft_pf/
# libft:
# 	make -C /libft

$(NAME): $(OBJ)
	@make -C libft/
	$(CC)  $(CFLAGS)   $(READLINE) $(LIBFT) -o $(NAME) $(MAIN)  $(OBJ)
# $(NAME): $(OBJ) libft
# 	# @say -v kyoko こんにちは マクドナルド ミルク バス ビール スターバックス
# 	$(CC)  $(CFLAGS) $(OBJ) $(READLINE) $(LIBFT) $(MAIN) -o $(NAME)

# $(BNAME): $(BOBJ)
# 	# @say -v kyoko こんにちは マクドナルド ミルク バス ビール スターバックス
# 	@make -C dt_dpf/
# 	@make -C libftfinal/
# 	$(CC) $(CFLAGS) $(BOBJ) dt_dpf/libftprintf.a libftfinal/libft.a -o $(BNAME)

# debug:
# 	@make -C dt_dpf/
# 	@make -C libftfinal/
# 	$(CC) -g $(CFLAGS) $(FILES) dt_dpf/libftprintf.a libftfinal/libft.a -o debug


love:
	@printf "No one to \e[1;31m make love \e[0m with you."

cheer:
	@say -v kanya หนึ่ง สอง /
	@say -v kanya หนึ่งสองสาม /
	@say -v kanya หนึ่งสอง /
	@say -v kanya หนึ่งสอง /
	@say -v kanya หนึ่ง /

badvoice:
	@say -v kanya ยายมอยเลี้ยงหมี และยายมีเลี้ยงหอย/
	@say -v kanya ส่วนนางลีขายหอย และนางมอยขายหมี/
	@say -v kanya ยานัตถุ์ของหมอมีแก้ฝีแก้หิด แต่การแพทย์ของหมอชิดแก้หิดแก้ฝี/
	@say -v kanya เอาหูหมีมาใส่ในหูหมู หนูเอาหูหมูมาใส่หูหมี หูหมู หูหนี เอาหูหมีมาใส่หูหมู/
	@say -v kanya แต่ถ้าเธอเอาไปผัดเห็ดมันจะเป็นเห็ดหูหนู/

norm:
	@say -v kanya เช็คนอม หน่อยนะค่ะ /
	norminette -R checkforbiddensourceheader $(FILES)
	norminette -R checkdefine minishell.h struct.h

clean:
	@make clean -C libft/
	@rm -f $(OBJ)
	@rm -rf debug

fclean: clean
	@make fclean -C libft/
	@rm -f  $(NAME)

re: fclean all

re2: clean debug

.PHONY: clean fclean all re norm love cheer badvoice chkr
