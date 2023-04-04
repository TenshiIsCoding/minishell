# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azaher <azaher@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 14:54:07 by azaher            #+#    #+#              #
#    Updated: 2023/04/04 23:55:07 by azaher           ###   ########.fr        #
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
ynafiss/export.c	\
ynafiss/unset.c	\
ynafiss/multipipe.c	\
parsing/upgraded_split_tools.c \
parsing/upgraded_split.c \
parsing/syntax_tools.c \
parsing/syntax_tools2.c \
parsing/syntax.c \
parsing/expanding.c \
parsing/expanding_tools.c \
parsing/parse_start.c \
parsing/parse_tools.c

OBJS = ${AF:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	make -C libft
	cc ${CFLAGS} ${AF} -o ${NAME} ${LIBFT} -lreadline

clean :
		rm -f ${OBJS} ${BOBJS}
fclean : clean
		rm -f ${NAME} ${BNAME}

re : fclean all