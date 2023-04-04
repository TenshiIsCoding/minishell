/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:45:02 by ynafiss           #+#    #+#             */
/*   Updated: 2023/03/29 12:47:51 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_ft(int fd, char *str)
{
	char	*d;
	int		i;

	i = 1;
	d = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!d)
		return (NULL);
	while (!ft_strchr(str, '\n') && i != 0)
	{
		i = read(fd, d, BUFFER_SIZE);
		if (i == -1)
		{
			free(d);
			free (str);
			return (0);
		}
		d[i] = '\0';
		str = ft_strjoin(str, d);
		if (!str)
			return (NULL);
	}
	free(d);
	return (str);
}

char	*ft_fr(char *str)
{
	int		i;
	int		j;
	char	*d;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	i++;
	d = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!d)
	{
		free (str);
		return (NULL);
	}
	while (str[i] != '\0')
		d[j++] = str[i++];
	d[j] = '\0';
	free (str);
	return (d);
}

char	*ft_l1(char *s)
{
	int		i;
	int		j;
	char	*d;

	i = 0;
	j = 0;
	if (!ft_strlen(s))
		return (NULL);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		d = malloc(sizeof(char) * (i + 2));
	else
		d = malloc(sizeof(char) * (i + 1));
	if (!d)
		return (NULL);
	while (j <= i && s[j] != '\0')
	{
		d[j] = s[j];
		j++;
	}
	d[j] = '\0';
	return (d);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ptr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_ft(fd, str);
	if (str == NULL)
		return (NULL);
	ptr = ft_l1(str);
	str = ft_fr(str);
	return (ptr);
}

// #include <fcntl.h>

// int main(){
//     int fd;
//     fd = open("t.txt", O_RDWR | O_CREAT, 0777);
//     printf("%s\n",get_next_line(fd));
// 	printf("%s\n",get_next_line(fd));
// 	printf("%s\n",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// }