/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:12:24 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/16 16:17:54 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*basic_expand(char *line, t_data *v, t_env *env)
{
	int		i;

	i = 0;
	v->ret = ft_strdup("");
	while (line[i])
	{
		if (line[i] == '$' && !v->squote)
		{
			i += in_dollar(v, line + i + 1, env);
			continue ;
		}
		else
			v->ret = ft_strjoin_c(v->ret, line[i]);
		i++;
	}
	return (v->ret);
}
