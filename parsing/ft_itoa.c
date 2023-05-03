/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:41:55 by azaher            #+#    #+#             */
/*   Updated: 2023/05/03 17:49:19 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_digits(int nbr)
{
	int	digit;

	digit = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		digit++;
	}
	while (nbr > 0)
	{
		digit++;
		nbr /= 10;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digi_count;
	int		nb;

	str = NULL;
	nb = n;
	digi_count = count_digits(nb);
	if (n < 0)
		nb *= -1;
	str = malloc((digi_count + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	str[digi_count] = '\0';
	while (digi_count > 0)
	{
		str[digi_count - 1] = (nb % 10) + 48;
		nb /= 10;
		digi_count--;
	}
	if (n < 0)
		str[digi_count] = '-';
	return (str);
}
