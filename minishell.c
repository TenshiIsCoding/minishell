/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:30:23 by azaher            #+#    #+#             */
/*   Updated: 2023/03/17 15:23:49 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	main(void)
// {
// 	t_data	*vars;

// 	vars = malloc(sizeof(t_data));
// 	while (1)
// 	{
// 		vars->line = readline("minishell>");
// 		maskgen(vars);
// 		printf("%s\n", vars->mask);
// 		add_history(vars->line);
// 		free(vars->line);
// 	}
// }

/*≈
><|

00122222222210
ls >>>>>|||| p
[ls, >>>>>|||, p]

00122222333310
ls >>>>>|||| p
[ls, >>>>>, |||||, p]

<>| outside '' "" 2
\t\n\v 1
else 0

*/