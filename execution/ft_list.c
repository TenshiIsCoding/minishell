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

#include "../minishell.h"

t_list	*ft_lstlast_nor(t_list *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back_nor(t_list **lst, t_list *new)
{
	t_list	*lst1;

	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			lst1 = ft_lstlast_nor(*lst);
			lst1->next = new;
		}
	}
}

t_list	*ft_lstnew_nor(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

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
