/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:00:33 by azaher            #+#    #+#             */
/*   Updated: 2022/10/27 13:40:14 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_mstrcat(char *s1, char *s2, char *dest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		dest[j] = s2[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		nlen;
	char	*dest;

	if (s1 == NULL || s2 == NULL)
		return (0);
	nlen = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc((nlen + 1) * (sizeof(char)));
	if (!dest)
		return (0);
	ft_mstrcat((char *)s1, (char *)s2, dest);
	return (dest);
}
