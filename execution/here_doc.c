/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:31:22 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/16 15:55:41 by ynafiss          ###   ########.fr       */
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

int	here_doc(t_queue *line, t_vars *fd_h, t_env *env, t_data *var)
{
	t_queue_node	*node;
	t_cmd			*cmd;
	t_norm			n;

	node = line->head;
	n.k = 0;
	while (node)
	{
		cmd = node->ptr;
		if (is_here(cmd->files))
		{
			(pipe(n.pi), n.ch = fork());
			if (n.ch == 0)
				norm_here(cmd, n, env, var);
			(close(n.pi[1]), waitpid(n.ch, &n.status, 0));
			if (WEXITSTATUS(n.status) == 44)
				return (44);
			if (n.k++ == 0)
				fd_h->fd_h = ft_lstnew_nor(n.pi[0]);
			else
				ft_lstadd_back_nor(&fd_h->fd_h, ft_lstnew_nor(n.pi[0]));
		}
		node = node->next;
	}
	return (g_data.g_exit);
}
