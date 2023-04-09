/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:03:03 by ynafiss           #+#    #+#             */
/*   Updated: 2023/04/07 01:13:37 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

// int main(int ac, char **av, char **env)
// {
// 	char	*s =  "ff====";
// 	char	*y =  "aousse=";
// 	char	**r;
// 	int		i;
// 	int		j;
   
// 	i = 0;
// 	j = 0;
// 	(void)av;
// 	(void)ac;
// 	t_env	*enva;
// 	enva = ft_lstnew(env[i++]);
// 	while (env[i])
// 	{
// 		ft_lstadd_back(&enva, ft_lstnew(env[i]));
// 		i++;
// 	}
// 	ft_lstadd_back(&enva, NULL);
// 	printf ("--------------------------------------------------------\n");
// 	r = ft_export(enva, ft_lstsize(enva) - 1, s, 0);
// 	ft_lstadd_front(&enva, ft_lstnew(s));
// 	r = ft_export(enva, ft_lstsize(enva) - 1, y, 0);
// 	ft_lstadd_front(&enva, ft_lstnew(y));
// 	ft_env(enva);
// 	// exit (0);
// 	// i = 0;
// 	// while (r[i])
// 	// {
// 	// 	if (r[i][0])
// 	// 		ft_putstr_export("declare -x ", 1);
// 	// 	ft_putstr_export(r[i], 1);
// 	// 	if (r[i][0])
// 	// 		write(1, "\n", 1);
// 	// 	i++;
// 	// }
// }