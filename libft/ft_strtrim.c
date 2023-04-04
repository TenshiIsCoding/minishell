/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:21:46 by ynafiss           #+#    #+#             */
/*   Updated: 2022/10/31 10:37:09 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*trim;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
	{
		i++;
	}
	if (i == ft_strlen(s1))
		return (ft_strdup(""));
	while (j != 0 && ft_strrchr(set, s1[j]))
	{
		j--;
	}
	trim = ft_substr(s1, i, (j - i + 1));
	return (trim);
}
