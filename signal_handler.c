/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:23:25 by azaher            #+#    #+#             */
/*   Updated: 2023/05/17 13:48:33 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler(int signal)
{
	(void)signal;
	if (g_data.sigflag == 0)
	{	
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	handel_quit(int sig)
{
	ft_putstr_fd("^l'ndf \n", 2);
	(void)sig;
}

void	handle_signals(int i)
{
	if (i == 0)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, SIG_IGN);
	}
	else
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, handel_quit);
	}
}
