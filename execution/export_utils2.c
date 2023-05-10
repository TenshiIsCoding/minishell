/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:13:24 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/09 18:06:27 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_valid(char *var)
{
	int	i;

	i = 1;
	if (var == NULL)
		return (0);
	if (var[0] != '_' && ft_isalpha(var[0]) == 0)
	{
		ft_putstr_fd(var, 2);
		write(2, ": not a valid identifier\n", 25);
		return (1);
	}
	while (var[i] != '\0' && var[i] != '=')
	{
		if (ft_isalpha(var[i]) && ft_isdigit(var[i]) && var[i] != '_')
		{
			ft_putstr_fd(var, 2);
			write(2, ": not a valid identifier\n", 25);
			return (1);
		}
		i++;
	}
	return (0);
}

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
