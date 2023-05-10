/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:31:22 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/09 12:34:14 by ynafiss          ###   ########.fr       */
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

void	norm_here(t_cmd *cmd, int pi[2])
{
	int		i;
	char	*line_r;

	i = 0;
	line_r = NULL;
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
				if (i == last_here(cmd->files))
					(ft_putstr_fd(line_r, pi[1]), write(pi[1], "\n", 1));
				free(line_r);
			}
		}
		i++;
	}
}

void	here_doc(t_queue *line, t_vars *fd_h)
{
	t_list			*here;
	t_queue_node	*node;
	t_cmd			*cmd;
	int				pi[2];
	int				k;

	here = NULL;
	node = line->head;
	k = 0;
	if (!node)
		return ;
	while (node)
	{
		cmd = node->ptr;
		if (is_here(cmd->files))
		{
			(pipe(pi), norm_here(cmd, pi), close(pi[1]));
			if (k++ == 0)
				here = ft_lstnew_nor(pi[0]);
			else
				ft_lstadd_back_nor(&here, ft_lstnew_nor(pi[0]));
		}
		node = node->next;
	}
	fd_h->fd_h = here;
}
