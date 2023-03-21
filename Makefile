# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azaher <azaher@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 14:54:07 by azaher            #+#    #+#              #
#    Updated: 2023/03/17 13:27:25 by azaher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFT = libft/libft.a
CFLAGS = -Wall -Werror -Wextra
AF= minishell.c \
ynafiss/builtins.c	\
ynafiss/ft_list.c	\
ynafiss/ft_strcmp.c	\
parsing/upgraded_split_tools.c

OBJS = ${AF:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	cc ${CFLAGS} ${AF} -o ${NAME} ${LIBFT} -lreadline

clean :
		rm -f ${OBJS} ${BOBJS}
fclean : clean
		rm -f ${NAME} ${BNAME}

re : fclean all