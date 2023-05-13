/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:00:32 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/11 17:22:23 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	*where_here(t_cmd *cmd, t_queue *line, t_queue_node *node)
{
	int	i;
	int	j;
	int	c;
	int	*here;

	j = 0;
	c = 0;
	here = calloc(line->len, 4);
	while (cmd && node)
	{
		i = 0;
		cmd = node->ptr;
		if (cmd)
		{
			while (cmd->files[i])
			{
				if (cmd->files[i]->type == HERE)
				{
					here[j] = c;
					j++;
					break ;
				}
				i++;
			}
		}
		c++;
		node = node->next;
	}
	if (j == 0)
		return (NULL);
	return (here);
}

void	here_handel(int sig)
{
	(void)sig;
	g_exit = 444;
}

void	here_signal(void)
{
	signal(SIGINT, here_handel);
	signal(SIGQUIT, SIG_IGN);
}
