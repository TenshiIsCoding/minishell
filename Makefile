# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azaher <azaher@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 14:54:07 by azaher            #+#    #+#              #
#    Updated: 2023/03/16 15:33:32 by azaher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = minishell.c \
	   parsing/upgraded_split.c 

NAME = minishell
LIBFT = libft/libft.a
CFLAGS = -Wall -Werror -Wextra
OBJS = ${SRCS:.c=.o}
BOBJS = ${BSRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	cc ${CFLAGS} ${SRCS} -o ${NAME} ${LIBFT} -lreadline

clean :
		rm -f ${OBJS} ${BOBJS}
fclean : clean
		rm -f ${NAME} ${BNAME}

re : fclean all