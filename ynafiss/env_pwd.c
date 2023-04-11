/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:15:02 by ynafiss           #+#    #+#             */
/*   Updated: 2023/04/11 03:36:51 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void	ft_env(t_env *env)
// {
// 	while (env)
// 	{
// 		printf("%s\n", env->element);
// 		env = env->next;
// 	}
// }

void	ft_pwd(void)
{
	char	s[1000];
		printf("%s\n", getcwd(s, 1000));
}

// int main()
// {
// 	ft_pwd();
// }