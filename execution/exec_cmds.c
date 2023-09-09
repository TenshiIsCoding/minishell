/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 04:45:34 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/17 14:44:35 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	norm_cmd(t_cmd *cmd, t_vars *t, t_env **eenv)
{
	char	*path;

	if (cmd->args[0][0] == '/' || access(cmd->args[0], X_OK) == 0)
		path = cmd->args[0];
	else
		path = get((*eenv), cmd->args[0]);
	execve(path, cmd->args, t->env);
}

void	mid_cmd(t_vars *t, t_cmd *cmd, int ch, t_env **eenv)
{
	if (ch == 0)
	{
		if (ch == 0)
			handle_signals(1);
		dup_in(t);
		if (open_in(cmd->files, t->fd_h) == 1)
			exit(1);
		open_out(cmd->files);
		if (is_cmd(cmd) == 1)
		{
			if (is_builtin(cmd->args) == 0)
				norm_l_m_cmd(cmd, t, eenv);
			else
				exec_built(cmd->args, t->env, ch, eenv);
		}
		else
		{
			if (open_in_no_cmd(cmd->files, t->fd_h) == 1)
				exit (1);
			open_out_no_cmd(cmd->files);
			exit(0);
		}
	}
	else
		(close(t->pi[1]), close(t->fd_in), t->fd_in = t->pi[0]);
}

void	last_cmd(t_vars *t, t_cmd *cmd, int ch, t_env **eenv)
{
	if (ch == 0)
	{
		if (ch == 0)
			handle_signals(1);
		dup2(t->fd_in, 0);
		close(t->fd_in);
		if (open_in(cmd->files, t->fd_h) == 1)
			exit(1);
		open_out(cmd->files);
		if (is_cmd(cmd) == 1)
		{
			if (is_builtin(cmd->args) == 0)
				norm_l_m_cmd(cmd, t, eenv);
			else
				exec_built(cmd->args, t->env, ch, eenv);
		}
		else
		{
			if (open_in_no_cmd(cmd->files, t->fd_h) == 1)
				exit (1);
			(open_out_no_cmd(cmd->files), exit(0));
		}
	}
	else
		close (t->fd_in);
}

void	norm_one(t_cmd *cmd, t_env **eenv, t_vars *t)
{
	char	*path;

	if (cmd->args[0][0] == '/' || \
	(cmd->args[0][0] == '.' && access(cmd->args[0], F_OK) == 0))
		path = cmd->args[0];
	else
		path = get((*eenv), cmd->args[0]);
	if (execve(path, cmd->args, t->env) == -1)
	{
		write(2, "command not found : ", 20);
		ft_putstr_fd(cmd->args[0], 2);
		write(2, "\n", 1);
		exit (127);
	}
}

void	one_cmd(t_cmd *cmd, int ch, t_vars *t, t_env **eenv)
{
	if (ch == 0 || is_builtin(cmd->args) != 0)
	{
		if (ch == 0)
			handle_signals(1);
		if (open_in(cmd->files, t->fd_h) == 1)
			return ;
		open_out(cmd->files);
		if (is_builtin(cmd->args) == 0)
			norm_one(cmd, eenv, t);
		else
			exec_built(cmd->args, t->env, ch, eenv);
	}
	if (is_builtin(cmd->args) == 0)
		wait_child(0, t->ch);
}
