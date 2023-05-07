/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_ch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 00:31:35 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/07 13:17:24 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	wait_child(int i, int *ch)
{
	int	j;

	j = 0;
	waitpid(ch[i], NULL, 0);
	while (j < i)
	{
		waitpid(ch[j], NULL, 0);
		j++;
	}
}

void	close_all(void)
{
	int	j;

	j = 0;
	while (j <= 1024)
	{
		close (j);
		j++;
	}
}