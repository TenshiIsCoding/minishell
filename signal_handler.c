/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:23:25 by azaher            #+#    #+#             */
/*   Updated: 2023/05/14 17:06:36 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler(int signal)
{
	(void)signal;
	g_exit = 1;
	// dprintf(2,"IM IN!!!!!!!!!![%d]\n", getpid());
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	// rl_redisplay();
}

void	handle_signals(void)
{
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
}
