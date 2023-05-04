/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:31:22 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/03 16:12:42 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

int	count_here(t_file **file)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file[i])
	{
		if (file[i]->type == HERE)
			j++;
		i++;
	}
	return (j);
}

void	here_doc(t_queue *line, t_vars *fd_h)
{
	int				i;
	int				j;
	int				k;
	t_list			*here;
	t_queue_node	*node;
	t_cmd			*cmd;
	char			*line_r = NULL;
	int				pi[2];

	i = 0;
	j = 0;
	k = 0;
	node = line->head;
	while (node)
	{
		cmd = node->ptr;
		i = 0;
		while (cmd->files[i])
		{
			if (cmd->files[i]->type == HERE)
			{
				pipe(pi);
				while (ft_strcmp(cmd->files[i]->filename, \
				line_r) != 0)
				{
					line_r = readline("> ");
					if (ft_strcmp(cmd->files[i]->filename, line_r) == 0 \
					|| line_r == NULL)
					{
						free (line_r);
						break ;
					}
					ft_putstr_fd(line_r, pi[1]);
					(write(pi[1], "\n", 1), free (line_r));
				}
				k++;
			}
			i++;
		}
		if (j == 0)
		{
			close(pi[1]);
			here = ft_lstnew_nor(pi[0]);
			j++;
		}
		node = node->next;
		if (j > 1 && k != 0)
		{
			close(pi[1]);
			ft_lstadd_back_nor(&here, ft_lstnew_nor(pi[0]));
		}
		k = 0;
	}
	fd_h->fd_h = here;
}
