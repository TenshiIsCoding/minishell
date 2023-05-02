/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 04:45:34 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/01 18:56:26 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	open_in(t_file **file, t_list *here)
{
	int	fd_in;
	int	i;

	fd_in = -1;
	i = 0;
	if (!file[i])
		return ;
	while (file[i])
	{
		if (file[i]->filename && file[i]->type == IN)
		{
			fd_in = open(file[i]->filename, O_RDONLY);
			if (fd_in == -1)
			{
				write(2, "no such file or directory: ", 27);
				ft_putstr_fd(file[i]->filename, 2);
				(write(2, "\n", 1), exit (127));
			}
			if (file[i + 1] && file[i + 1]->type == IN)
				close (fd_in);
		}
		if (file[i]->type == HERE)
			fd_in = here->content;
		i++;
	}
	(fd_in != -1) && dup2(fd_in, 0);
	(fd_in != -1) && close (fd_in);
}

int	open_out(t_file **file)
{
	int	i;
	int	ret;
	int	fd_out;

	if (file[0] == NULL)
		return (0);
	i = 0;
	ret = 0;
	fd_out = -1;
	while (file[i])
	{
		if (file[i]->type == OUT || file[i]->type == APND)
		{
			if (file[i]->type == OUT)
				fd_out = open (file[i]->filename, O_CREAT | O_TRUNC | \
			O_WRONLY | O_RDONLY, 0777);
			if (file[i]->type == APND)
				fd_out = open (file[i]->filename, O_CREAT | O_APPEND | \
			O_WRONLY | O_RDONLY, 0777);
			if (fd_out == -1)
			{
				write(2, "open filed: ", 12);
				(ft_putstr_fd(file[i]->filename, 2), exit (127));
			}
			if (file[i + 1] && file[i + 1]->type == OUT)
				close (fd_out);
			ret = 1;
		}
		i++;
	}
	if (fd_out != -1)
		dup2(fd_out, 1);
	return (ret);
}

void	first_cmd(t_cmd *cmd, int ch, t_env **eenv, char **env, t_vars *t)
{
	char		*path;

	if (ch == 0)
	{
		if (cmd->args[0][0] == '/' && access(cmd->args[0], X_OK) == 0)
			path = cmd->args[0];
		else
			path = get((*eenv), cmd->args[0]);
		dup2(t->pi[1], 1);
		close (t->pi[1]);
		close (t->pi[0]);
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

void	mid_cmd(t_vars *t, t_cmd *cmd, char **env, int ch, t_env **eenv)
{
	char		*path;

	if (ch == 0)
	{
		if (cmd->args[0][0] == '/' && access(cmd->args[0], X_OK) == 0)
			path = cmd->args[0];
		else
			path = get((*eenv), cmd->args[0]);
		close(t->pi[0]);
		dup2(t->fd, 0);
		close(t->fd);
		// open_in(cmd->files);
		dup2(t->pi[1], 1);
		close (t->pi[1]);
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

void	last_cmd(int fd, t_cmd *cmd, char **env, int ch, t_env **eenv)
{
	char		*path;

	if (ch == 0)
	{
		if (is_builtin(cmd->args) == 0)
		{
			if (cmd->args[0][0] == '/' && access(cmd->args[0], X_OK) == 0)
				path = cmd->args[0];
			else
				path = get((*eenv), cmd->args[0]);
			open_out(cmd->files);
			dup2(fd, 0);
			close(fd);
			// open_in(cmd->files);
			execve(path, cmd->args, env);
		}
		else
			exec_built(cmd->args, env, ch, eenv);
	}
	else
		close (fd);
}

void	one_cmd(t_cmd *cmd, char **env, int ch, t_env **eenv, t_list *here)
{
	char		*path;

	if (ch == 0 || is_builtin(cmd->args) != 0)
	{
		open_in(cmd->files, here);
		open_out(cmd->files);
		// close (here->content); 
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
	else
		close (here->content);
}
