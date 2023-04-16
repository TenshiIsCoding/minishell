/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:31:36 by azaher            #+#    #+#             */
/*   Updated: 2023/04/16 09:43:04 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*expand_init(char *line, t_env *env, t_data *v)
{
	int		i;
	char	*ret;

	i = 0;
	v->squote = 0;
	v->dquote = 0;
	ret = ft_strdup("");
	while (line[i])
	{
		if ((line[i] == '$' && !var_len(line + i + 1)) || line[i] != '$')
			ret = ft_strjoin_c(ret, line[i]);
		else if (line[i] == '$')
		{
			v->varname = get_varname(line + i + 1);
			v->expenv = get_envalue(v->varname, env);
			v->freeptr = ret;
			ret = ft_strjoin(ret, v->expenv);
			(free(v->varname), free(v->expenv), free(v->freeptr));
			i += var_len(line + i + 1) + 1;
			continue ;
		}
		i++;
	}
	free(line);
	return (ret);
}
