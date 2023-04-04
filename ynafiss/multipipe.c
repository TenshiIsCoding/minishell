/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:16:19 by ynafiss           #+#    #+#             */
/*   Updated: 2023/04/04 02:37:58 by ynafiss          ###   ########.fr       */
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

int	ft_len(char	**cmd, int j)
{
	int	i;

	i = j;
	while (cmd[i] && strcmp(cmd[i], "|") != 0)
		i++;
	return (i);
}

void	mid_cmd(int *fd, char **cmd, char **env)
{
	static int	c;
	char		*path;
	int			ch;
	int			pi[2];

	pipe(pi);
	ch = fork();
	if (ch == 0)
	{
		if (cmd[0][0] == '/' && access(cmd[0], X_OK) == 0)
			path = cmd[0];	
		else
			path = get(env, cmd[0]);

		if (c == 0)
		{
			dup2(pi[1], 1);
			close(pi[0]);
			close (pi[1]);
			c++;
		}
		else
		{
			close (pi[0]);
			dup2(*fd, 0);
			dup2(pi[1], 1);
			close(*fd);
			close (pi[1]);
		}
		execve(path, cmd, env);
	}
	else
	{
		close(pi[1]);
		close(*fd);
		*fd = pi[0];
	}
	
}

void	last_cmd(int *fd, char **cmd, char **env)
{
	char		*path;
	int			ch;
	int			pi[2];

	pipe(pi);
	ch = fork();
	if (ch == 0)
	{
		if (cmd[0][0] == '/' && access(cmd[0], X_OK) == 0)
			path = cmd[0];	
		else
			path = get(env, cmd[0]);
		dup2(*fd, 0);
		close(pi[0]);
		close (pi[1]);
		waitpid(ch, NULL, 0);
		execve(path, cmd, env);
	}
	
}

void    multipipe(t_node  *line, int pipe_num, char **env)
{
    int	i;
	int	j;
	int	fd;

	i = 0;
	j = 0;
	fd = dup (0);
	// // printf("%s", line->content->args[0]);
	// printf("%d", pipe_num);
	// // printf("%s", line->next->content->args[0]);
	// exit (0);
	while (i < pipe_num)
	{
		mid_cmd(&fd, line->content->args, env);
		i++;
	}
	line = line->next;
	last_cmd(&fd, line->content->args, env);
}
