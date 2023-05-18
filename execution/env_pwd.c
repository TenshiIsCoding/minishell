/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:15:02 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/17 14:40:32 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(t_env *env, int ch)
{
	g_data.g_exit = 0;
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
	char	*pwd;

	pwd = getcwd(s, 1000);
	g_data.g_exit = 0;
	if (pwd)
		printf("%s\n", pwd);
	else
		ft_putstr_fd(": path not found\n", 2);
	if (ch == 0)
		exit(0);
}

void	ft_exit(char *i)
{
	ft_putstr_fd("exit\n", 2);
	if (!i)
		exit (0);
	if (ft_isalpha(i[0]) == 1)
	{
		g_data.g_exit = 255;
		ft_putstr_fd("exit: fd: numeric argument required\n", 2);
		exit (g_data.g_exit);
	}
	else
	{
		g_data.g_exit = ft_atoi(i);
		exit(g_data.g_exit);
	}
}
