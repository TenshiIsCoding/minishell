/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:36:45 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/16 16:24:26 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_here(t_norm n, t_cmd *cmd, t_data *var, t_env *env)
{
	char	*expand;

	expand = basic_expand(n.line_r, var, env);
	if (n.i == last_here(cmd->files) && cmd->files[n.i]->inqt == 0)
		(ft_putstr_fd(expand, n.pi[1]), write(n.pi[1], "\n", 1));
	if (n.i == last_here(cmd->files) && cmd->files[n.i]->inqt == 1)
		(ft_putstr_fd(n.line_r, n.pi[1]), write(n.pi[1], "\n", 1));
	free(expand);
}

void	main_while(t_norm n, t_cmd *cmd, t_data *var, t_env *env)
{
	n.line_r = NULL;
	while (1)
	{
		n.line_r = readline("> ");
		if (!n.line_r || \
		!ft_strcmp(cmd->files[n.i]->filename, n.line_r))
		{
			free(n.line_r);
			break ;
		}
		print_here(n, cmd, var, env);
		free(n.line_r);
	}
}

void	norm_here(t_cmd *cmd, t_norm n, t_env *env, t_data *var)
{
	struct termios	term;

	n.i = 0;
	if (n.ch == 0)
	{
		tcgetattr(STDIN_FILENO, &term);
		here_signal(term);
		while (cmd->files[n.i])
		{
			if (cmd->files[n.i]->type == HERE)
				main_while(n, cmd, var, env);
			n.i++;
		}
		exit(0);
	}
}
