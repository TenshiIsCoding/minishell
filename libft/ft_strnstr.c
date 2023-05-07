/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:35:25 by azaher            #+#    #+#             */
/*   Updated: 2022/10/25 17:58:35 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	else
	{
		while (haystack[i] != '\0' && i < len)
		{
			if (haystack[i] == needle[j])
			{
				while (haystack[i + j] == needle [j] && needle[j] != '\0')
					j++;
			}
			if (needle[j] == '\0' && len >= i + j)
				return ((char *)haystack + i);
			else
				j = 0;
			i++;
		}
	}
	return (0);
}
