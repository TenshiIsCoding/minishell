/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:10:57 by azaher            #+#    #+#             */
/*   Updated: 2022/10/27 13:41:14 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		f;
	size_t		len;
	char		*strtrim;

	if (!s1 || !set)
		return (NULL);
	f = ft_strlen(s1);
	if (f == 0)
		return (ft_strdup(""));
	f = 0;
	while (ft_strchr((char *)set, ((char *)s1)[f]) && s1[f] != '\0')
		f++;
	len = ft_strlen(s1);
	while (ft_strrchr((char *)set, ((char *)s1)[len - 1]))
		len--;
	strtrim = ft_substr(s1, f, len - f);
	return (strtrim);
}
