/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:03:03 by ynafiss           #+#    #+#             */
/*   Updated: 2023/04/14 01:04:27 by ynafiss          ###   ########.fr       */
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
