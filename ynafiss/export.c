/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:12:54 by ynafiss           #+#    #+#             */
/*   Updated: 2023/03/20 13:29:07 by ynafiss          ###   ########.fr       */
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

void ft_export(t_env **env, int limit, char *add)
{
	char	**str;
	int i = 0;
	int j = 0;
	char	*alpha;

	if (add)
	{
		ft_lstadd_front(env, ft_lstnew(add));
    }
	str = (char **)malloc(sizeof (char *) * ft_lstsize((*env)));
	while (*env)
	{
		str[i] = (*env)->element;
		(*env) = (*env)->next;
		i++;
	}
	i = 0;
	while (limit >= i)
	{
		j = 0;
		while (limit - 2 >= j)
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
	j = 0;
	while (j <= limit)
	{
		ft_putstr_export("declare -x ", 1);
		ft_putstr_export(str[j], 1);
		write(1, "\n", 1);
		// free(str[j]);
		j++;
	}
	j = 0;
	// while (str != NULL && str[j] != NULL)
	// {
	// 	free(str[j]);
	// 	j++;
	// }
	// free (str);
	// free (str);
}

