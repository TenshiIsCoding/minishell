/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files_no_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:04:45 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/17 15:22:39 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	norm_open_out_no_cmd(t_file **file, int *fd_out, int i)
{
	if (file[i]->type == OUT || file[i]->type == APND)
	{
		if (file[i]->type == OUT)
			*fd_out = open (file[i]->filename, O_CREAT | O_TRUNC | \
		O_WRONLY | O_RDONLY, 0644);
		if (file[i]->type == APND)
			*fd_out = open (file[i]->filename, O_CREAT | O_APPEND | \
		O_WRONLY | O_RDONLY, 0644);
		if (*fd_out == -1)
		{
			write(2, "open filed: ", 12);
			(ft_putstr_fd(file[i]->filename, 2));
		}
		close (*fd_out);
	}
}

int	open_out_no_cmd(t_file **file)
{
	int	i;
	int	ret;
	int	fd_out;

	if (!file)
		return (0);
	i = 0;
	ret = 0;
	fd_out = -1;
	while (file[i])
	{
		if (file[i]->type == OUT || file[i]->type == APND)
			norm_open_out_no_cmd(file, &fd_out, i);
		i++;
	}
	return (ret);
}

int	norm_open_in_n(t_file **file, t_list *here, int *fd_in, int i)
{
	if (file[i]->filename && file[i]->type == AMBIG)
	{
		g_data.g_exit = 1;
		ft_putstr_fd(file[i]->filename, 2);
		write(2, ": ambiguous redirect\n", 21);
		return (1);
	}
	if (file[i]->filename && file[i]->type == IN)
	{
		*fd_in = open(file[i]->filename, O_RDONLY);
		if (*fd_in == -1)
		{
			write(2, "no such file or directory: ", 27);
			ft_putstr_fd(file[i]->filename, 2);
			(write(2, "\n", 1));
			return (1);
		}
		close (*fd_in);
	}
	if (file[i]->type == HERE)
		*fd_in = here->content;
	return (0);
}

int	open_in_no_cmd(t_file **file, t_list *here)
{
	int	fd_in;
	int	i;

	fd_in = -1;
	i = 0;
	if (!file)
		return (0);
	while (file[i])
	{
		if (norm_open_in_n(file, here, &fd_in, i) == 1)
			return (1);
		i++;
	}
	(fd_in != -1) && close (fd_in);
	return (2);
}
