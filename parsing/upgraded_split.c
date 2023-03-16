/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upgraded_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:17:08 by azaher            #+#    #+#             */
/*   Updated: 2023/03/16 15:38:15 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*maskgen(char *str)
{
	char	*mask;
	int		i;

	i = 0;
	mask = malloc(sizeof(ft_strlen(str)));
	while (str[i])
	{
		if (str[i] == '<')
			mask[i] = '2';
		else if (str[i] == '>')
			mask[i] = '2';
		else if (str[i] == '|')
			mask[i] = '2';
		else if (str[i] == ' ')
			mask[i] = '1';
		else
			mask[i] = '0';
		i++;
	}
	return (mask);
}
