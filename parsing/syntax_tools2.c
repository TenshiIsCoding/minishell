/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_tools2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 03:44:29 by azaher            #+#    #+#             */
/*   Updated: 2023/05/07 22:08:52 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	triple_lredirections(char *token)
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

void	remove_index(char *string, int index)
{
	int	i;

	i = index;
	while (string[i])
	{
		string[i] = string[i + 1];
		i++;
	}
}

int	remove_quotes(char *token)
{
	int	i;
	int	tracker;
	int	squote;
	int	dquote;

	i = 0;
	squote = 0;
	dquote = 0;
	tracker = 0;
	while (token[i])
	{
		if (token[i] == '\'' && !dquote)
		{
			squote = !squote;
			// token[i] = SQUOTE;
			remove_index(token, i);
			tracker = 1;
		}
		else if (token[i] == '\"' && !squote)
		{
			dquote = !dquote;
			// token[i] = DQUOTE;
			remove_index(token, i);
			tracker = 1;
		}
		i++;
	}
	return (tracker);
}
