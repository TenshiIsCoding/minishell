/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:55:09 by azaher            #+#    #+#             */
/*   Updated: 2023/04/08 05:24:56 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	token_len(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		i++;
	return (i);
}

int	ifelse_ret(char *token, char *next_token)
{
	if (ft_strchr("><|", token[0]))
	{
		if (check_mix_meta(token))
			return (1);
		if (token[0] == '|')
			return (double_pipe(token));
		else if (token[0] == '>')
			return (triple_rredirections(token) || next_token == NULL);
		else if (token[0] == '<')
			return (triple_lredirections(token) || next_token == NULL);
	}
	return (check_quotes(token));
}

int	syntax_checker(char	**tokens)
{
	int	i;
	int	ret;

	i = token_len(tokens);
	if (pipe_ends(tokens[0], tokens[i - 1]))
		return (1);
	i = -1;
	ret = 0;
	while (tokens[++i])
	{
		if (ifelse_ret(tokens[i], tokens[i + 1]))
			ret++;
	}	
	return (ret);
}
