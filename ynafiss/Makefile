# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 14:54:07 by azaher            #+#    #+#              #
<<<<<<< HEAD:ynafiss/Makefile
#    Updated: 2023/03/16 11:38:35 by ynafiss          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


=======
#    Updated: 2023/03/16 15:33:32 by azaher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = minishell.c \
	   parsing/upgraded_split.c 
>>>>>>> 6ad028c0b9eee8393e817425a5800db444d9f7e4:Makefile

NAME = minishell
LIBFT = libft/libft.a
#CFLAGS = -Wall -Werror -Wextra
AF= builtins.c	\
ft_list.c	\
ft_strcmp.c	\

OBJS = ${AF:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	cc ${CFLAGS} ${AF} -o ${NAME} ${LIBFT} -lreadline

clean :
		rm -f ${OBJS} ${BOBJS}
fclean : clean
		rm -f ${NAME} ${BNAME}

re : fclean all