/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:31:22 by ynafiss           #+#    #+#             */
/*   Updated: 2023/04/28 12:57:39 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

int	count_here(t_file **file)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file[i])
	{
		if (file[i]->type == HERE)
			j++;
		i++;
	}
	return (j);
}

void	here_doc(t_file **file, int *fd)
{
	int		i;
	int		j;
	int		pi[count_here(file)][2];
	char	*line;

	i = 0;
	j = 0;
	while (file[i])
	{
		if (file[i]->type == HERE)
		{
			pipe(pi[j]);
			while (line != NULL || ft_strcmp(file[i]->filename, line))
			{
				line = readline("> ");
				ft_putstr_fd(line, pi[j][1]);
			}
			j++;
		}
		i++;
	}
	*fd = pi[0];
}