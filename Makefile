# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 14:54:07 by azaher            #+#    #+#              #
#    Updated: 2023/03/22 18:16:42 by ynafiss          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFT = libft/libft.a
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
AF= minishell.c \
ynafiss/builtins.c	\
ynafiss/ft_list.c	\
ynafiss/ft_strcmp.c	\
ynafiss/echo_cd.c	\
ynafiss/env_pwd.c	\
ynafiss/export.c	\
ynafiss/unset.c	\
parsing/upgraded_split_tools.c \
parsing/upgraded_split.c

OBJS = ${AF:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	cc ${CFLAGS} ${AF} -o ${NAME} ${LIBFT} -lreadline

clean :
		rm -f ${OBJS} ${BOBJS}
fclean : clean
		rm -f ${NAME} ${BNAME}

re : fclean all