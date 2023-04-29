/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:15:02 by ynafiss           #+#    #+#             */
/*   Updated: 2023/04/29 11:46:59 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(t_env *env)
{
	while (env)
	{
		ft_putstr_fd(env->name, 1);
		ft_putstr_fd(env->value, 1);
		write(1, "\n", 1);
		env = env->next;
	}
}

void	ft_pwd(int ch)
{
	char	s[1000];

	printf("%s\n", getcwd(s, 1000));
	if (ch == 0)
		exit(0);
}

void	ft_exit(char *i)
{
	exit(ft_atoi(i));
}
