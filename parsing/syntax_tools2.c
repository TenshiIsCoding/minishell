/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_tools2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 03:44:29 by azaher            #+#    #+#             */
/*   Updated: 2023/05/07 20:00:04 by ynafiss          ###   ########.fr       */
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

void	squote_ifcondition(char *token, int squote, int tracker, int i)
{
	squote = !squote;
	remove_index(token, i);
	tracker = 1;
	i--;
}

void	dquote_ifcondition(char *token, int dquote, int tracker, int i)
{
	dquote = !dquote;
	remove_index(token, i);
	tracker = 1;
	i--;
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
			remove_index(token, i);
			tracker = 1;
			i--;
		}
		else if (token[i] == '\"' && !squote)
		{
			dquote = !dquote;
			remove_index(token, i);
			tracker = 1;
			i--;
		}
		i++;
	}
	return (tracker);
}
