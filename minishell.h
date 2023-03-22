/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:46:31 by ynafiss           #+#    #+#             */
/*   Updated: 2023/03/22 18:17:36 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>

//              Execution Structs              //

typedef struct t_env
{
	char			*element;
	struct t_env	*next;
}t_env;

typedef struct t_list
{
	int				content;
	struct t_list	*next;
}t_list;

//              Parsing Structs              //

typedef struct t_data{
	char	*line;
	char	*mask;
	int		dquote;
	int		squote;
}t_data;

void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *str, int c, size_t n);
void	ft_putstr_export(char *s, int fd);
void	*ft_memchr(const void *s, int c, size_t n);
char	**ft_export(t_env *env, int limit, char *add, int unst);
void	ft_bzero(void *str, size_t n);
char	**ft_unset(char **env, char *name, int size);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isalpha(int c);
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_atoi(const char *str);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str);
char	*ft_itoa(int n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *stack, const char *need, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_lstadd_back(t_env **lst, t_env *new);
void	ft_lstadd_front(t_env **lst, t_env *new);
t_env	*ft_lstlast(t_env *lst);
t_env	*ft_lstnew(char *element);
int		ft_lstsize(t_env *lst);

//              Parsing prototypes Structs              //

void	maskgen(t_data *vars);
int		token_count(t_data *vars);
char	**upgraded_split(t_data *vars);

#endif