/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:30:23 by azaher            #+#    #+#             */
/*   Updated: 2023/04/03 09:49:26 by azaher           ###   ########.fr       */
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

void	print_list(t_node *node)
{
	while(node != NULL) {
	printf("%s\n", node->content->args[0]);
	node = node->next;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	*vars;

	(void)argc;
	(void)argv;
	(void)env;
	vars = malloc(sizeof(t_data));
	while (1)
	{
		vars->line = readline("minishell$ ");
		// vars->line = "ls | la";
		if (!vars->line)
			break ;
		if (!vars->line[0])
			continue ;
		parse_start(vars);
		if (vars->status != 258)
			hard_list(vars->cmds);
		print_list(vars->cmds);
	//	char **ret = upgraded_split(vars);
	//	print_ret(ret);
		add_history(vars->line);
		free(vars->line);
	}
}

/*≈


00122222222210
ls >>>>>|||| p
[ls, >>>>>|||, p]

00122222333310
ls >>>>>|||| p
[ls, >>>>>, |||||, p]

<>| outside '' "" 2
\t\n\v 1
else 0
	dump shit
*/

/*≈


00122222222210
ls >>>>>|||| p
[ls, >>>>>|||, p]

00122222333310
ls >>>>>|||| p
[ls, >>>>>, |||||, p]

<>| outside '' "" 2
\t\n\v 1
else 0

*/