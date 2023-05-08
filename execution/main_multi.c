/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_multi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:59:57 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/08 13:52:09 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cmd_num(t_queue *line)
{
	int				i;
	t_queue_node	*node;
	t_cmd			*cmd;

	i = 0;
	node = line->head;
	while (node)
	{
		cmd = node->ptr;
		if (cmd->args[0])
			i++;
		node = node->next;
	}
	return (i);
}

void	ft_else(t_queue *line, char **env, t_vars *t, t_env **eenv)
{
	t_queue_node	*node;
	t_cmd			*cmd;
	int				i;

	i = 0;
	node = line->head;
	cmd = node->ptr;
	while (i < cmd_num(line) - 1)
	{
		pipe(t->pi);
		t->ch[i] = fork();
		mid_cmd(t, cmd, env, t->ch[i], eenv);
		t->fd = t->pi[0];
		cmd = node->ptr;
		node = node->next;
		if (is_here(cmd->files) == 1)
			t->fd_h = t->fd_h->next;
		t->open++;
		i++;
	}
	cmd = node->ptr;
	t->ch[i] = fork();
	if (is_here(cmd->files) == 1)
			t->fd_h = t->fd_h->next;
	last_cmd(t, cmd, env, t->ch[i], eenv);
	wait_child(i, t->ch);
}

void	multipipe(t_queue *line, char **env, t_env *eenv)
{
	int				i;
	t_queue_node	*node;
	t_cmd			*cmd;
	t_vars			t;

	i = 0;
	t.ch = malloc(sizeof(int) * line->len);
	node = line->head;
	t.fd = dup (0);
	t.open = 0;
	if (!node)
		return ;
	here_doc(line, &t);
	if (cmd_num(line) == 1)
	{
		cmd = node->ptr;
		if (is_builtin(cmd->args) == 0)
			t.ch[i] = fork();
		one_cmd(cmd, env, t.ch[i], &t, &eenv);
	}
	else if (cmd_num(line) > 1)
		ft_else(line, env, &t, &eenv);
	(wait_child(i, t.ch), free(t.ch));
}