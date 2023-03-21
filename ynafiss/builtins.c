/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:03:03 by ynafiss           #+#    #+#             */
/*   Updated: 2023/03/21 16:36:47 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

// int main(int ac, char **av, char **env)
// {
// 	char	*s =  "hello";
// 	// char	*r =  "no";
// 	int		i;
// 	int		j;
// 	t_env	*enva;
// 	// t_env	*unset;

// 	i = 0;
// 	j = 0;
// 	(void)av;
// 	(void)ac;
// 	enva = ft_lstnew(env[i++]);
// 	while (env[i])
// 	{
// 		ft_lstadd_back(&enva, ft_lstnew(env[i]));
// 		i++;
// 	}
// 	// char *buf;
// 	ft_export(&enva, 37, s);
// 	// ft_export(&enva, 38, r);
// 	// ft_export(&enva, 37, s);
// 	// ft_export(&enva, 37, s);
// 	ft_unset(&enva, s);
// 	// ft_export(&unset, 37, s);
// 	// ft_unset(&enva, s);
// 	// ft_export(&enva, 37, "g");
// 	// // printing current working directory
// 	// buf = readline("\nMinishell>>");
// 	// add_history(buf);
// 	// if (ft_strcmp(buf, "cd") == 0)
// 	// 	ft_cd(av[2], env);
// 	// if (ft_strcmp(buf, "pwd") == 0)
// 	// 	ft_pwd();
// 	// printf("kyhb%%");
// 	// ft_cd("~", env);
// 	// ft_env(enva);
// 	// write (1, "\"", 1);
// 	// ft_export(enva, 36, "f");
// 	// ft_lstadd_front(&enva, ft_lstnew("f=\'''"));
// 	// ft_lstadd_front(&enva, ft_lstnew("r"));
// 	// printf("%s",get_env(env, "~"));
// 	// printf("\n%c\n", enva->element);
// }