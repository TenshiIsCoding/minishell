/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upgraded_split_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:17:08 by azaher            #+#    #+#             */
/*   Updated: 2023/03/22 19:51:54 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*	   replaces normal charaters by 0 and checks if in double quote	    */

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

/*	   	replaces normal charaters by 0 and checks if in single quote	*/

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

/*	   		replaces space with 1 and other tokens with 2			*/

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

/*tokenize and give each input a certain number to help with spliting/parsing*/

void	maskgen(t_data *vars)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(vars->line);
	vars->dquote = 0;
	vars->squote = 0;
	vars->mask = malloc((len + 1) * sizeof(char));
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

/*                     counts tokens in the mask                           */

int	token_count(t_data *vars)
{
	int		i;
	int		count;
	char	prev_mask;

	i = 0;
	count = 0;
	prev_mask = '1';
	while (vars->mask[i])
	{
		if (vars->mask[i] == '0' && prev_mask != '0')
			count++;
		else if (vars->mask[i] == '2' && prev_mask != '2')
			count++;
		prev_mask = vars->mask[i];
		i++;
	}
	return (count);
}
