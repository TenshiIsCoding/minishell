/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_multi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:59:57 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/15 11:57:26 by ynafiss          ###   ########.fr       */
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

int	is_cmd(t_cmd *cmd)
{
	if (cmd->args[0][0] != '\0')
		return (1);
	return (0);
}


void	ft_else(t_queue *line, t_vars *t, t_env **eenv)
{
	t_queue_node	*node;
	t_cmd			*cmd;
	int				i;
	int				j;
	int				*here;

	i = 0;
	j = 0;
	node = line->head;
	cmd = node->ptr;
	t->open = 0;
	here = where_here(cmd, line, node);
	printf("%d\n", line->len);
	while (i < line->len - 1)
	{
		pipe(t->pi);
		ft_putstr_fd("ww\n", 2);
		t->ch[i] = fork();
		mid_cmd(t, cmd, t->ch[i], eenv);
		t->fd = t->pi[0];
		node = node->next;
		cmd = node->ptr;
		if (here != NULL && i == here[j])
		{
			t->fd_h = t->fd_h->next;
			j++;
		}
		t->open++;
		i++;
	}
	cmd = node->ptr;
	t->ch[i] = fork();
	last_cmd(t, cmd, t->ch[i], eenv);
	wait_child(i, t->ch);
	(free (here));
}

void	ft_else_if(t_queue *line, t_cmd *cmd, t_env *eenv, t_vars t)
{
	if (line->len > 1)
		ft_else(line, &t, &eenv);
	else if (cmd_num(line) == 0)
		(open_out_no_cmd(cmd->files), open_in_no_cmd(cmd->files, t.fd_h));
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
		t.fd = dup (0);
		t.env = full_vars(env);
		if (!node)
			return ;
		g_exit = here_doc(&line->commands, &t, eenv, line);
		if (cmd_num(&line->commands) == 1 && \
		line->commands.len == 1 && g_exit != 44)
		{
			if (is_builtin(cmd->args) == 0)
				t.ch[0] = fork();
			else
				t.ch[0] = 1;
			one_cmd(cmd, t.ch[0], &t, &eenv);
		}
		else if (g_exit != 44)
			ft_else_if(&line->commands, cmd, eenv, t);
		if (g_exit == 44)
			g_exit = 1;
		(free(t.ch), ft_free(t.env));
	}
}
