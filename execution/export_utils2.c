/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:13:24 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/15 09:08:34 by ynafiss          ###   ########.fr       */
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

int	export_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	if (!s1 || !s2)
		return (1);
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while ((ss1[i] != '\0' || ss2[i] != '\0') && \
	(ss2[i] != '=' || ss1[i] != '='))
	{
		if (ss1[i] != ss2[i] && (ss1[i] != '\0' || ss2[i] != '\0'))
		{
			return (ss1[i] - ss2[i]);
		}
		i++;
	}
	i--;
	return (ss1[i] - ss2[i]);
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
	while (var[j] != '\0' && var[j] != '=')
		j++;
	if (var[j] == '=')
		j++;
	str = ft_substr(var, 0, j);
	while (env)
	{
		if (export_strcmp(env->name, str) == 0)
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

char	*check_exist_1(t_env *env, char *var)
{
	t_env	*tmp;
	int		i;
	int		j;
	char	*str;
	char	*final;

	i = 0;
	j = 0;
	tmp = env;
	final = NULL;
	while (var[j] != '\0' && var[j] != '+')
		j++;
	if (var[j] != '+')
		return (NULL);
	str = ft_substr(var, 0, j);
	if (var[j] == '+')
		final = ft_strjoin(str, "=");
	while (env)
	{
		if (ft_strcmp(env->name, final) == 0)
		{
			(free(str));
			return (final);
		}
		env = env->next;
	}
	env = tmp;
	(free(str), free(final));
	return (NULL);
}
