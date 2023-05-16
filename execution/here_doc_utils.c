/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:00:32 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/16 15:01:56 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	*full_tab(t_cmd *cmd, t_queue_node *node, t_tab *t, t_queue *line)
{
	int	*here;

	t->c = 0;
	here = calloc(line->len, 4);
	while (cmd && node)
	{
		t->i = 0;
		cmd = node->ptr;
		if (cmd)
		{
			while (cmd->files[t->i])
			{
				if (cmd->files[t->i]->type == HERE)
				{
					here[t->j] = t->c;
					t->j++;
					break ;
				}
				t->i++;
			}
		}
		t->c++;
		node = node->next;
	}
	return (here);
}

int	*where_here(t_cmd *cmd, t_queue *line, t_queue_node *node)
{
	t_tab	t;
	int		*here;

	t.j = 0;
	here = full_tab(cmd, node, &t, line);
	if (t.j == 0)
	{
		free(here);
		return (NULL);
	}
	return (here);
}

void	here_handel(int sig)
{
	(void)sig;
	g_data.g_exit = 44;
	exit(44);
}

void	here_signal(struct termios term)
{
	term.c_cc[VQUIT] = _POSIX_VDISABLE;
	term.c_lflag &= ~ECHOCTL;
	(tcsetattr(0, TCSANOW, &term), signal(SIGINT, here_handel));
}
