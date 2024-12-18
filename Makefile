# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 14:54:07 by azaher            #+#    #+#              #
#    Updated: 2023/05/17 16:26:52 by ynafiss          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFT = libft/libft.a
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g
AF= minishell.c \
execution/builtins.c	\
execution/ft_list.c	\
execution/ft_list2.c	\
execution/ft_strcmp.c	\
execution/echo_cd.c	\
execution/env_pwd.c	\
execution/here_doc_utils.c	\
execution/unset.c	\
execution/signal_exec.c	\
execution/norm_multi.c	\
execution/multipipe.c	\
execution/exec_cmds.c	\
execution/exec_cmd_2.c	\
execution/check_norm.c	\
execution/wait_ch.c	\
execution/exec_bult.c	\
execution/export.c	\
execution/export_norm.c	\
execution/here_doc.c	\
execution/here_doc_norm.c	\
execution/export_utils.c	\
execution/open_files.c	\
execution/cd.c	\
execution/export_utils2.c	\
execution/open_files_no_cmd.c	\
execution/main_multi.c	\
parsing/ft_itoa.c \
parsing/upgraded_split_tools.c \
parsing/upgraded_split.c \
parsing/syntax_tools.c \
parsing/syntax_tools2.c \
parsing/syntax.c \
parsing/expanding_tools.c \
parsing/basic_expand.c \
parsing/parse_start.c \
parsing/parse_tools.c \
parsing/parse_tools_2.c \
parsing/parse_tools_3.c \
parsing/parse_tools_4.c \
parsing/parse_tools_5.c \
parsing/parse_tools_6.c \
queue/queue.c \
signal_handler.c


${USER} = $USER
OBJS = ${AF:.c=.o}
.SILENT:
all : ${NAME}
${NAME} : ${OBJS}
	stty -ctlecho
	echo "\033[0;33m"LIBFT is compiling...
	make -C libft
	echo  "\033[0;33m"${NAME} is compiling...
	cc ${CFLAGS} ${OBJS} -o ${NAME} ${LIBFT} -I /goinfre/${USER}/homebrew/opt/readline/include -lreadline -L /goinfre/${USER}/homebrew/opt/readline/lib
	# cc ${CFLAGS} ${OBJS} -o ${NAME} ${LIBFT} -lreadline
	echo "\033[0;32m"${NAME} is compiled!
clean :
		rm -f ${OBJS} ${BOBJS}
fclean : clean
		make fclean -C libft
		rm -f ${NAME} ${BNAME}

re : fclean all