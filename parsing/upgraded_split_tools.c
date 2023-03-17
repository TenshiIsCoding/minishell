/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upgraded_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:17:08 by azaher            #+#    #+#             */
/*   Updated: 2023/03/17 02:33:49 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	difelse(t_data *vars, int i)
{
	if (vars->dquote)
	{
		vars->dquote = 0;
		vars->mask[i] = '0';
	}
	else if (!vars->squote)
	{
		vars->dquote = 1;
		vars->mask[i] = '0';
	}
	else
		vars->mask[i] = '0';
}

void	sifelse(t_data *vars, int i)
{
	if (vars->squote)
	{
		vars->squote = 0;
		vars->mask[i] = '0';
	}
	else if (!vars->dquote)
	{
		vars->squote = 1;
		vars->mask[i] = '0';
	}
	else
		vars->mask[i] = '0';
}

void	ifelse(t_data *vars, int i)
{
	if (vars->squote || vars->dquote)
		vars->mask[i] = '0';
	else
	{
		if (vars->line[i] == ' ')
			vars->mask[i] = '1';
		else if (vars->line[i] == '<' || vars->line[i] == '>'
			|| vars->line[i] == '|')
			vars->mask[i] = '2';
	}
}

void	maskgen(t_data *vars)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(vars->line);
	vars->dquote = 0;
	vars->squote = 0;
	vars->mask = malloc(len * sizeof(char));
	while (i < len)
	{
		if (vars->line[i] == ' ')
			ifelse(vars, i);
		else if (vars->line[i] == '<' || vars->line[i] == '>'
			|| vars->line[i] == '|')
			ifelse(vars, i);
		else if (vars->line[i] == '\'')
			sifelse(vars, i);
		else if (vars->line[i] == '\"')
			difelse(vars, i);
		else
			vars->mask[i] = '0';
		i++;
	}
	vars->mask[i] = '\0';
}
