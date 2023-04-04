/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:24:35 by ynafiss           #+#    #+#             */
/*   Updated: 2022/10/31 14:31:07 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*b;

	i = 0;
	if (!s || !f)
		return (NULL);
	b = malloc(ft_strlen(s) + 1);
	if (!b)
		return (NULL);
	while (s && s[i] != '\0')
	{
		b[i] = f(i, s[i]);
		i++;
	}
	b[i] = '\0';
	return (b);
}
