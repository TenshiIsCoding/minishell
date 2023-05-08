/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:18:45 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/08 15:02:24 by ynafiss          ###   ########.fr       */
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

void	ft_unset(t_env **env, char *name_p, int ch)
{
	t_env	*tmp;
	t_env	*pr;
	t_env	*cur;
	char	*name;

	pr = NULL;
	cur = *env;
	name = ft_strjoin(name_p, "=");
	if (*env != NULL && ft_strcmp((*env)->name, name) == 0)
	{
		tmp = *env;
		*env = (*env)->next;
		free(tmp->name);
		free(tmp->value);
		free(tmp);
		return ;
	}
	while (cur != NULL && ft_strcmp(cur->name, name) != 0)
	{
		pr = cur;
		cur = cur->next;
	}
	if (cur == NULL)
		return ;
	pr->next = cur->next;
	(free(cur->name), free(cur->value));
	free(cur);
	if (ch == 0)
		exit (0);
}
