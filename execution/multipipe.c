/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:16:19 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/07 20:00:24 by ynafiss          ###   ########.fr       */
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

char	*get(t_env *env, char *cmd)
{
	int		i;
	char	**path;
	char	*path_f;

	i = 0;
	if (cmd == NULL)
		com_n(cmd);
	while (env && ft_strcmp(env->name, "PATH=") != 0)
		env = env->next;
	i = 0;
	if (ft_strcmp(env->name, "PATH=") != 0)
		com_n(cmd);
	path = ft_split(env->value, ':');
	path_f = pipe_strjoin(path[i++], cmd);
	while (access(path_f, X_OK) != 0 && path[i])
	{
		free(path_f);
		path_f = pipe_strjoin(path[i++], cmd);
	}
	ft_free(path);
	if (access(path_f, X_OK) == 0)
		return (path_f);
	else
		com_n(cmd);
	return (cmd);
}
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

void	ft_else(t_queue *line, char **env, t_env **eenv, t_vars *t)
{
	t_queue_node	*node;
	t_cmd			*cmd;
	int				i;

	i = 0;
	node = line->head;
	cmd = node->ptr;
	while (i < cmd_num(line) - 1)
	{
		pipe(t->pi);
		t->ch[i] = fork();
		mid_cmd(t, cmd, env, t->ch[i], eenv);
		t->fd = t->pi[0];
		cmd = node->ptr;
		node = node->next;
		if (is_here(cmd->files) == 1)
			t->fd_h = t->fd_h->next;
		t->open++;
		i++;
	}
	cmd = node->ptr;
	t->ch[i] = fork();
	if (is_here(cmd->files) == 1)
			t->fd_h = t->fd_h->next;
	last_cmd(t, cmd, env, t->ch[i], eenv);
	wait_child(i, t->ch);
}

void	multipipe(t_queue *line, char **env, t_env **eenv)
{
	int				i;
	t_queue_node	*node;
	t_cmd			*cmd;
	t_vars			t;

	i = 0;
	t.ch = malloc(sizeof(int) * line->len);
	node = line->head;
	t.fd = dup (0);
	t.open = 0;
	if (!node)
		return ;
	here_doc(line, &t);
	if (cmd_num(line) == 1)
	{
		cmd = node->ptr;
		if (is_builtin(cmd->args) == 0)
			t.ch[i] = fork();
		one_cmd(cmd, env, t.ch[i], eenv, &t);
	}
	else if (cmd_num(line) > 1)
		ft_else(line, env, eenv, &t);
	(wait_child(i, t.ch), free(t.ch));
}
