/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:28:09 by azaher            #+#    #+#             */
/*   Updated: 2023/04/30 20:53:04 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	in_dollar(t_data *v, char *line, t_env *env)
{
	v->varname = get_varname(line);
	v->expenv = get_envalue(v->varname, env);
	v->freeptr = v->ret;
	v->ret = ft_strjoin(v->ret, v->expenv);
	(free(v->varname), free(v->expenv), free(v->freeptr));
	return (var_len(line) + 1);
}

void	squote_ifcon(t_data *v, char c)
{
	v->squote = !v->squote;
	v->ret = ft_strjoin_c(v->ret, c);
}

void	dquote_ifcon(t_data *v, char c)
{
	v->dquote = !v->dquote;
	v->ret = ft_strjoin_c(v->ret, c);
}

char	*expand_argument(char *line, t_data *v, t_env *env)
{
	int		i;

	i = 0;
	v->squote = 0;
	v->dquote = 0;
	v->ret = ft_strdup("");
	while (line[i])
	{
		if (line[i] == '\'' && !v->dquote)
			squote_ifcon(v, line[i]);
		else if (line[i] == '\"' && !v->squote)
			dquote_ifcon(v, line[i]);
		else if (line[i] == '$' && !v->squote)
		{
			i += in_dollar(v, line + i + 1, env);
			continue ;
		}
		else
			v->ret = ft_strjoin_c(v->ret, line[i]);
		i++;
	}
	free(line);
	return (v->ret);
}
