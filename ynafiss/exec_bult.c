/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 01:03:08 by ynafiss           #+#    #+#             */
/*   Updated: 2023/04/14 01:05:43 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_built(char **cmd, char **env, int ch)
{
	(void)env;
	// ft_putstr_fd(cmd[0], 2);
	if (strcmp(cmd[0], "cd") == 0)
		ft_cd(cmd[1], env);
	if (strcmp(cmd[0], "echo") == 0)
		ft_echo(cmd);
	// if (strcmp(cmd[0], "env"))
	// 	ft_env(env);
	if (strcmp(cmd[0], "pwd") == 0)
		ft_pwd(ch);
// 	if (strcmp(cmd[0], "unset"))
// 		ft_unset(env, cmd, cmd[1]);
}

int	is_builtin(char **cmd)
{
	if (strcmp(cmd[0], "pwd") == 0 || \
	strcmp(cmd[0], "echo") == 0 || \
	strcmp(cmd[0], "cd") == 0)
	// strcmp(cmd[0], "env") == 0)
		return (1);
	else
		return (0);
}
