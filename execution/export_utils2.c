/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:13:24 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/11 11:17:41 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_p_e(char c1, char c2)
{
	if (c1 == '+' && c2 == '=')
		return (1);
	return (0);
}

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
		if (check_p_e(var[i], var[i + 1]) == 0 && \
		(ft_isalpha(var[i]) == 0 && ft_isdigit(var[i]) == 0 && \
		var[i] != '_'))
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
	char	*str;

	i = 0;
	j = 0;
	tmp = env;
	while (var[j] != '\0' && var[j] != '=' && var[j] != '+')
		j++;
	str = ft_substr(var, 0, j);
	while (env)
	{
		if (ft_strcmp(env->name, str) == 0)
		{
			free(str);
			return (1);
		}
		env = env->next;
	}
	env = tmp;
	free(str);
	return (0);
}
