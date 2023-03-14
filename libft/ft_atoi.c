/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:06:19 by ynafiss           #+#    #+#             */
/*   Updated: 2022/10/30 14:05:35 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbr(size_t nbr, const char *str, int i, int sign)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		if (sign == 1 && nbr > 9223372036854775807)
			return (-1);
		else if (sign == -1 && nbr > 9223372036854775807)
			return (0);
		i++;
	}
	return (nbr);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	size_t	nbr;

	nbr = 0;
	sign = 1;
	i = 0;
	if (str[i] == '\0')
		return ((int) NULL);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		sign = -1;
		i++;
	}
	nbr = ft_nbr(nbr, str, i, sign);
	return ((int)nbr * sign);
}
