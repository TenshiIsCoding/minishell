/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:03:03 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/09 20:54:18 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*full_env(char **env)
{
	t_env	*ee;
	t_env	*head;
	int		i;
	int		j;

	i = 0;
	while (env[i])
	{
		ee = malloc(sizeof(t_env));
		if (i == 0)
			head = ee;
		j = 0;
		while (env[i][j] != '\0' && env[i][j] != '=')
			j++;
		if (env[i][j] == '=')
			j++;
		ee->name = ft_substr(env[i], 0, j);
		ee->value = ft_strdup(env[i] + j);
		ee->next = NULL;
		if (i > 0)
			ft_lstadd_back(&head, ee);
		i++;
	}
	return (head);
}

char	**full_vars(char **env)
{
	char	**ee;
	int		i;

	i = 0;
	ee = (char **)malloc(sizeof(char **) * 40);
	while (env[i])
	{
		ee[i] = ft_strdup(env[i]);
		i++;
	}
	ee[i] = NULL;
	return (ee);
}
