/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:14:19 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/14 17:53:06 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strlen_dub(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_print_echo(char **print, int j, int i)
{
	int	h;

	h = ft_strlen_dub(print);
	if (print[j][i] != '\0')
	{
		ft_putstr_fd(print[j], 1);
		if (print[j + 1])
			write(1, " ", 1);
	}
	while (print[j++])
	{
		ft_putstr_fd(print[j], 1);
		if (j + 1 <= h)
			write(1, " ", 1);
	}
}

int	ft_echo_norm(char **print, int j, int i)
{
	while (print[j][i])
	{
		if (print[j][0] != '-')
			break ;
		if (print[j][i] != 'n' && i != 0)
			break ;
		i++;
	}
	return (i);
}

void	norm_echo(char **print, int i, int j, int r)
{
	while (print[j])
	{
		i = ft_echo_norm(print, j, i);
		if (print[j][i] != '\0')
			break ;
		else
			r = 1;
		i = 0;
		j++;
	}
	ft_print_echo(print, j, i);
	if (r == 0)
		write(1, "\n", 1);
}

void	ft_echo(char **print, int ch)
{
	int	i;
	int	j;
	int	r;

	i = 0;
	r = 0;
	j = 1;
	if (print[1] && print[1][0] != '\0')
		norm_echo(print, i, j, r);
	else
		write(1, "\n", 1);
	if (ch == 0)
	{
		g_data.g_exit = 0;
		exit (0);
	}
	else
		g_data.g_exit = 0;
}
