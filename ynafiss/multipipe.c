/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:16:19 by ynafiss           #+#    #+#             */
/*   Updated: 2023/04/07 01:06:23 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

char	*pipe_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*b;

	i = 0;
	j = 0;
	if (!s2 || !s1)
		return (NULL);
	b = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!b)
		return (NULL);
	while (s1[i] != '\0')
	{
		b[i] = s1[i];
		i++;
	}
	b[i++] = '/';
	while (s2[j] != '\0')
		b[i++] = s2[j++];
	b[i] = '\0';
	return (b);
}

void	com_n(char *cmd)
{
	write(2, "command not found: ", 20);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);

	exit(127);
}

char	*get(char **env, char *cmd)
{
	int		i;
	char	**path;
	char	*path_f;
	char	*envv;

	i = 0;
	if (cmd == NULL)
		com_n(cmd);
	while (ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	envv = env[i] + 5;
	i = 0;
	path = ft_split(envv, ':');
	path_f = pipe_strjoin(path[i++], cmd);
	while (access(path_f, X_OK) != 0 && path[i])
	{
		free(path_f);
		path_f = pipe_strjoin(path[i++], cmd);
	}
	free(path);
	if (access(path_f, X_OK) == 0)
		return (path_f);
	else
		com_n(cmd);
	return (cmd);
}

void	exec_built(char **cmd, char **env)
{
	if (strcmp(cmd[0], "cd"))
		ft_cd(cmd[1], env);
	// if (strcmp(cmd[0], "echo"))
	// 	ft_echo(cmd, cmd[1]);
	// if (strcmp(cmd[0], "env"))
	// 	ft_env(env);
	if (strcmp(cmd[0], "pwd"))
		ft_pwd();
	// if (strcmp(cmd[0], "unset"))
	// 	ft_unset(env, cmd, cmd[1]);
}
int	is_builtin(char **cmd)
{
	if (strcmp(cmd[0], "cd") || strcmp(cmd[0], "echo") || strcmp(cmd[0], "export") || strcmp(cmd[0], "env") || strcmp(cmd[0], "unset") ||  strcmp(cmd[0], "pwd"))
		return (1);
	else
		return (0);
}
void	mid_cmd(int *fd, char **cmd, char **env, int ch, int *pi)
{
	char		*path;
	if (ch == 0)
	{
		if (cmd[0][0] == '/' && access(cmd[0], X_OK) == 0)
			path = cmd[0];	
		else
			path = get(env, cmd[0]);

			close (pi[0]);
			dup2(pi[1], 1);
			close (pi[1]);
			dup2(*fd, 0);
			close(*fd);
		if (is_builtin(cmd) == 0)
			execve(path, cmd, env);
		else
			exec_built(cmd, env);
	}
	else
	{
		close(pi[1]);
		close(*fd);
		*fd = pi[0];
	}
	
}



void	last_cmd(int fd, char **cmd, char **env, int ch)
{
	char		*path;

	if (ch == 0)
	{
		if (cmd[0][0] == '/' && access(cmd[0], X_OK) == 0)
			path = cmd[0];	
		else
			path = get(env, cmd[0]);
		printf("%s", path);
		dup2(fd, 0);
		close (fd);
		execve(path, cmd, env);
	}
	else
		close (fd);
}

void one_cmd(char **cmd, char **env, int ch)
{
	char		*path;

	if (ch == 0)
	{
		if (cmd[0][0] == '/' && access(cmd[0], X_OK) == 0)
			path = cmd[0];	
		else
			path = get(env, cmd[0]);
		execve(path, cmd, env);
	}
	
}

void    multipipe(t_node  *line, int cmd_num, char **env)
{
    int	i;
	int	j;
	int	fd;
	int ch[cmd_num];
	int			pi[2];

	i = 0;
	j = 0;
	fd = dup (0);
	if (cmd_num == 1)
	{
		ch[i] = fork();
		one_cmd(line->content->args, env, ch[i]);
	}
	else
	{
		pipe(pi);
		while (i < cmd_num && line->next)
		{
			ch[i] = fork();
			mid_cmd(&fd, line->content->args, env, ch[i], pi);
			line = line->next;
			i++;
		}
		ch[i] = fork();
		last_cmd(fd, line->content->args, env, ch[i]);
	}
	waitpid(ch[i], NULL, 0);
	while (j < i)
	{
		waitpid(ch[j], NULL, 0);
		j++;
	}
	
}