/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:13:24 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/09 17:38:21 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_exist(t_env *env, char *var)
{
	t_env	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = env;
	while (var[j] != '\0' && var[j] != '=')
		j++;
	if (var[j] == '=')
		j++;
	while (env)
	{
		if (ft_strncmp(env->name, var, j) == 0)
			return (1);
		env = env->next;
	}
	env = tmp;
	return (0);
}
