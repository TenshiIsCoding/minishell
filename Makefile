# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 14:54:07 by azaher            #+#    #+#              #
#    Updated: 2023/05/06 14:17:40 by ynafiss          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFT = libft/libft.a
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
AF= minishell.c \
execution/builtins.c	\
execution/ft_list.c	\
execution/ft_strcmp.c	\
execution/echo_cd.c	\
execution/env_pwd.c	\
execution/unset.c	\
execution/multipipe.c	\
execution/exec_cmds.c	\
execution/wait_ch.c	\
execution/exec_bult.c	\
execution/export.c	\
execution/here_doc.c	\
execution/export_utils.c	\
parsing/upgraded_split_tools.c \
parsing/upgraded_split.c \
parsing/syntax_tools.c \
parsing/syntax_tools2.c \
parsing/syntax.c \
parsing/expanding.c \
parsing/expanding_tools.c \
parsing/parse_start.c \
parsing/parse_tools.c \
parsing/parse_tools_2.c \
parsing/parse_tools_3.c \
parsing/parse_tools_4.c \
queue/queue.c

OBJS = ${AF:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	make -C libft
	cc ${CFLAGS} ${AF} -o ${NAME} ${LIBFT} -lreadline

clean :
		rm -f ${OBJS} ${BOBJS} libft/*.o
fclean : clean
		rm -f ${NAME} ${BNAME} ${LIBFT}

re : fclean all