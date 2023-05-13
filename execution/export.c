/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 09:26:25 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/11 17:40:02 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_var(t_env **env, char *var)
{
	t_env	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(t_env));
	while (var[i] != '\0' && var[i] != '=')
		i++;
	if (var[i] == '=')
		i++;
	new->name = expo_substr(var, 0, i);
	new->value = ft_strdup(var + i);
	new->next = NULL;
	ft_lstadd_back(env, new);
}

void	update_value(t_env *env, char *new_value)
{
	if (env != NULL)
	{
		if (env->value != NULL)
			free(env->value);
		if (new_value != NULL)
			env->value = ft_strdup(new_value);
		else
			env->value = NULL;
	}
}

void	over_add(t_env **env, char *var)
{
	int		i;
	char	*str;
	char	*app;
	t_env	*current_env;

	i = 0;
	current_env = *env;
	while (var[i] != '\0' && var[i] != '=')
		i++;
	if (var[i] == '=')
	{
		str = ft_substr(var, 0, i);
		while (current_env != NULL && \
		ft_strcmp(current_env->name, str) != 0)
			current_env = current_env->next;
		if (current_env != NULL)
		{
			if (var[i - 1] == '+')
			{
				update_value(current_env, var);
				app = ft_strjoin(current_env->value, var + i);
			}
			else
				update_value(current_env, var + i);
		}
		free(str);
	}
}

int	export(char **cmd, t_env **env)
{
	int	i;

	i = 1;
	if (cmd[1] == NULL)
	{
		export_print((*env), (ft_lstsize(*env) - 1));
		g_exit = 0;
	}
	else
	{
		while (cmd[i])
		{
			g_exit = check_valid(cmd[i]);
			if (g_exit == 0)
			{
				if (check_exist((*env), cmd[i]) == 0)
					add_var(env, cmd[i]);
				else
					over_add(env, cmd[i]);
			}
			i++;
		}
	}
	return (g_exit);
}
