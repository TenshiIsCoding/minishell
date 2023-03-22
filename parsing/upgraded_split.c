/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upgraded_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:40:38 by azaher            #+#    #+#             */
/*   Updated: 2023/03/22 18:12:53 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* 			duplicates string considering the given coordinates				*/

char	*dup_coord(char *str, int start, int end)
{
	char	*ret;
	int		i;
	int		j;

	ret = malloc((end - start + 2) * sizeof(char));
	i = start;
	j = 0;
	while (i <= end)
	{
		ret[i] = str[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}

int	token_fill(char **token, char *mask, char *str, int i)
{
	int		len;
	int		temp;
	int		index;
	char	*token_temp;

	len = 0;
	temp = mask[i];
	index = 0;
	while (mask[len + i] == temp)
		len++;
	printf("%d", len);
	*token = malloc((len + 1) * sizeof(char));
	token_temp = *token;
	while (mask[i] == temp)
	{
		token_temp[index] = str[i];
		index++;
		i++;
	}
	token_temp[index] = '\0';
	return (i);
}

char	**upgraded_split(t_data *vars)
{
	char	**ret;
	char	temp;
	int		i;
	int		j;

	maskgen(vars);
	i = token_count(vars);
	ret = malloc((i + 1) * sizeof(char *));
	i = 0;
	j = 0;
	temp = vars->mask[i];
	while (vars->mask[i])
	{
		if (vars->mask[i] != '1')
		{
			i = token_fill(ret + j, vars->mask, vars->line, i);
			j++;
			continue ;
		}
		i++;
	}
	ret[j] = NULL;
	return (ret);
}
