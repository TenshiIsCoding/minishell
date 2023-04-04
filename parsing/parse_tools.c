/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 07:54:09 by azaher            #+#    #+#             */
/*   Updated: 2023/04/03 07:45:29 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstback_add(t_node **lst, t_node *new)
{
	t_node	*lst1;

	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			lst1 = ft_lstlastnode(*lst);
			lst1->next = new;
		}
	}
}

t_node	*ft_lstlastnode(t_node *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

// int	tablen(char **tab)
// {
// 	int	i;

// 	if (!tab)
// 		return (0);
// 	i = 0;
// 	printf("%s\n", tab[i]);
// 	while (tab[i])
// 	{
// 		i++;
// 	}
// 	return (i + 1);
// }

// char	**rllc(char **tab, char *arg)
// {
// 	char	**ret;
// 	int		tlen;
// 	int		i;

// 	ret = NULL;
// 	if (!tab[0] || !tab)
// 	{
// 		ret = ft_calloc(sizeof(char *) * 2, 2);
// 		ret[0] = ft_strdup(arg);
// 		ft_free(tab);
// 		return (tab);
// 	}
// 	tlen = tablen(tab);
// 	ret = malloc(sizeof(char *) * (tlen + 1));
// 	i = -1;
// 	while (tab[++i])
// 		ret[i] = ft_strdup(tab[i]);	
// 	ret[i] = ft_strdup(arg);
// 	ret[i + 1] = NULL;
// 	ft_free(tab);
// 	return(ret);
// }