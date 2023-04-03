/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:55:12 by azaher            #+#    #+#             */
/*   Updated: 2023/03/29 02:33:10 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_quotes(char *token)
{
	int	i;
	int	stracker;
	int	dtracker;

	i = -1;
	stracker = 0;
	dtracker = 0;
	while (token[++i])
	{
		if (token[i] == '\'')
		{
			if (stracker)
				stracker = 0;
			else if (!dtracker)
				stracker = 1;
		}
		else if (token[i] == '\"')
		{
			if (dtracker)
				dtracker = 0;
			else if (!stracker)
				dtracker = 1;
		}
	}
	return (stracker || dtracker);
}

int	check_mix_meta(char *token)
{
	int		i;
	char	temp;

	i = 0;
	temp = token[i];
	while (token[i])
	{
		if (token[i] != temp)
			return (1);
		i++;
	}
	return (0);
}

int	pipe_ends(char	*first_token, char *last_token)
{
	if (first_token[0] == '|' || last_token[0] == '|')
		return (1);
	else
		return (0);
}

int	double_pipe(char *token)
{
	return (token[1] != '\0');
}

int	double_rredirections(char *token)
{
	return (token[1] != '\0');
}
