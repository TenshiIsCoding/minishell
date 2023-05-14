/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 04:45:34 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/14 17:31:23 by azaher           ###   ########.fr       */
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
void	cmd_handel(int sig)
{
	(void)sig;
	exit (130);
}

void	cmd_signal(struct termios term)
{
	term.c_cc[VQUIT] = _POSIX_VDISABLE;
	term.c_lflag &= ~ECHOCTL;
	(tcsetattr(0, TCSANOW, &term), signal(SIGINT, SIG_DFL));
}

void	mid_cmd(t_vars *t, t_cmd *cmd, int ch, t_env **eenv)
{
	char			*path;
	struct termios	term;

	if (ch == 0)
	{
		tcgetattr(STDIN_FILENO, &term);
		cmd_signal(term);
		if ((cmd->args[0][0] == '/' || cmd->args[0][0] == '.' ))
			path = ft_strdup(cmd->args[0]);
		else
			path = get((*eenv), cmd->args[0]);
		(close(t->pi[0]), dup2(t->fd, 0));
		(close(t->fd), dup2(t->pi[1], 1));
		close (t->pi[1]);
		open_out(cmd->files);
		if (open_in(cmd->files, t->fd_h) == 1)
			exit(1);
		if (cmd->args)
		{
			if (is_builtin(cmd->args) == 0)
				execve(path, cmd->args, t->env);
			else
				exec_built(cmd->args, t->env, ch, eenv);
		}
	}
	else
	{
		(close(t->pi[1]), close(t->fd));
		t->fd = t->pi[0];
	}
}


void	last_cmd(t_vars *t, t_cmd *cmd, int ch, t_env **eenv)
{
	char			*path;
	struct termios	term;

	if (ch == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		tcgetattr(STDIN_FILENO, &term);
		cmd_signal(term);
		dup2(t->fd, 0);
		close(t->fd);
		open_out(cmd->files);
		if (open_in(cmd->files, t->fd_h) == 1)
			exit(1);
		if (is_cmd(cmd) == 1)
		{
			if (is_builtin(cmd->args) == 0)
			{
				if (cmd->args[0][0] == '/' || access(cmd->args[0], X_OK) == 0)
					path = cmd->args[0];
				else
					path = get((*eenv), cmd->args[0]);
				execve(path, cmd->args, t->env);
			}
			else
				exec_built(cmd->args, t->env, ch, eenv);
		}
		else
			(open_out_no_cmd(cmd->files), open_in_no_cmd(cmd->files, t->fd_h), exit(0));
	}
	else
		close (t->fd);
}

void	one_cmd(t_cmd *cmd, int ch, t_vars *t, t_env **eenv)
{
	char			*path;
	struct termios	term;

	if (ch == 0 || is_builtin(cmd->args) != 0)
	{
		tcgetattr(STDIN_FILENO, &term);
		cmd_signal(term);
		if (open_in(cmd->files, t->fd_h) == 1)
			return ;
		open_out(cmd->files);
		if (is_builtin(cmd->args) == 0)
		{			
			if (cmd->args[0][0] == '/' || \
			(cmd->args[0][0] == '.' && access(cmd->args[0], F_OK) == 0))
				path = cmd->args[0];
			else
				path = get((*eenv), cmd->args[0]);
			if (execve(path, cmd->args, t->env) == -1)
			{
				ft_putstr_fd(path, 2);
				write(2, ": No such file or directory\n", 28);
			}
		}
		else
			exec_built(cmd->args, t->env, ch, eenv);
	}
	if (is_builtin(cmd->args) == 0)
		wait_child(0, t->ch);
}
