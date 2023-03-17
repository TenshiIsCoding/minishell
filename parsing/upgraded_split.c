/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upgraded_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:17:08 by azaher            #+#    #+#             */
/*   Updated: 2023/03/17 01:20:06 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*maskgen(char *str, t_data *vars)
{
	char	*mask;
	char	*quote;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	vars->mask = 0;
	mask = malloc(sizeof(len) * sizeof(char));
	if (mask == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] == ' ')
			mask[i] = '1';
		else if (str[i] == '<' || str[i] == '>', str[i] == '|')
			mask[i] = '2';
		else if (str[i] == '\'' || str[i] == '\"')
		{
			mask[i] = '0';
			quote = str[i];
			i++;
			while (i < len && str[i] != quote)
			{
				str[i] = '0';
				i++;
			}
		}
		else
			mask[i] = '0';
		i++;
	}
	return (mask);
}
