/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upgraded_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:40:38 by azaher            #+#    #+#             */
/*   Updated: 2023/05/06 21:07:20 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
	free (ret);
}

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

/*	 	fills the allocated token and returns the i to incrament it		*/

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

/*  	iterates through the mask and splits where the 1's are found	 */

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
