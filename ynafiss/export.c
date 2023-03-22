/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:12:54 by ynafiss           #+#    #+#             */
/*   Updated: 2023/03/22 18:08:07 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_putstr_export(char *s, int fd)
{
	int	i;
	int	co;

	i = 0;
	co = 0;
	if (!s)
		return ;
	while (s[i])
	{
		if (co == 1 && s[i] == '\'' && s[i - 1] != '=')
			write(fd, &s[i], 1);
		if ( s[i] != '\'')
			write(fd, &s[i], 1);
		if (s[i] == '=')
		{
			write(1, "\"", 1);
			co = 1;
		}
		i++;
	}
	if (co == 1)
		write(1, "\"", 1);
	
}

char **ft_export(t_env *env, int limit, char *add, int unst)
{
	char	**str;
	char	**new_env;
	int i = 0;
	int j = 0;
	int size = ft_lstsize(env);
	char	*alpha;

	// if (add)
	// 	ft_lstadd_front(&env, ft_lstnew(add));
	str = (char **)malloc(sizeof (char *) * (ft_lstsize((env)) + 1));
	while (env)
	{
		str[i] = (env)->element;
		(env) = (env)->next;
		i++;
	}
	str[i] = NULL;
	i = 0;
	while (limit >= i)
	{
		j = 0;
		while (limit >= j)
		{
			if(strcmp(str[j], str[j + 1]) > 0)
			{
				alpha = str[j];
				str[j] = str[j + 1];
				str[j + 1] = alpha;;
			}
			j++;
		}
		i++;
	}
	if (unst == 1)
	{
		new_env = malloc(sizeof(char *) * (ft_lstsize(env) + 1));
		new_env = ft_unset(str, add, size);
		new_env[i] = NULL;
		return (new_env);
	}
	return (str);
}

