/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:38:23 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/17 14:43:30 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	dup_in(t_vars *t)
{
	(close(t->pi[0]), dup2(t->fd_in, 0));
	(close(t->fd_in), dup2(t->pi[1], 1));
	close (t->pi[1]);
}

// void	handel_quit(int sig)
// {
// 	ft_putstr_fd("^l'ndf \n", 2);
// 	(void)sig;
// }

// void	handel_cmd_signal(void)
// {
// 	signal(SIGINT, SIG_DFL);
// 	signal(SIGQUIT, handel_quit);
// }
