/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 01:03:08 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/15 16:04:17 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_built(char **cmd, char **env, int ch, t_env **eenv)
{
	if (ft_strcmp(cmd[0], "cd") == 0)
		g_data.g_exit = ft_cd(cmd[1], env, ch);
	if (ft_strcmp(cmd[0], "echo") == 0)
		ft_echo(cmd, ch);
	if (ft_strcmp(cmd[0], "export") == 0)
		g_data.g_exit = export(cmd, eenv);
	if (ft_strcmp(cmd[0], "pwd") == 0)
		ft_pwd(ch);
	if (ft_strcmp(cmd[0], "unset") == 0)
		g_data.g_exit = while_unset(eenv, cmd);
	if (ft_strcmp(cmd[0], "exit") == 0)
		ft_exit(cmd[1]);
	if (ft_strcmp(cmd[0], "env") == 0)
		ft_env((*eenv), ch);
	if (ch == 0)
		exit (g_data.g_exit);
}

int	is_builtin(char **cmd)
{
	if (ft_strcmp(cmd[0], "pwd") == 0 || \
	ft_strcmp(cmd[0], "echo") == 0 || \
	ft_strcmp(cmd[0], "cd") == 0 || \
	ft_strcmp(cmd[0], "export") == 0 || \
	ft_strcmp(cmd[0], "unset") == 0 || \
	ft_strcmp(cmd[0], "env") == 0 || \
	ft_strcmp(cmd[0], "exit") == 0)
		return (1);
	else
		return (0);
}
