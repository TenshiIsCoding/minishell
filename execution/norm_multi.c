/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_multi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:13:10 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/17 14:43:46 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cmd_num(t_queue *line)
{
	int				i;
	int				j;
	t_queue_node	*node;
	t_cmd			*cmd;

	i = 0;
	j = 0;
	node = line->head;
	while (node)
	{
		cmd = node->ptr;
		if (cmd->args[j] != NULL)
			i++;
		node = node->next;
		j++;
	}
	return (i);
}

int	is_cmd(t_cmd *cmd)
{
	if (cmd->args[0][0] != '\0')
		return (1);
	return (0);
}

void	free_list(t_list *head)
{
	t_list	*next;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

void	pipes_fork(t_vars *t, t_cmd *cmd, t_env **env, int i)
{
	pipe(t->pi);
	t->ch[i] = fork();
	mid_cmd(t, cmd, t->ch[i], env);
	t->fd_in = t->pi[0];
}
