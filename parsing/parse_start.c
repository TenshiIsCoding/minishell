/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 06:53:03 by azaher            #+#    #+#             */
/*   Updated: 2023/04/12 03:47:18 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pass_data(t_data *v)
{
	int	i;

	i = 0;
	v->pipedex = 0;
	queue_init(&v->commands);
	while (v->splt[v->pipedex])
	{
		if (v->splt[v->pipedex][0] == '|')
			v->pipedex++;
		queue_insert(&v->commands, get_cmd(v->splt, v));
	}
}

int	parse_start(t_data *vars)
{
	vars->splt = upgraded_split(vars);
	if (syntax_checker(vars->splt))
	{
		write(2, "minishell: syntax error near unexpected token\n", 46);
		vars->status = 258;
		ft_free(vars->splt);
		free(vars->mask);
		return (1);
	}
	pass_data(vars);
	ft_free(vars->splt);
	free(vars->mask);
	return (0);
}
