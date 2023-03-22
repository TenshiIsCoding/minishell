/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:18:45 by ynafiss           #+#    #+#             */
/*   Updated: 2023/03/22 17:52:10 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_unset(char **env, char *name, int size)
{
	// t_env	*pre;
	// t_env	*cur;
	(void)size;
	char **tmp;
	int i = 0;

	while (env[i])
		i++;
	tmp = malloc(sizeof(char *) * i + 1);

	// cur = *env;
	// pre = NULL;
	i = 0;
	while (env[i])
	{
		tmp[i] = ft_strdup(env[i]);
		i++;
	}
	i = 0;
	while (tmp[i] != NULL && ft_strncmp(tmp[i], name, ft_strlen(name) - 1) != 0)
	{
		i++;
	}
	tmp[i][0] = '\0';
	i = 0;
	return (tmp);
}