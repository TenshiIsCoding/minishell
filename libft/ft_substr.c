/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:53:12 by azaher            #+#    #+#             */
/*   Updated: 2023/05/16 11:23:01 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	if (ft_strlen(s) < start || s == NULL)
		return (ft_calloc(1, 1));
	if (len >= SIZE_MAX || len + start > ft_strlen(s))
		dest = ft_calloc(ft_strlen(&s[start]) + 1, sizeof(char));
	else
		dest = ft_calloc(len + 1, sizeof(char));
	if (dest == 0)
		return (0);
	while (i < len && start + i < ft_strlen(s))
	{
		dest[i] = s[start + i];
		i++;
	}
	return (dest);
}
