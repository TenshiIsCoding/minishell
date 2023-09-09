/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:04:42 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/16 14:04:59 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*full_cmp(char *var, int j)
{
	char	*cmp;
	char	*str;

	if (var[j] == '=')
	{
		j++;
		str = ft_substr(var, 0, j);
		cmp = ft_strdup(str);
	}
	else
	{
		str = ft_substr(var, 0, j);
		cmp = ft_strjoin(str, "=");
	}
	free(str);
	return (cmp);
}

char	*full_final(char *var, int j)
{
	char	*str;
	char	*final;

	str = ft_substr(var, 0, j);
	final = ft_strjoin(str, "=");
	free(str);
	return (final);
}
