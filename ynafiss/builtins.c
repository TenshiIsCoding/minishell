/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:03:03 by ynafiss           #+#    #+#             */
/*   Updated: 2023/03/22 18:13:31 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

// int main(int ac, char **av, char **env)
// {
// 	char	*s =  "COLORTERM";
// 	char	**r;
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
// 	ft_lstadd_back(&enva, NULL);
// 	// char *buf;
// 	// r = ft_export(enva, ft_lstsize(enva) - 1, s, 0);
// 	// 	i = 0;
// 	// while (r[i])
// 	// {
// 	// 	if (r[i][0])
// 	// 		ft_putstr_export("declare -x ", 1);
// 	// 	ft_putstr_export(r[i], 1);
// 	// 	if (r[i][0])
// 	// 		write(1, "\n", 1);
// 	// 	i++;
// 	// }
// 	printf ("--------------------------------------------------------\n");
// 	r = ft_export(enva, ft_lstsize(enva) - 1, s, 1);
// 	printf("--%d--\n", ft_lstsize(enva));
// 	// exit (0);
// 	i = 0;
// 	while (r[i])
// 	{
// 		if (r[i][0])
// 			ft_putstr_export("declare -x ", 1);
// 		ft_putstr_export(r[i], 1);
// 		if (r[i][0])
// 			write(1, "\n", 1);
// 		i++;
// 	}
// 	// ft_export(&enva, 38, r);
// 	// ft_export(&enva, 37, s);
// 	// ft_export(&enva, 37, s);
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