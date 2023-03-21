/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:18:45 by ynafiss           #+#    #+#             */
/*   Updated: 2023/03/21 15:23:11 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unset(t_env **env, char *name)
{
	t_env	*pre;
	t_env	*cur;

	cur = *env;
	pre = NULL;
	while (cur != NULL && ft_strncmp(cur->element, name, ft_strlen(name) - 1) != 0)
	{
		pre = cur;
		cur = cur->next;
	}
	if (pre == NULL)
		*env = cur->next;
	else
		pre->next = cur->next;
	free (cur);

	// if ((*env)->next->next != NULL)
	// {
	// 	(*env)->next = (*env)->next->next;
	// }
	// else
	// 	(*env)->next = NULL;
	
}