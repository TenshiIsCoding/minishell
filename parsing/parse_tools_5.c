/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:53:24 by azaher            #+#    #+#             */
/*   Updated: 2023/05/07 19:32:50 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ambig_token_count(char *mask)
{
	int		i;
	int		count;
	char	prev_mask;

	i = 0;
	count = 0;
	prev_mask = '1';
	while (mask[i])
	{
		if (mask[i] == '0' && prev_mask != '0')
			count++;
		else if (mask[i] == '2' && prev_mask != '2')
			count++;
		prev_mask = mask[i];
		i++;
	}
	return (count);
}

int	ambig_token_fill(char **token, char *mask, char *str, int i)
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

char	**ambig_upgraded_split(char *token, char *mask)
{
	char	**ret;
	char	temp;
	int		i;
	int		j;

	i = ambig_token_count(mask);
	ret = malloc((i + 1) * sizeof(char *));
	i = 0;
	j = 0;
	temp = mask[i];
	while (mask[i])
	{
		if (mask[i] != '1')
		{
			i = ambig_token_fill(ret + j, mask, token, i);
			j++;
			continue ;
		}
		i++;
	}
	ret[j] = NULL;
	return (ret);
}
