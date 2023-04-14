/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:16:19 by ynafiss           #+#    #+#             */
/*   Updated: 2023/04/14 01:03:31 by ynafiss          ###   ########.fr       */
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

void	multipipe(t_queue *line, char **env)
{
	int				i;
	t_queue_node	*node;
	t_cmd			*cmd;
	t_vars			t;
	int				ch[line->len];

	i = 0;
	node = line->head;
	t.fd = dup (0);
	if (line->len == 1)
	{
		cmd = node->ptr;
		if (is_builtin(cmd->args) == 0)
			ch[i] = fork();
		one_cmd(cmd->args, env, ch[i]);
	}
	else
	{
		while (i < line->len - 1)
		{
			pipe(t.pi);
			cmd = node->ptr;
			ch[i] = fork();
			mid_cmd(&t, cmd, env, ch[i]);
			node = node->next;
			i++;
		}
		cmd = node->ptr;
		ch[i] = fork();
		last_cmd(t.fd, cmd, env, ch[i]);
	}
	wait_child(i, ch);
}
