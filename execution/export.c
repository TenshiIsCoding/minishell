/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 09:26:25 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/04 15:50:56 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_valid_id(char *var)
{
	int	i;

	i = 0;
	while (var[i] && var[i] != '=')
	{
		if (!ft_isalpha(var[i]) && var[i] != '=')
			return (0);
		i++;
	}
	return (1);
}

void	add_var(t_env **env, char *var)
{
	t_env	*new;
	int		i;

	if (check_valid_id(var) == 0)
	{
		ft_putstr_fd(var, 2);
		write(2, ": not a valid identifier \n", 26);
	}
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
	free(env->value);
	env->value = strdup(new_value);
}

void	over_add(t_env **env, char *var)
{
	int		i;
	char	*un;
	t_env	*new;

	i = 0;
	new = *env;
	while (var[i] != '\0' && var[i] != '=')
		i++;
	un = ft_substr(var, 0, i);
	while (*env != NULL && strcmp((*env)->name, un) != 0)
		*env = (*env)->next;
	update_value((*env), var + i);
	(*env) = new;
}

void	export(char **cmd, t_env **env)
{
	int	i;

	i = 1;
	if (cmd[1] == NULL)
		export_print((*env), (ft_lstsize(*env) - 1));
	else
	{
		while (cmd[i])
		{
			if (check_exist((*env), cmd[i]) == 0)
				add_var(env, cmd[i]);
			else
				over_add(env, cmd[i]);
			i++;
		}
	}
}
