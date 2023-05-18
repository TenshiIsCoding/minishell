/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:46:24 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/17 15:07:34 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*export_strdup(const char *s1)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = malloc (sizeof (char) * ft_strlen(s1) + 1);
	if (!s2)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		if (s1[i] == '+' || s1[i] == '=')
		{
			s2[i] = '=';
			i++;
			break ;
		}
		s2[i] = s1 [i];
		i++;
	}
	if (s2[i - 1] != '=')
	{
		s2[i] = '=';
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

void	creat_var(char *cmd, t_env **env)
{
	if (check_exist((*env), cmd) == 0)
		add_var(env, cmd);
	else
		over_add(env, cmd);
}
