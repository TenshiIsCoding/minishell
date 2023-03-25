/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:30:23 by azaher            #+#    #+#             */
/*   Updated: 2023/03/23 13:38:51 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	main(void)
// {
// 	t_data	*vars;
// 	char	**ret;

// 	vars = malloc(sizeof(t_data));
// 	while (1)
// 	{
// 		vars->line = readline("minishell>");
// 		ret = upgraded_split(vars);
// 		printf("%s\n%s\n", ret[0], ret[1]);
// 		add_history(vars->line);
// 		free(vars->line);
// 	}
// }

/*≈


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