/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:35:25 by azaher            #+#    #+#             */
/*   Updated: 2022/10/25 15:07:16 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!s2)
		return (0);
	if (s1 == 0)
		return (0);
	while (s1[i])
	{
		s2[i] = s1 [i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
