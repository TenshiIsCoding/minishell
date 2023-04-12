/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:31:36 by azaher            #+#    #+#             */
/*   Updated: 2023/04/12 06:48:53 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*expand_basic(char *token, t_env *env)
{
	int		i;
	char	*freeptr;
	char	*ret;
	char	*varname;
	char	*expenv;

	i = 0;
	ret = ft_strdup("");
	while (token[i])
	{
		if ((token[i] == '$' && !var_len(token + i + 1)) || token[i] != '$')
			ret = ft_strjoin_c(ret, token[i]);
		else if (token[i] == '$')
		{
			varname = get_varname(token + i + 1);
			expenv = get_envalue(varname, env);
			freeptr = ret;
			ret = ft_strjoin(ret, expenv);
			(free(varname), free(expenv), free(freeptr));
			i += var_len(token + i + 1) + 1;
			continue ;
		}
		i++;
	}
	return (ret);
}
