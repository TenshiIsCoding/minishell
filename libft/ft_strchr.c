/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:04:44 by ynafiss           #+#    #+#             */
/*   Updated: 2022/10/30 12:08:14 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	char		b;

	i = 0;
	b = (char)c;
	if (b == '\0')
		return (((char *)s) + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == b)
		{
			return (((char *)s) + i);
		}
		i++;
	}
	return (NULL);
}
