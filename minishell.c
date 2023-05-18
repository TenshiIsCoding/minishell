/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:23:24 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/17 16:24:51 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_ret(char **ret)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ret[i])
	{
		j = 0;
		while (ret[i][j])
		{
			write(1, &ret[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	print_queue(t_queue *queue)
{
	int				i;
	t_queue_node	*node;
	t_cmd			*cmd;

	node = queue->head;
	while (node)
	{
		i = 0;
		cmd = node->ptr;
		printf("Args: ");
		while (cmd->args[i])
			printf("(%s) ", cmd->args[i++]);
		printf("\n");
		i = 0;
		printf("Files: ");
		while (cmd->files[i])
		{
			printf("(%s type: %d, in quotes: %d) ", cmd->files[i]->filename,
				cmd->files[i]->type, cmd->files[i]->inqt);
			i++;
		}
		printf("\n");
		printf("COMMANDs: %d\n", queue->len);
		node = node->next;
	}
}

void	free_cmd(void *v)
{
	t_cmd	*p;
	int		i;

	i = 0;
	p = v;
	ft_free(p->args);
	while (p->files[i])
	{
		free(p->files[i]->filename);
		free(p->files[i]);
		i++;
	}
	free(p->files);
	free(p);
}

void	while_1(t_data *vars, char **env, t_vars t, struct termios *term)
{
	t.env = full_vars(env);
	while (1)
	{
		tcgetattr(0, term);
		handle_signals(0);
		g_data.sigflag = 0;
		vars->line = readline("minishell → ");
		if (!vars->line)
			(ft_putstr_fd("exit\n", 2), exit (0));
		if (!vars->line[0] || parse_start(vars, vars->env))
		{
			if (vars->line[0])
				(add_history(vars->line), free(vars->line));
			else
				free(vars->line);
			continue ;
		}
		g_data.sigflag = 1;
		multipipe(vars, env, vars->env, t);
		(queue_free(&vars->commands, free_cmd), add_history(vars->line));
		free(vars->line);
		g_data.sigflag = 0;
		tcsetattr(0, TCSANOW, term);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data			*vars;
	t_vars			*t;
	struct termios	term;

	(void)argc;
	(void)argv;
	t = malloc(sizeof(t_vars));
	vars = malloc(sizeof(t_data));
	vars->env = full_env(env);
	g_data.g_exit = 0;
	g_data.sigflag = 0;
	t->fd_h = NULL;
	while_1(vars, env, *t, &term);
}
