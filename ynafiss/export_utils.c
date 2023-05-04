/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 02:43:18 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/03 17:15:08 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_putstr_export(char *name, char *value)
{
	int	i;
	int	co;

	i = 0;
	co = 0;
	while (name[i])
	{
		if (co == 1 && name[i] == '\'' && name[i - 1] != '=')
			write(1, &name[i], 1);
		if (name[i] != '\'')
			write(1, &name[i], 1);
		if (name[i] == '=' && co == 0)
		{
			write(1, "\"", 1);
			co = 1;
		}
		i++;
	}
	i = 0;
	while (value[i])
	{
		if (co == 1 && value[i] == '\'' && value[i - 1] != '=')
			write(1, &value[i], 1);
		if (value[i] != '\'')
			write(1, &value[i], 1);
		if (value[i] == '=' && co == 0)
		{
			write(1, "\"", 1);
			co = 1;
		}
		i++;
	}
	if (co == 1)
		write(1, "\"", 1);
}

void	cmp_print(t_env *env, char **str)
{
	int		i;
	int		j;
	t_env	*tmp;

	i = 0;
	j = 0;
	tmp = env;
	while (str[i])
	{
		env = tmp;
		while (env)
		{
			if (ft_strcmp(env->name, str[i]) == 0)
			{
				write(1, "declare -x ", 11);
				ft_putstr_export(env->name, env->value);
				write(1, "\n", 1);
				break ;
			}
			env = env->next;
		}
		i++;
	}
}

void	export_print(t_env *env, int limit)
{
	char	**str;
	char	*alpha;
	t_env	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = env;
	str = (char **)malloc(sizeof (char *) * (ft_lstsize((env)) + 1));
	while (env)
	{
		str[i] = ft_strdup(env->name);
		env = env->next;
		i++;
	}
	str[i] = NULL;
	i = 0;
	while (limit >= i)
	{
		j = 0;
		while (limit - 1 >= j)
		{
			if (ft_strcmp(str[j], str[j + 1]) > 0)
			{
				alpha = str[j];
				str[j] = str[j + 1];
				str[j + 1] = alpha;
			}
			j++;
		}
		i++;
	}
	env = tmp;
	cmp_print(env, str);
	ft_free(str);
}

int	check_exist(t_env *env, char *var)
{
	t_env	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = env;
	while (var[j] && var[j] != '=')
	{
		j++;
	}
	while (env)
	{
		if (ft_strncmp(env->name, var, j - 1) == 0)
			return (1);
		env = env->next;
	}
	env = tmp;
	return (0);
}
