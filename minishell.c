/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:30:23 by azaher            #+#    #+#             */
/*   Updated: 2023/05/01 15:14:49 by azaher           ###   ########.fr       */
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

void	hard_list(t_node *node)
{
	t_node	*tmp;

	if (node == NULL)
		return ;
	tmp = node->next->next;
	node->content = node->next->content;
	node->next = node->next->next;
	free(tmp);
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

int	main(int argc, char **argv, char **env)
{
	t_data	*vars;

	(void)argc;
	(void)argv;
	vars = malloc(sizeof(t_data));
	vars->env = full_env(env);
	while (1)
	{
		vars->line = readline("minishell$ ");
		if (!vars->line)
			break ;
		if (!vars->line[0])
			continue ;
		if (parse_start(vars, vars->env))
			continue ;
		multipipe(&vars->commands, env, &vars->env);
		print_queue(&vars->commands);
		queue_free(&vars->commands, free_cmd);
		add_history(vars->line);
		free(vars->line);
	}
}
