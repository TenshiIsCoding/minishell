/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 06:53:03 by azaher            #+#    #+#             */
/*   Updated: 2023/04/03 09:24:55 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	alloc_tmp(t_data *v)
{
	v->ndtmp->content->args = ft_calloc((v->argln + 1), sizeof(char *));
	v->ndtmp->content->outf = ft_calloc((v->outln + 1), sizeof(char *));
	v->ndtmp->content->infl = ft_calloc((v->inln + 1), sizeof(char *));
}

void	init_values(t_data *v)
{
	v->argln = 0;
	v->outln = 0;
	v->inln = 0;
	v->ndtmp = ft_calloc(sizeof(t_node), 1);
	v->ndtmp->content = ft_calloc(sizeof(t_cmd), 1);
	v->ndtmp->next = NULL;
	v->cmds = ft_calloc(sizeof(t_node), 1);
	v->cmds->content = ft_calloc(sizeof(t_cmd), 1);
	v->cmds->next = NULL;
}

void	assign_alloc(t_data *v)
{
	int	i;

	i = 0;
	init_values(v);
	while (v->splt[i])
	{
		if (!ft_strchr("<|>", v->splt[i][0]))
			v->argln++;
		else if (ft_strchr("<", v->splt[i][0]))
		{
			v->inln++;
			v->argln--;
		}
		else if (ft_strchr(">", v->splt[i][0]))
		{
			v->outln++;
			v->argln--;
		}
		i++;
	}
	v->cmds->content->args = ft_calloc((v->argln + 1), sizeof(char *));
	v->cmds->content->outf = ft_calloc((v->outln + 1), sizeof(char *));
	v->cmds->content->infl = ft_calloc((v->inln + 1), sizeof(char *));
	alloc_tmp(v);
}

void	send_data(t_data *v)
{
	int		i;

	i = 0;
	v->argdx = 0;
	v->outdx = 0;
	v->infdx = 0;
	v->cmdcount = 0;
	assign_alloc(v);
	while (v->splt[i])
	{
		if (v->splt[i][0] == '|')
		{
			// if (v->cmdcount == 0)
			// {
			// 	v->cmds->content = v->ndtmp->content;
			// 	v->cmds->next = v->ndtmp->next->next;
			// }
			ft_lstback_add(&v->cmds, v->ndtmp);
			v->ndtmp = malloc(sizeof(t_node));
			v->ndtmp->content = ft_calloc(sizeof(t_cmd), 1);
			v->ndtmp->next = NULL;
			alloc_tmp(v);
			v->cmdcount++;
			v->argdx = 0;
			v->outdx = 0;
			v->infdx = 0;
		}
		else if (v->splt[i][0] == '<')
		{
			v->ndtmp->content->infl[v->infdx] = strdup(v->splt[i + 1]);
			v->infdx++;
			i += 2;
			continue ;
		}
		else if (v->splt[i][0] == '>')
		{
			v->ndtmp->content->outf[v->outdx] = strdup(v->splt[i + 1]);
			v->outdx++;
			i += 2;
			continue ;
		}
		//else if >>
		else
		{
			v->ndtmp->content->args[v->argdx] = strdup(v->splt[i]);
			v->argdx++;
		}
		i++;
	}
	if(i != 0)
	{
		ft_lstback_add(&v->cmds, v->ndtmp);
		v->cmdcount++;
	}
}

void	parse_start(t_data *vars)
{
	vars->splt = upgraded_split(vars);
	if (syntax_checker(vars->splt))
	{
		printf("minishell: syntax error near unexpected token\n");
		vars->status = 258;
		return ;
	}
	send_data(vars);
	ft_free(vars->splt);
	free(vars->mask);
}
