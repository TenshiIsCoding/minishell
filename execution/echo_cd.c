/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:14:19 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/06 18:07:25 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(char **print)
{
	int	i;
	int	j;
	int	r;
	int	h;

	i = 0;
	r = 0;
	j = 1;
	h = 0;
	if (print[1])
	{
		while (print[h])
			h++;
		while (print[j])
		{
			while (print[j][i])
			{
				if (print[j][0] != '-')
					break ;
				if (print[j][i] != 'n' && i != 0)
					break ;
				i++;
			}
			if (print[j][i] != '\0')
			{
				break ;
				h = 1;
			}
			else
				r = 1;
			i = 0;
			j++;
		}
		if (print[j][i] != '\0')
		{
			ft_putstr_fd(print[j], 1);
			if (print[j + 1])
				write(1, " ", 1);
		}
		while (print[j++])
		{
			ft_putstr_fd(print[j], 1);
			if (j + 1 <= h)
				write(1, " ", 1);
		}
		if (r == 0)
			write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
}

char	*get_env(char **env, char *src)
{
	int	i;

	i = 0;
	if (ft_strcmp(src, "~") == 0)
	{
		while (ft_strncmp(env[i], "HOME=", 5))
			i++;
		if (ft_strncmp(env[i], "HOME=", 5) == 0)
			return (env[i] + 5);
		else
			exit (0);
	}
	else if (ft_strcmp(src, "-") == 0)
	{
		while (ft_strncmp(env[i], "OLDPWD=", 7))
			i++;
		if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
			return (env[i] + 7);
		else
			exit (0);
	}
	return ("null");
}

void	ft_cd(char *path, char **env)
{
	if (path != NULL)
	{
		if (ft_strcmp(path, "~") == 0)
			chdir(get_env(env, path));
		else if (ft_strcmp(path, "-") == 0)
			chdir(get_env(env, path));
		else if (chdir(path) == -1)
			printf("cd: no such file or directory: %s", path);
	}
}
