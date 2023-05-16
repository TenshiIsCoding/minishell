/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:04:31 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/15 16:12:58 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

int	ft_cd(char *path, char **env, int ch)
{
	if (path != NULL && env[0] != NULL)
	{
		g_data.g_exit = 0;
		if (ft_strcmp(path, "~") == 0 || path == NULL)
			chdir(get_env(env, path));
		else if (ft_strcmp(path, "-") == 0)
			chdir(get_env(env, path));
		else if (chdir(path) == -1)
		{
			printf("cd: no such file or directory: %s\n", path);
			g_data.g_exit = 1;
		}
	}
	else if (env[0] != NULL)
		chdir(get_env(env, "~"));
	else
		g_data.g_exit = 1;
	if (ch == 0)
	{
		if (env)
			g_data.g_exit = 0;
		exit (0);
	}
	return (g_data.g_exit);
}
