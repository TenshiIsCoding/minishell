/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 07:54:09 by azaher            #+#    #+#             */
/*   Updated: 2023/04/29 10:11:05 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_redir(char *token)
{
	if (token[0] == '<' || token[0] == '>')
		return (1);
	else
		return (0);
}

t_file	*create_file(char *filename, char *filetype)
{
	t_file	*new_file;

	new_file = malloc(sizeof(t_file));
	new_file->filename = ft_strdup(filename);
	if (filetype[0] == '!')
		new_file->type = AMBIG;
	else if (filetype[0] == '>' && filetype[1] == '>')
		new_file->type = APND;
	if (filetype[0] == '<' && filetype[1] == '<')
		new_file->type = HERE;
	else if (filetype[0] == '>' && filetype[1] == '\0')
		new_file->type = OUT;
	else if (filetype[0] == '<' && filetype[1] == '\0')
		new_file->type = IN;
	return (new_file);
}

char	**fill_args(t_queue *args)
{
	int		i;
	char	**ret;
	// char	*freeptr;
	char	*ptr;

	i = 0;
	ptr = args->head->ptr;
	ret = malloc((args->len + 1) * sizeof(char *));
	ret[args->len] = NULL;
	while (args->len)
	{
		// freeptr = ptr;
		ret[i++] = ft_strdup(queue_pop(args));
		// free(freeptr);
	}
	return (ret);
}

t_file	**fill_files(t_queue *files)
{
	int		i;
	t_file	**ret;

	i = 0;
	ret = malloc((files->len + 1) * sizeof(t_file *));
	ret[files->len] = NULL;
	while (files->len)
		ret[i++] = queue_pop(files);
	return (ret);
}

t_cmd	*get_cmd(char **splt, t_data *v, t_env *env)
{
	int		i;
	t_queue	argqueue;
	t_queue	flqueue;
	t_cmd	*cmd;

	queue_init(&argqueue);
	queue_init(&flqueue);
	i = v->pipedex;
	cmd = malloc (sizeof(t_cmd));
	while (splt[i] && splt[i][0] != '|')
	{
		if (is_redir(splt[i]))
		{
			if (ambig_test(splt[i + 1], env, v))
			{
				queue_insert(&flqueue, create_file(splt[i + 1], "!"));
			}
			else
			{
				splt[i + 1] = expand_argument(splt[i + 1], v, env);
				remove_quotes(splt[i + 1]);
				printf("splt[i] = (%s)\n", splt[i + 1]);
				queue_insert(&flqueue, create_file(splt[i + 1], splt[i]));
			}
			i += 2;
			continue ;
		}
		else
		{
			splt[i] = expand_argument(splt[i], v, env);
			v->argmask = maskgen_01(splt[i], v);
			v->spltargs = ambig_upgraded_split(splt[i], v->argmask);
			v->argdex = 0;
			while (v->spltargs[v->argdex])
			{
				remove_quotes(v->spltargs[v->argdex]);
				queue_insert(&argqueue, ft_strdup(v->spltargs[v->argdex++]));
			}
			(free(v->argmask), ft_free(v->spltargs));
		}
		i++;
	}
	v->pipedex = i;
	cmd->args = fill_args(&argqueue);
	cmd->files = fill_files(&flqueue);
	return (cmd);
}
