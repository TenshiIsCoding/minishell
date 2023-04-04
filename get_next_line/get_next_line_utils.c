/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:45:06 by ynafiss           #+#    #+#             */
/*   Updated: 2023/03/29 12:47:35 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strchr( char *s, int c)
{
	int			i;
	char		b;

	i = 0;
	if (!s)
		return (0);
	b = (char)c;
	if (b == '\0')
		return (s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == b)
		{
			return (&s[i]);
		}
		i++;
	}
	return (0);
}

size_t	ft_strlen( char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_full(char *b, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		b[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		b[i++] = s2[j++];
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*b;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = 0;
	}
	b = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!b)
		return (NULL);
	i = ft_full(b, s1, s2);
	b[i] = '\0';
	free (s1);
	return (b);
}
