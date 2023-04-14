/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 04:45:34 by ynafiss           #+#    #+#             */
/*   Updated: 2023/04/14 10:04:21 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	num_file(t_file **file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	return (i);
}

int	open_in_out(t_file **file)
{
	static int	i;
	int			j;
	int			fd_in;
	int			fd_out;
	// int			here_doc;

	i = 0;
	j = 0;
	fd_in = -1;
	fd_out = -1;
	if (file[i++]->filename && file[i]->type == IN)
		fd_in = open(file[i]->filename, O_RDONLY);
	if (file[i]->filename && file[i]->type == OUT && fd_in != -1)
		fd_out = open (file[i]->filename, O_CREAT | O_RDWR);
	if (file[i]->filename && file[i]->type == APND && fd_in != -1)
		fd_out = open (file[i]->filename, O_CREAT | O_RDWR | O_APPEND);
	if (fd_in != -1)
	{
		dup2(fd_in, 0);
		j++;
	}
	if (fd_out != -1)
	{
		dup2(fd_out, 1);
		j++;
	}
	i++;
	return (j);
}

void	mid_cmd(t_vars *t, t_cmd *cmd, char **env, int ch, t_env *eenv)
{
	char		*path;

	if (ch == 0)
	{
		if (cmd->args[0][0] == '/' && access(cmd->args[0], X_OK) == 0)
			path = cmd->args[0];
		else
			path = get(env, cmd->args[0]);
		close(t->pi[0]);
		dup2(t->pi[1], 1);
		close (t->pi[1]);
		dup2(t->fd, 0);
		close(t->fd);
		if (is_builtin(cmd->args) == 0)
			execve(path, cmd->args, env);
		else
			exec_built(cmd->args, env, ch, eenv);
	}
	else
	{
		close(t->pi[1]);
		close(t->fd);
		t->fd = t->pi[0];
	}
}

void	last_cmd(int fd, t_cmd *cmd, char **env, int ch)
{
	char		*path;

	if (ch == 0)
	{
		if (cmd->args[0][0] == '/' && access(cmd->args[0], X_OK) == 0)
			path = cmd->args[0];
		else
			path = get(env, cmd->args[0]);
		dup2(fd, 0);
		close (fd);
		execve(path, cmd->args, env);
	}
	else
	{	
		close (fd);
	}
}

void	one_cmd(char **cmd, char **env, int ch, t_env *eenv)
{
	char		*path;

	if (ch == 0 || is_builtin(cmd) != 0)
	{
		if (cmd[0][0] == '/' && access(cmd[0], X_OK) == 0)
			path = cmd[0];
		if (is_builtin(cmd) == 0)
		{			
			path = get(env, cmd[0]);
			execve(path, cmd, env);
		}
		else
			exec_built(cmd, env, ch, eenv);
	}
}
