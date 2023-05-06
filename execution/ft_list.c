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

t_env	*ft_lstlast(t_env *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

// t_here	*ft_herelast(t_here *lst)
// {
// 	if (lst != NULL)
// 	{
// 		while (lst->next != NULL)
// 			lst = lst->next;
// 	}
// 	return (lst);
// }

// void	ft_hereadd_back(t_here **lst, t_here *new)
// {
// 	t_here	*lst1;

// 	if (lst != NULL)
// 	{
// 		if (*lst != NULL)
// 		{
// 			lst1 = ft_herelast(*lst);
// 			lst1->next = new;
// 		}
// 	}
// }
// t_env	*ft_lstnew(char *element)
// {
// 	t_env	*new;

// 	new = (t_env *)malloc(sizeof(t_env));
// 	if (!new)
// 		return (NULL);
// 	new->element = element;
// 	new->next = NULL;
// 	return (new);
// }

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
