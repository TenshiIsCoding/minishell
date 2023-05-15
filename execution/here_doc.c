/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:31:22 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/14 19:02:01 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

int	last_here(t_file **file)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file[i])
	{
		if (file[i]->type == HERE)
			j = i;
		i++;
	}
	return (j);
}

int	is_here(t_file **file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (file[i]->type == HERE)
			return (1);
		i++;
	}
	return (0);
}

void	norm_here(t_cmd *cmd, int pi[2], int ch, t_env *env, t_data *var)
{
	int				i;
	char			*line_r;
	struct termios	term;

	i = 0;
	line_r = NULL;
	if (ch == 0)
	{
		tcgetattr(STDIN_FILENO, &term);
		here_signal(term);
		while (cmd->files[i])
		{
			if (cmd->files[i]->type == HERE)
			{
				while (1)
				{
					line_r = readline("> ");
					if (!line_r || \
					!ft_strcmp(cmd->files[i]->filename, line_r))
					{
						free(line_r);
						break ;
					}
					if (i == last_here(cmd->files) && cmd->files[i]->inqt == 0)
						(ft_putstr_fd(expand_argument(line_r, var, env), \
						pi[1]), write(pi[1], "\n", 1));
					if (i == last_here(cmd->files) && cmd->files[i]->inqt == 1)
						(ft_putstr_fd(line_r, pi[1]), write(pi[1], "\n", 1));
					// free(line_r);
				}
			}
			i++;
		}
		exit(0);
	}
}

// void    ft_here(struct termios a2, char **env, char *lim, int fdp)
// {
//     a2.c_cc[VQUIT] = _POSIX_VDISABLE;
//     a2.c_lflag &= ~ECHOCTL;
//     (tcsetattr(0, TCSANOW, &a2), signal(SIGINT, doc));
//     (here_doc1(env, lim, fdp), exit(0));
// }

int	here_doc(t_queue *line, t_vars *fd_h, t_env *env, t_data *var)
{
	t_list			*here;
	t_queue_node	*node;
	t_cmd			*cmd;
	t_norm			n;

	here = NULL;
	node = line->head;
	n.k = 0;
	if (!node)
		return (g_exit);
	while (node)
	{
		cmd = node->ptr;
		if (is_here(cmd->files))
		{
			(pipe(n.pi), n.ch = fork());
			if (n.ch == 0)
				norm_here(cmd, n.pi, n.ch, env, var);
			(close(n.pi[1]), waitpid(n.ch, &n.status, 0));
			if (WEXITSTATUS(n.status) == 44)
				return (44);
			if (n.k++ == 0)
				here = ft_lstnew_nor(n.pi[0]);
			else
				ft_lstadd_back_nor(&here, ft_lstnew_nor(n.pi[0]));
		}
		node = node->next;
	}
	fd_h->fd_h = here;
	// free(here);
	return (g_exit);
}
