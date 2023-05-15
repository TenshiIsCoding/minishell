/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:38:23 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/15 12:38:39 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cmd_handel(int sig)
{
	(void)sig;
	exit (130);
}

void	cmd_signal(struct termios term)
{
	term.c_cc[VQUIT] = _POSIX_VDISABLE;
	term.c_lflag &= ~ECHOCTL;
	(tcsetattr(0, TCSANOW, &term), signal(SIGINT, SIG_DFL));
}

void	dup_in(t_vars *t)
{
	(close(t->pi[0]), dup2(t->fd, 0));
	(close(t->fd), dup2(t->pi[1], 1));
	close (t->pi[1]);
}

void	handel_cmd_signal(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	cmd_signal(term);
}
