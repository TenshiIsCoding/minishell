/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:24:17 by azaher            #+#    #+#             */
/*   Updated: 2022/10/26 14:03:53 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigits(int n)
{
	int			count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
			count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*asc;
	long long	nb;
	int			len;

	nb = n;
	len = ft_countdigits(n);
	asc = malloc((len + 1) * sizeof(char));
	if (!asc)
		return (0);
	asc[len] = '\0';
	len--;
	if (n == 0)
		asc[0] = '0';
	if (nb < 0)
	{
		asc[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		asc[len] = (nb % 10) + 48;
		nb = nb / 10;
		len--;
	}
	return (asc);
}
