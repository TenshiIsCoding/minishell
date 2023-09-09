/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_multi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:59:57 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/17 16:23:39 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	last_one(t_vars *t, t_cmd *cmd, t_env **env)
{
	t->ch[t->i] = fork();
	last_cmd(t, cmd, t->ch[t->i], env);
	if (t->ch[t->i] == 0)
		exit (0);
	wait_child(t->i, t->ch);
}

void	ft_else(t_queue *line, t_vars *t, t_env **eenv)
{
	t_queue_node	*node;
	t_cmd			*cmd;
	int				j;

	t->i = 0;
	j = 0;
	node = line->head;
	cmd = node->ptr;
	t->here = where_here(cmd, line, node);
	while (t->i < line->len - 1)
	{
		pipes_fork(t, cmd, eenv, t->i);
		node = node->next;
		cmd = node->ptr;
		if (t->here != NULL && t->i == t->here[j])
		{
			t->fd_h = t->fd_h->next;
			j++;
		}
		t->i++;
	}
	cmd = node->ptr;
	(last_one(t, cmd, eenv), free (t->here));
	node = line->head;
}

void	ft_else_if(t_queue *line, t_cmd *cmd, t_env *eenv, t_vars t)
{
	t_list	*tmp;

	tmp = t.fd_h;
	if (line->len > 1)
		ft_else(line, &t, &eenv);
	else if (cmd_num(line) == 0)
	{
		if (open_in_no_cmd(cmd->files, t.fd_h) == 1)
		{
			g_data.g_exit = 1;
			return ;
		}
		open_out_no_cmd(cmd->files);
		return ;
	}
	t.fd_h = tmp;
}

void	multi_norm(t_cmd *cmd, t_vars *t, t_env *env)
{
	if (is_builtin(cmd->args) == 0)
		t->ch[0] = fork();
	else
		t->ch[0] = 1;
	one_cmd(cmd, t->ch[0], t, &env);
	if (t->ch[0] == 1)
		(dup2(t->fd_in, 0), dup2(t->fd_out, 1));
	else if (t->ch[0] == 0)
		exit (127);
}

void	multipipe(t_data *line, char **env, t_env *eenv, t_vars t)
{
	t_queue_node	*node;
	t_cmd			*cmd;

	if (line->commands.head)
	{
		t.ch = malloc(sizeof(int) * line->commands.len);
		node = line->commands.head;
		cmd = node->ptr;
		t.fd_in = dup (0);
		t.fd_out = dup (0);
		t.env = full_vars(env);
		if (!node)
			return ;
		g_data.g_exit = here_doc(&line->commands, &t, eenv, line);
		if (cmd_num(&line->commands) == 1 && \
		line->commands.len == 1 && g_data.g_exit != 44)
			multi_norm(cmd, &t, eenv);
		else if (g_data.g_exit != 44)
			ft_else_if(&line->commands, cmd, eenv, t);
		if (g_data.g_exit == 44)
			g_data.g_exit = 1;
		(free(t.ch), ft_free(t.env), free_list(t.fd_h));
	}
}
