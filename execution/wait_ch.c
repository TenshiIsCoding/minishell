/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_ch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 00:31:35 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/10 17:44:51 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	wait_child(int i, int *ch)
{
	int	j;
	int	status;

	j = 0;
	waitpid(ch[i], &status, 0);
	while (j < i)
	{
		waitpid(ch[j], NULL, 0);
		j++;
	}
	if (WIFEXITED(status))
		g_exit = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_exit = WTERMSIG(status) + 128;
}

void	close_all(void)
{
	int	j;

	j = 3;
	while (j <= 1024)
	{
		close (j);
		j++;
	}
}
