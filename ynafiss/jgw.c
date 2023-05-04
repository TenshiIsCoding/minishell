// int	export_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*ss1;
// 	unsigned char	*ss2;

// 	i = 0;
// 	ss1 = (unsigned char *)s1;
// 	ss2 = (unsigned char *)s2;
// 	if (n == 0)
// 	{
// 		return (0);
// 	}	
// 	while ((ss1[i] != '\0' || ss2[i] != '\0') && i < n && \
// 	(ss1[i] != '=' || ss2[i] != '=') && \
// 	(ss1[i] != '+' || ss2[i] != '+'))
// 	{
// 		if (ss1[i] != ss2[i] && (ss1[i] != '\0' || ss2[i] != '\0') && \
// 	(ss1[i] != '=' || ss2[i] != '=') && \
// 	(ss1[i] != '+' || ss2[i] != '+'))
// 		{
// 			return (ss1[i] - ss2[i]);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int	export_strcmp(const char *s1, const char *s2)
// {
// 	size_t			i;
// 	unsigned char	*ss1;
// 	unsigned char	*ss2;

// 	i = 0;
// 	ss1 = (unsigned char *)s1;
// 	ss2 = (unsigned char *)s2;
// 	while ((ss1[i] != '\0' || ss2[i] != '\0') && \
// 	(ss1[i] != '=' || ss2[i] != '=') && \
// 	(ss1[i] != '+' || ss2[i] != '+'))
// 	{
// 		if (ss1[i] != ss2[i] && (ss1[i] != '\0' || ss2[i] != '\0') && \
// 	(ss1[i] != '=' || ss2[i] != '=') && \
// 	(ss1[i] != '+' || ss2[i] != '+'))
// 		{
// 			return (ss1[i] - ss2[i]);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// 	else
// 	{
// 		if (var[i] == '=')
// 			i++;
// 		un = ft_substr(var, i, ft_strlen(var) - 1);
// 		while (*env != NULL && export_strcmp((*env)->name, un) != 0)
// 			*env = (*env)->next;
// 		new_val = ft_strjoin((*env)->value, un);
// 		update_value((*env), new_val);
// 	}