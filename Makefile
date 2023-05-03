# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azaher <azaher@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 14:54:07 by azaher            #+#    #+#              #
#    Updated: 2023/05/03 17:49:51 by azaher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFT = libft/libft.a
CFLAGS = -Wall -Werror -Wextra
AF= minishell.c \
ynafiss/builtins.c	\
ynafiss/ft_list.c	\
ynafiss/ft_strcmp.c	\
ynafiss/echo_cd.c	\
ynafiss/env_pwd.c	\
ynafiss/unset.c	\
ynafiss/multipipe.c	\
ynafiss/exec_cmds.c	\
ynafiss/wait_ch.c	\
ynafiss/exec_bult.c	\
ynafiss/export.c	\
ynafiss/here_doc.c	\
ynafiss/export_utils.c	\
parsing/ft_itoa.c \
parsing/upgraded_split_tools.c \
parsing/upgraded_split.c \
parsing/syntax_tools.c \
parsing/syntax_tools2.c \
parsing/syntax.c \
parsing/expanding_tools.c \
parsing/parse_start.c \
parsing/parse_tools.c \
parsing/parse_tools_2.c \
parsing/parse_tools_3.c \
parsing/parse_tools_4.c \
parsing/parse_tools_5.c \
parsing/parse_tools_6.c \
queue/queue.c \
signal_handler.c

OBJS = ${AF:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	make -C libft
	cc ${CFLAGS} ${AF} -o ${NAME} ${LIBFT} -I /goinfre/azaher/homebrew/opt/readline/include -lreadline -L /goinfre/azaher/homebrew/opt/readline/lib

clean :
		make clean -C libft
		rm -f ${OBJS} ${BOBJS}
fclean : clean
		make fclean -C libft
		rm -f ${NAME} ${BNAME}

re : fclean all