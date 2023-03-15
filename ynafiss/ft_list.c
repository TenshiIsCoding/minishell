/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:31:23 by ynafiss           #+#    #+#             */
/*   Updated: 2023/03/15 14:32:06 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*lst1;

	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			lst1 = ft_lstlast(*lst);
			lst1->next = new;
		}
	}
}

void	ft_lstadd_front(t_env **lst, t_env *new)
{
	if (lst != NULL)
	{
		if (*lst != NULL)
			new->next = *lst;
		*lst = new;
	}
}

t_env	*ft_lstlast(t_env *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

t_env	*ft_lstnew(char *element)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->element = element;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_env *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
