/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:46:31 by ynafiss           #+#    #+#             */
/*   Updated: 2023/03/15 14:35:07 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdlib.h>

typedef struct t_env
{
    char    *element;
    struct t_env   *next;
}t_env;

int	ft_strcmp(const char *s1, const char *s2);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_lstadd_back(t_env **lst, t_env *new);
void	ft_lstadd_front(t_env **lst, t_env *new);
t_env	*ft_lstlast(t_env *lst);
t_env	*ft_lstnew(char *element);
int	ft_lstsize(t_env *lst);

#endif