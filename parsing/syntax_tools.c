/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:55:12 by azaher            #+#    #+#             */
/*   Updated: 2023/05/06 22:09:23 by azaher           ###   ########.fr       */
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

int	two_pipe_tokens(char	*first_token, char *next_token)
{
	if (first_token[0] == '|' && next_token[0] == '|')
		return (1);
	else
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

int	triple_rredirections(char *token)
{
	int	i;
	int	tracker;

	i = 1;
	tracker = 1;
	while (token[i])
	{
		if (token[i] == '<')
			tracker++;
		i++;
	}
	if (tracker > 2)
		return (1);
	else
		return (0);
}
