/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:24:44 by azaher            #+#    #+#             */
/*   Updated: 2022/10/27 13:13:20 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static void	ft_free(char **ret, int p)
{
	int	i;

	i = 0;
	while (i <= p)
	{
		free(ret[i]);
		i++;
	}
	free (ret);
}

static void	ft_storewords(char **ret, char *s, char c)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	j = 0;
	p = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c)
			j = i;
		while (s[i] != c && s[i])
			i++;
		if (i != j)
		{
			ret[p] = ft_substr(s, j, i - j);
			if (!ret[p])
				ft_free(ret, p);
			p++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**ret;

	if (s == NULL)
		return (0);
	words = ft_countwords((char *)s, c);
	ret = malloc((words + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	ft_storewords(ret, (char *)s, c);
	ret[words] = NULL;
	return (ret);
}
