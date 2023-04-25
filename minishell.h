/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:46:31 by ynafiss           #+#    #+#             */
/*   Updated: 2023/04/17 03:15:34 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef BUFFER_SIZE
#  define  BUFFER_SIZE	5
# endif

# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "queue/queue.h"
//              Execution Structs              //

typedef struct t_env
{
	char			*name;
	char			*value;
	struct t_env	*next;
}t_env;

typedef struct t_list
{
	int				content;
	struct t_list	*next;
}t_list;

typedef struct t_vars
{
	int	pi[2];
	int	fd;
	int	open;
}t_vars;

//              Parsing Structs              //

enum
{
	IN,
	OUT,
	APND,
	HERE,
	AMBIG
};

typedef struct t_file
{
	int		type;
	char	*filename;
}t_file;

typedef struct t_cmd {
	char	**args;
	t_file	**files;
}t_cmd;

typedef struct t_node
{
	t_cmd				*content;
	struct t_node		*next;
}t_node;

typedef struct t_data{
	int		cmdcount;
	t_node	*cmds;
	t_node	*ndtmp;
	t_env	*env;
	t_queue	commands;
	char	**splt;
	char	*line;
	char	*lineptr;
	char	*mask;
	int		dquote;
	int		squote;
	char	*temp;
	char	*ret;
	int		status;
	int		pipedex;
	char	*freeptr;
	char	*varname;
	char	*expenv;
	char	**spltargs;
	int		spltargdex;
	char	*argmask;
}t_data;

void	multipipe(t_queue *line, char **env, t_env **eenv);
t_env	*full_env(char **env);
void	first_cmd(t_cmd *cmd, int ch, t_env **eenv, char **env, t_vars *t);
char	*expo_substr(char const *s, unsigned int start, size_t len);
void	com_n(char *cmd);
int		export_strcmp(const char *s1, const char *s2);
int		open_in(t_file **file);
int		export_strncmp(const char *s1, const char *s2, size_t n);
void	cmp_print(t_env *env, char **str);
void	export_print(t_env *env, int limit);
int		check_exist(t_env *env, char *var);
char	*pipe_strjoin(char const *s1, char const *s2);
char	*get(char **env, char *cmd);
int		is_builtin(char **cmd);
void	exec_built(char **cmd, char **env, int ch, t_env **eenv);
void	one_cmd(t_cmd *cmd, char **env, int ch, t_env **eenv);
void	mid_cmd(t_vars *t, t_cmd *cmd, char **env, int ch, t_env **eenv);
void	last_cmd(int fd, t_cmd *cmd, char **env, int ch);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *str, int c, size_t n);
void	ft_putstr_export(char *name, char *value);
void	*ft_memchr(const void *s, int c, size_t n);
void	export(char **cmd, t_env **env);
void	ft_bzero(void *str, size_t n);
void	ft_unset(t_env **env, char *var);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	wait_child(int i, int *ch);
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
char	*get_next_line(int fd);
char	*ft_ft(int fd, char *str);
char	*ft_fr(char *str);
char	*ft_l1(char *s);
// void	ft_env(t_env *env);
void	ft_pwd(int ch);
void	ft_echo(char **print);
void	ft_cd(char *path, char **env);

//              Parsing prototypes Structs              //

void	maskgen(t_data *vars);
char	*maskgen_01(char *token, t_data *vars);
int		token_count(t_data *vars);
void	print_ret(char **ret);
char	**upgraded_split(t_data *vars);
void	ft_free(char **ret);
int		check_mix_meta(char *token);
int		check_quotes(char *token);
int		pipe_ends(char	*first_token, char *last_token);
int		double_pipe(char *token);
int		triple_rredirections(char *token);
int		triple_lredirections(char *token);
int		syntax_checker(char	**tokens);
void	pass_data(t_data *v, t_env *env);
int		parse_start(t_data *vars, t_env *env);
void	ft_lstback_add(t_node **lst, t_node *new);
t_node	*ft_lstlastnode(t_node *lst);
char	**rllc(char **tab, char *arg);
int		is_redir(char *token);
t_file	*create_file(char *filename, char *filetype);
t_file	**fill_files(t_queue *files);
t_cmd	*get_cmd(char **splt, t_data *v, t_env *env);
void	free_data(void *t);
char	*get_varname(char *token);
int		var_len(char *token);
char	*ft_free_strjoin(char *s1, char *s2);
char	*ft_strjoin_c(char *str, char c);
char	*get_envalue(char *name, t_env *env);
char	*expand_init(char *line, t_env *env, t_data *v);
char	*expand_argument(char *line, t_data *v, t_env *env);
char	*get_envalue(char *name, t_env *env);
void	remove_index(char *string, int index);
void	remove_quotes(char *token);
void	insert_file(t_queue flqueue, char **splt, t_env *env, int i);
void	insert_arg(char **splt, t_queue argqueue, int i);
int		check_varname(char *filename, t_env *env);
int		ambig_test(char *file, t_env *env, t_data *v);
char	**ambig_upgraded_split(char *token, char *mask, t_data *vars);
void	replace_quotes(char *varvalue);
int		is_splitable(char **varvalue);

#endif