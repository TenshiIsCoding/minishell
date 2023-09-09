/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:04:38 by ynafiss           #+#    #+#             */
/*   Updated: 2023/05/16 12:04:01 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = malloc (sizeof (char) * ft_strlen(s1) + 1);
	if (!s2)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		s2[i] = s1 [i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
