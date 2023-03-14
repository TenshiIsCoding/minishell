/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:25:21 by ynafiss           #+#    #+#             */
/*   Updated: 2022/10/30 11:22:50 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_n(int n)
{
	int		i;
	long	j;

	i = 1;
	j = n;
	if (j < 0)
	{
		j = j * -1;
	}
	while (j > 0)
	{
		j = j / 10;
		i++;
	}
	return (i);
}

static char	*ft_a(char *b, int j, int i)
{
	if (j == 0)
		b[i] = '0';
	if (j == -2147483648)
	{
		j = j / 10;
		j *= -1;
		b[i] = '8';
		i--;
	}
	while (j > 0)
	{
		b[i] = (j % 10) + '0';
		j = j / 10;
		i--;
	}
	return (b);
}

char	*ft_itoa(int n)
{
	char		*b;
	int			i;
	long		j;

	i = len_n(n);
	j = n;
	if (j <= 0)
	b = malloc (i + 1);
	else
	{
		b = malloc (i);
		i--;
	}
	if (!b)
		return (0);
	b[i] = '\0';
	i--;
	if (j < 0)
	{
		j *= -1;
		b[0] = '-';
	}
	b = ft_a(b, j, i);
	return (b);
}
