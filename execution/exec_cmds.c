/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 04:45:34 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/08 14:03:22 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void	first_cmd(t_cmd *cmd, int ch, t_env **eenv, char **env, t_vars *t)
// {
// 	char		*path;

// 	if (ch == 0)
// 	{
// 		if (cmd->args[0][0] == '/' && access(cmd->args[0], X_OK) == 0)
// 			path = cmd->args[0];
// 		else
// 			path = get((*eenv), cmd->args[0]);
// 		dup2(t->pi[1], 1);
// 		close (t->pi[1]);
// 		if (is_builtin(cmd->args) == 0)
// 			execve(path, cmd->args, env);
// 		else
// 			exec_built(cmd->args, env, ch, eenv);
// 	}
// 	else
// 	{
// 		close(t->pi[1]);
// 		close(t->fd);
// 		t->fd = t->pi[0];
// 	}
// }

void	mid_cmd(t_vars *t, t_cmd *cmd, char **env, int ch, t_env **eenv)
{
	char		*path;

	if (ch == 0)
	{
		if (cmd->args[0][0] == '/' && access(cmd->args[0], X_OK) == 0)
			path = cmd->args[0];
		else
			path = get((*eenv), cmd->args[0]);
		(close(t->pi[0]), dup2(t->fd, 0));
		(close(t->fd), dup2(t->pi[1], 1));
		close (t->pi[1]);
		if (open_in(cmd->files, t->fd_h) == 1)
			return ;
		if (is_builtin(cmd->args) == 0)
			execve(path, cmd->args, env);
		else
			exec_built(cmd->args, env, ch, eenv);
	}
	else
	{
		(close(t->pi[1]), close(t->fd));
		t->fd = t->pi[0];
	}
}

void	last_cmd(t_vars *t, t_cmd *cmd, char **env, int ch, t_env **eenv)
{
	char		*path;

	if (ch == 0)
	{
		dup2(t->fd, 0);
		close(t->fd);
		open_out(cmd->files);
		if (open_in(cmd->files, t->fd_h) == 1)
			return ;
		if (is_builtin(cmd->args) == 0)
		{
			if (cmd->args[0][0] == '/' || access(cmd->args[0], X_OK) == 0)
				path = cmd->args[0];
			else
				path = get((*eenv), cmd->args[0]);
			execve(path, cmd->args, env);
		}
		else
			exec_built(cmd->args, env, ch, eenv);
	}
	else
		close (t->fd);
}

void	one_cmd(t_cmd *cmd, char **env, int ch, t_vars *t, t_env **eenv)
{
	char		*path;

	if (ch == 0 || is_builtin(cmd->args) != 0)
	{
		if (open_in(cmd->files, t->fd_h) == 1)
			return ;
		open_out(cmd->files);
		if (is_builtin(cmd->args) == 0)
		{			
			if (cmd->args[0][0] == '/' && access(cmd->args[0], X_OK) == 0)
				path = cmd->args[0];
			else
				path = get((*eenv), cmd->args[0]);
			execve(path, cmd->args, env);
		}
		else
			exec_built(cmd->args, env, ch, eenv);
	}
}
