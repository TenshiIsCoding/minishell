/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 09:26:25 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/17 15:48:25 by ynafiss          ###   ########.fr       */
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
	new->name = export_strdup(var);
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
	t_env	*current_env;

	i = 0;
	current_env = *env;
	while (var[i] != '\0' && var[i] != '=')
		i++;
	if (var[i] == '=')
	{
		i++;
		str = ft_substr(var, 0, i);
		while (current_env != NULL && \
		export_strcmp(current_env->name, str) != 0)
			current_env = current_env->next;
		if (current_env != NULL)
			update_value(current_env, var + i);
		free(str);
	}
}

void	append(t_env **env, char *var, char *cmp)
{
	int		i;
	char	*app;
	t_env	*current_env;

	i = ft_strlen(cmp) + 1;
	current_env = *env;
	while (current_env != NULL && \
	ft_strcmp(current_env->name, cmp) != 0)
		current_env = current_env->next;
	if (current_env != NULL)
	{
		app = ft_strjoin(current_env->value, var + i);
		update_value(current_env, app);
		free(app);
	}
}

int	export(char **cmd, t_env **env)
{
	int		i;
	char	*cmp;

	i = 1;
	if (cmd[1] == NULL)
		export_print((*env), (ft_lstsize(*env) - 1));
	else if ((*env))
	{
		while (cmd[i])
		{
			g_data.g_exit = check_valid(cmd[i]);
			if (g_data.g_exit == 0)
			{
				cmp = check_exist_1((*env), cmd[i]);
				if (cmp == NULL)
					creat_var(cmd[i], env);
				else
					append(env, cmd[i], cmp);
				free (cmp);
			}
			i++;
		}
	}
	return (g_data.g_exit);
}
//env
//permission
//exit 4 dfg