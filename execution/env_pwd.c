/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:15:02 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/09 18:13:15 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(t_env *env, int ch)
{
	g_exit = 0;
	while (env)
	{
		ft_putstr_fd(env->name, 1);
		ft_putstr_fd(env->value, 1);
		write(1, "\n", 1);
		env = env->next;
	}
	if (ch == 0)
		exit(0);
}

void	ft_pwd(int ch)
{
	char	s[1000];

	g_exit = 0;
	printf("%s\n", getcwd(s, 1000));
	if (ch == 0)
		exit(0);
}

void	ft_exit(char *i)
{
	g_exit = i;
	printf("exit\n");
	if (!i)
		exit (0);
	exit(ft_atoi(i));
}
