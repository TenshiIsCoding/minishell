/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:09:08 by azaher            #+#    #+#             */
/*   Updated: 2023/04/16 07:33:05 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// int	in_quotes(char *token, int dollar_index)
// {
// 	int	i;
// 	int	j;
// 	int	ret;

// 	i = dollar_index;
// 	j = dollar_index;
// 	ret = 0;
// 	while (token[j] && i <= 0 && token[i] != "$" && token[j] != "$")
// 	{
// 		if (token[i] == "\'" || token[j] == "\'")
// 			ret++;
// 		else if (token[i] == "\"" || token[j] == "\"")
// 			ret += 2;
// 		j++;
// 		i--;
// 	}
// }

int	var_len(char *token)
{
	int	i;

	i = 0;
	while (token[i] && (ft_isalnum(token[i]) || token[i] == '_'
			|| token[i] == '?'))
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
		namelen = ft_strlen(name);
		if (!ft_strncmp(node->name, name, namelen))
		{
			ret = ft_strdup(node->value);
			return (ret);
		}
		node = node->next;
	}
	return (ft_strdup(""));
}
