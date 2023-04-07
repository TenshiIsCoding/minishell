/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:14:19 by ynafiss           #+#    #+#             */
/*   Updated: 2023/04/06 02:58:36 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(char **print, char *flag)
{
	int	i;
	int	j;
	int k;

	i = 0;
	j = 1;
	while (flag[j])
	{
		if (flag[j] != 'n')
			break ;
		j++;
	}
	k = j;
	if (flag[j] != '\0')
	{
		j = 0;
		while (flag[j])
		{
			write(1, &flag[j], 1);
			j++;
		}
	}
	i = 0;
	j = 2;
	while (print[j])
	{
		while(print[j][i])
		{
			write(1, &print[i], 1);
			i++;
		}
		j++;
	}
	if (flag[k] != '\0' && (flag == NULL || ft_strcmp(flag, "-n") != 0))
		write(1, "\n", 1);
}

char	*get_env(char **env, char *src)
{
	int i;
	
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
void ft_cd(char *path, char **env)
{
	if (ft_strcmp(path, "~") == 0)
		chdir(get_env(env, path));
	else if (ft_strcmp(path, "-") == 0)
		chdir(get_env(env, path));
	else if (chdir(path) == -1)
		printf("cd: no such file or directory: %s", path);
}
