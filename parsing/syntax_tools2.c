/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_tools2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 03:44:29 by azaher            #+#    #+#             */
/*   Updated: 2023/05/07 19:58:25 by azaher           ###   ########.fr       */
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

int	remove_quotes(char *token, t_data *v)
{
	int	i;

	i = 0;
	v->sqt = 0;
	v->dqt = 0;
	v->tracker = 0;
	while (token[i])
	{
		if (token[i] == '\'' && !v->dqt)
		{
			v->sqt = !v->sqt;
			// remove_index(token, i);
			// v->tracker = 1;
			// i--;
		}
		else if (token[i] == '\"' && !v->sqt)
		{
			v->dqt = !v->dqt;
			// remove_index(token, i);
			// v->tracker = 1;
			// i--;
		}
		i++;
	}
	return (v->tracker);
}
