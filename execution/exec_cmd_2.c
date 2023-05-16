/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:39:56 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/16 17:02:26 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	norm_l_m_cmd(t_cmd *cmd, t_vars *t, t_env **eenv)
{
	char	*path;

	if (cmd->args[0][0] == '/' || access(cmd->args[0], X_OK) == 0)
		path = cmd->args[0];
	else
		path = get((*eenv), cmd->args[0]);
	execve(path, cmd->args, t->env);
}
