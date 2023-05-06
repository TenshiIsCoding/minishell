/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:24:40 by azaher            #+#    #+#             */
/*   Updated: 2022/10/24 14:54:58 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*d;

	i = 0;
	d = b;
	while (len != 0)
	{
		d[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (b);
}
