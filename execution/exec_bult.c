/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 01:03:08 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/17 14:12:10 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*lower_cmd(char *cmd)
{
	char	*res;
	int		i;

	res = malloc(ft_strlen(cmd) + 1);
	i = 0;
	while (cmd[i])
	{
		res[i] = ft_tolower(cmd[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	exec_built(char **cmd, char **env, int ch, t_env **eenv)
{
	char	*lower;

	lower = lower_cmd(cmd[0]);
	if (ft_strcmp(lower, "cd") == 0)
		g_data.g_exit = ft_cd(cmd[1], env, ch);
	if (ft_strcmp(lower, "echo") == 0)
		ft_echo(cmd, ch);
	if (ft_strcmp(lower, "export") == 0)
		g_data.g_exit = export(cmd, eenv);
	if (ft_strcmp(lower, "pwd") == 0)
		ft_pwd(ch);
	if (ft_strcmp(lower, "unset") == 0)
		g_data.g_exit = while_unset(eenv, cmd);
	if (ft_strcmp(lower, "exit") == 0)
		ft_exit(cmd[1]);
	if (ft_strcmp(lower, "env") == 0)
		ft_env((*eenv), ch);
	if (ch == 0)
	{
		free(lower);
		exit (g_data.g_exit);
	}
	free(lower);
}

int	is_builtin(char **cmd)
{
	char	*lower;

	lower = lower_cmd(cmd[0]);
	if (ft_strcmp(lower, "pwd") == 0 || \
	ft_strcmp(lower, "echo") == 0 || \
	ft_strcmp(lower, "cd") == 0 || \
	ft_strcmp(lower, "export") == 0 || \
	ft_strcmp(lower, "unset") == 0 || \
	ft_strcmp(lower, "env") == 0 || \
	ft_strcmp(lower, "exit") == 0)
	{
		free(lower);
		return (1);
	}
	else
	{
		free(lower);
		return (0);
	}
}
