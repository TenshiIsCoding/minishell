/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:01:20 by ynafiss           #+#    #+#             */
/*   Updated: 2023/04/16 02:26:13 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	sub = malloc (sizeof (char) * (len + 1));
	if (!sub)
		return (NULL);
	while (s && s[i] != '\0' && len != 0)
	{
		sub[i] = s[start + i];
		i++;
		len--;
	}
	sub[i] = '\0';
	return (sub);
}

char	*expo_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	sub = malloc (sizeof (char) * (len + 1));
	if (!sub)
		return (NULL);
	while (s && s[i] != '\0' && len != 0)
	{
		if (s[start + i] == '+')
			i++;
		sub[i] = s[start + i];
		i++;
		len--;
	}
	sub[i] = '\0';
	return (sub);
}
