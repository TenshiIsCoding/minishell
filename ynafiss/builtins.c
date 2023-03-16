/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:03:03 by ynafiss           #+#    #+#             */
/*   Updated: 2023/03/15 16:40:07 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <readline/history.h>
#include <readline/readline.h>
#include "minishell.h"


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
	else if (ft_strcmp(src, "~") == 0)
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

void	ft_pwd(void)
{
	char	s[1000];
		printf("%s\n", getcwd(s, 1000));
}

void	ft_echo(char *print, char *flag)
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
	while (print[i])
	{
		write(1, &print[i], 1);
		i++;
	}
	if (flag[k] != '\0' && (flag == NULL || ft_strcmp(flag, "-n") != 0))
		write(1, "\n", 1);
}

void	ft_env(t_env *env)
{
	while (env)
	{
		printf("%s\n", env->element);
		env = env->next;
	}
}

void ft_export(t_env *env)
{
	t_env *tmp;
	t_env *swap;
	int i = 0;
	int j = 1;
	char	*alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	tmp = env;
	while (alpha[i])
	{
		while (env)
		{
			if(alpha[i] == env->element[0])
				swap->element = env->element;
			env = env->next;
			swap = swap->next;
		}
		env = tmp;
		i++;
	}
	while (alpha[i])
	{
		while (alpha[i] == swap->element[0])
		{
			if (ft_isalpha(swap->element[j]) && swap->element[j] < swap->next->element[j])
			{
				printf("declare -x %s", swap->element);
				swap = swap->next;
			}
			else if (swap->element[j] == swap->next->element[j])
				j++;
				
		}
		i++;
	}
	// while (env)
	// {
	// 	printf("declare -x %s", env->element);
	// 	env = env->next;
	// }
}

int main(int ac, char **av, char **env)
{
	char	s[100];
	int		i;
	int		j;
	t_env	*enva;

	i = 0;
	j = 0;
	enva = ft_lstnew(env[i++]);
	while (env[i])
	{
		ft_lstadd_back(&enva, ft_lstnew(env[i]));
		i++;
	}
	// char *buf;

	// // printing current working directory
	// buf = readline("\nMinishell>>");
	// add_history(buf);
	// if (ft_strcmp(buf, "cd") == 0)
	// 	ft_cd(av[2], env);
	// if (ft_strcmp(buf, "pwd") == 0)
	// 	ft_pwd();
	// printf("kyhb%%");
	// ft_cd("~", env);
	// ft_env(enva);
	ft_export(enva);
	// printf("\n%c\n", enva->element);
}