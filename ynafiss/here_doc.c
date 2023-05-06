/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:31:22 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/06 13:23:32 by ynafiss          ###   ########.fr       */
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

void here_doc(t_queue *line, t_vars *fd_h)
{
	t_list *here = NULL;
	t_queue_node *node;
	char *line_r = NULL;
	t_cmd *cmd;
	int pi[2];
	int i;
	int k;

	node = line->head;
	if (!node)
		return ;
	while (node)
	{
		cmd = node->ptr;
		i = 0;
		if (is_here(cmd->files))
		{
			pipe(pi);
			while (cmd->files[i])
			{
				if (cmd->files[i]->type == HERE)
				{
					k = 0;
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
						{
							ft_putstr_fd(line_r, pi[1]);
							write(pi[1], "\n", 1);
						}
						free(line_r);
						k++;
					}
					if (k > 0)
					{
						close(pi[1]);
						here = ft_lstnew_nor(pi[0]);
					}
				}
				i++;
			}
		}
		node = node->next;
	}
	fd_h->fd_h = here;
}
