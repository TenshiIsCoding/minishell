/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:11:01 by azaher            #+#    #+#             */
/*   Updated: 2022/10/27 12:51:34 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	rdst;
	size_t	rsrc;
	size_t	i;

	i = 0;
	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	rdst = ft_strlen(dst);
	rsrc = ft_strlen(src);
	if (dstsize == 0 || dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	while (i < dstsize - rdst - 1 && src[i] != '\0')
	{
		dst[rdst + i] = src[i];
		i++;
	}
	dst[rdst + i] = '\0';
	return (rdst + rsrc);
}
