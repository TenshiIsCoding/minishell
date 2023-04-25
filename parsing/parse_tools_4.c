/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:28:09 by azaher            #+#    #+#             */
/*   Updated: 2023/04/17 03:17:40 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*expand_argument(char *line, t_data *v, t_env *env)
{
	int		i;
	char	*ret;

	i = 0;
	v->squote = 0;
	v->dquote = 0;
	ret = ft_strdup("");
	while (line[i])
	{
		if (line[i] == '\'' && !v->dquote)
		{
			v->squote = !v->squote;
			ret = ft_strjoin_c(ret, line[i]);
		}
		else if (line[i] == '\"' && !v->squote)
		{
			v->dquote = !v->dquote;
			ret = ft_strjoin_c(ret, line[i]);
		}
		else if (line[i] == '$' && !v->squote)
		{
			v->varname = get_varname(line + i + 1);
			v->expenv = get_envalue(v->varname, env);
			v->freeptr = ret;
			ret = ft_strjoin(ret, v->expenv);
			(free(v->varname), free(v->expenv), free(v->freeptr));
			i += var_len(line + i + 1) + 1;
			continue ;
		}
		else
			ret = ft_strjoin_c(ret, line[i]);
		i++;
	}
	free(line);
	return (ret);
}

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
