/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:04:55 by ynafiss           #+#    #+#             */
/*   Updated: 2022/10/30 13:49:14 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*b;
	unsigned char	*c;

	i = 0;
	if (dst == src)
		return (dst);
	b = (unsigned char *)dst;
	c = (unsigned char *)src;
	if (!b && !c)
		return (NULL);
	while (n > 0)
	{
		b[i] = c[i];
		i++;
		n--;
	}
	return (b);
}
