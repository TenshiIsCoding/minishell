/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:56:35 by azaher            #+#    #+#             */
/*   Updated: 2023/04/17 01:33:21 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_splitable(char **varvalue)
{
	int		size;

	size = 0;
	while (varvalue[size])
	{
		size++;
	}
	if (size > 1)
		return (1);
	else
		return (0);
}

void	ambig_difelse(t_data *vars, char *ret, int i)
{
	if (vars->dquote)
	{
		vars->dquote = 0;
		ret[i] = '0';
	}
	else if (!vars->squote)
	{
		vars->dquote = 1;
		ret[i] = '0';
	}
	else
		ret[i] = '0';
}

void	ambig_sifelse(t_data *vars, char *ret, int i)
{
	if (vars->squote)
	{
		vars->squote = 0;
		ret[i] = '0';
	}
	else if (!vars->dquote)
	{
		vars->squote = 1;
		ret[i] = '0';
	}
	else
		ret[i] = '0';
}

void	ambig_ifelse(char *ret, t_data *vars, int i)
{
	if (vars->squote || vars->dquote)
		ret[i] = '0';
	else
		ret[i] = '1';
}

char	*maskgen_01(char *token, t_data *vars)
{
	int		i;
	int		len;
	char	*ret;

	i = 0;
	len = ft_strlen(token);
	vars->dquote = 0;
	vars->squote = 0;
	ret = malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		if (token[i] == ' ')
			ambig_ifelse(ret, vars, i);
		else if (token[i] == '\'')
			ambig_sifelse(vars, ret, i);
		else if (token[i] == '\"')
			ambig_difelse(vars, ret, i);
		else
			ret[i] = '0';
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
