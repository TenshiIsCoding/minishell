/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 09:26:25 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/14 17:54:22 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


char	*expo_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	sub = malloc (sizeof (char) * (len + 1));
	if (!sub)
		return (NULL);
	while (s && s[i] != '\0' && len != 0)
	{
		if (s[start + i] == '+')
		{
			sub[i] = '=';
			i++;
			break ;
		}
		sub[i] = s[start + i];
		i++;
		len--;
	}
	sub[i] = '\0';
	return (sub);
}

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
	printf("%s\n", new->name);
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
		printf("*** %s ***\n", str);
		while (current_env != NULL && \
		ft_strcmp(current_env->name, str) != 0)
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
	printf("%s\n", cmp);
	while (current_env != NULL && \
	ft_strcmp(current_env->name, cmp) != 0)
		current_env = current_env->next;
	if (current_env != NULL)
	{
		printf("%s\n", var);
		app = ft_strjoin(current_env->value, var + i);
		update_value(current_env, app);
	}
}

int	export(char **cmd, t_env **env)
{
	int		i;
	char	*cmp;

	i = 1;
	if (cmd[1] == NULL)
	{
		export_print((*env), (ft_lstsize(*env) - 1));
		g_data.g_exit = 0;
	}
	else
	{
		while (cmd[i])
		{
			g_data.g_exit = check_valid(cmd[i]);
			if (g_data.g_exit == 0)
			{
				cmp = check_exist_1((*env), cmd[i]);
				printf("%s\n", cmp);
				if (cmp == NULL)
				{
					printf("%d\n", check_exist((*env), cmd[i]));
					if (check_exist((*env), cmd[i]) == 0)
						add_var(env, cmd[i]);
					else
						over_add(env, cmd[i]);
				}
				else
					append(env, cmd[i], cmp);
			}
			i++;
		}
	}
	return (g_data.g_exit);
}

