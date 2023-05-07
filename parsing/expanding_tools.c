/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:09:08 by azaher            #+#    #+#             */
/*   Updated: 2023/05/03 17:57:34 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	var_len(char *token)
{
	int	i;

	i = 0;
	while (token[i] && token[i] != '$' && (ft_isalnum(token[i])
			|| token[i] == '_' || token[i] == '?'))
		i++;
	return (i);
}

char	*ft_strjoin_c(char *str, char c)
{
	char	*ret;
	int		i;

	i = 0;
	ret = calloc((strlen(str) + 2), sizeof(char));
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = c;
	ret[i + 1] = 0;
	if (str)
		free(str);
	return (ret);
}

char	*get_varname(char *token)
{
	int		i;
	int		retlen;
	char	*ret;

	i = 0;
	retlen = var_len(token);
	ret = malloc((retlen + 1) * sizeof(char));
	while (token[i] && (ft_isalnum(token[i]) || token[i] == '_'
			|| token[i] == '?'))
	{
		ret[i] = token[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	*get_envalue(char *name, t_env *env)
{
	t_env	*node;
	char	*ret;
	int		namelen;

	node = env;
	while (node)
	{
		namelen = ft_strlen(node->name) - 1;
		if (!ft_strcmp("?", name))
		{
			ret = ft_strdup(ft_itoa(g_exit));
			return (ret);
		}
		else if (!ft_strncmp(node->name, name, namelen))
		{
			ret = ft_strdup(node->value);
			return (ret);
		}
		node = node->next;
	}
	return (ft_strdup(""));
}
