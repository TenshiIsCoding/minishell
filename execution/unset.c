/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:18:45 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/15 16:05:43 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	first_one(t_env **env, char *name, t_env *tmp)
{
	if (*env != NULL && ft_strcmp((*env)->name, name) == 0)
	{
		tmp = *env;
		*env = (*env)->next;
		free(tmp->name);
		free(tmp->value);
		free(tmp);
		return ;
	}
}

int	check_unset(char *var)
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
	while (var[i] != '\0')
	{
		if ((ft_isalpha(var[i]) == 0 && ft_isdigit(var[i]) == 0 && \
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

int	while_unset(t_env **env, char **cmd)
{
	int	i;

	i = 1;
	while (cmd[i])
	{
		if (check_unset(cmd[i]) == 0)
			g_exit = ft_unset(env, cmd[i]);
		else
			g_data.g_exit = 1;
		i++;
	}
	return (g_data.g_exit);
}

int	len_equ(char *name)
{
	int	i;

	i = 0;
	while (name[i] != '\0' && name[i] != '=')
		i++;
	return (i);
}

int	ft_unset(t_env **env, char *name_p)
{
	t_env	*tmp;
	t_env	*pr;
	t_env	*cur;
	int		i;

	pr = NULL;
	cur = *env;
	i = len_equ(name_p);
	if (*env != NULL && ft_strncmp((*env)->name, name_p, i) == 0)
	{
		tmp = *env;
		*env = (*env)->next;
		(free(tmp->name), free(tmp->value), free(tmp));
		return (0);
	}
	while (cur != NULL && ft_strncmp(cur->name, name_p, i) != 0)
	{
		pr = cur;
		cur = cur->next;
	}
	if (cur == NULL)
		return (0);
	pr->next = cur->next;
	(free(cur->name), free(cur->value), free(cur));
	return (0);
}
