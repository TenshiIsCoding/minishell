/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 01:03:08 by ynafiss           #+#    #+#             */
/*   Updated: 2023/04/29 11:46:20 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_built(char **cmd, char **env, int ch, t_env **eenv)
{
	if (strcmp(cmd[0], "cd") == 0)
		ft_cd(cmd[1], env);
	if (strcmp(cmd[0], "echo") == 0)
		ft_echo(cmd);
	if (strcmp(cmd[0], "export") == 0)
		export(cmd, eenv);
	if (strcmp(cmd[0], "pwd") == 0)
		ft_pwd(ch);
	if (strcmp(cmd[0], "unset") == 0)
		ft_unset(eenv, cmd[1]);
	if (strcmp(cmd[0], "exit") == 0)
		ft_exit(cmd[1]);
	if (strcmp(cmd[0], "env") == 0)
		ft_env((*eenv));
}

int	is_builtin(char **cmd)
{
	if (strcmp(cmd[0], "pwd") == 0 || \
	strcmp(cmd[0], "echo") == 0 || \
	strcmp(cmd[0], "cd") == 0 || \
	strcmp(cmd[0], "export") == 0 || \
	strcmp(cmd[0], "unset") == 0 || \
	strcmp(cmd[0], "env") == 0 || \
	strcmp(cmd[0], "exit") == 0)
		return (1);
	else
		return (0);
}
