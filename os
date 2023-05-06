# **************************************************************************** #$
#                                                                              #$
#                                                         :::      ::::::::    #$
#    Makefile                                           :+:      :+:    :+:    #$
#                                                     +:+ +:+         +:+      #$
#    By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+         #$
#                                                 +#+#+#+#+#+   +#+            #$
#    Created: 2023/03/13 14:54:07 by azaher            #+#    #+#              #$
#    Updated: 2023/05/03 17:00:16 by ynafiss          ###   ########.fr        #$
#                                                                              #$
# **************************************************************************** #$
$
NAME = minishell$
LIBFT = libft/libft.a$
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g$
AF= minishell.c \$
ynafiss/builtins.c	\$
ynafiss/ft_list.c	\$
ynafiss/ft_strcmp.c	\$
ynafiss/echo_cd.c	\$
ynafiss/env_pwd.c	\$
ynafiss/unset.c	\$
ynafiss/multipipe.c	\$
ynafiss/exec_cmds.c	\$
ynafiss/wait_ch.c	\$
ynafiss/exec_bult.c	\$
ynafiss/export.c	\$
ynafiss/here_doc.c	\$
ynafiss/export_utils.c	\$
parsing/upgraded_split_tools.c \$
parsing/upgraded_split.c \$
parsing/syntax_tools.c \$
parsing/syntax_tools2.c \$
parsing/syntax.c \$
parsing/expanding.c \$
parsing/expanding_tools.c \$
parsing/parse_start.c \$
parsing/parse_tools.c \$
parsing/parse_tools_2.c \$
parsing/parse_tools_3.c \$
parsing/parse_tools_4.c \$
queue/queue.c$
$
OBJS = ${AF:.c=.o}$
$
all : ${NAME}$
$
${NAME} : ${OBJS}$
	make -C libft$
	cc ${CFLAGS} ${AF} -o ${NAME} ${LIBFT} -lreadline$
$
clean :$
		rm -f ${OBJS} ${BOBJS} libft/*.o$
fclean : clean$
		rm -f ${NAME} ${BNAME} ${LIBFT}$
$
re : fclean all