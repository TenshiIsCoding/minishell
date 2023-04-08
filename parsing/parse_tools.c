/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 07:54:09 by azaher            #+#    #+#             */
/*   Updated: 2023/04/08 05:38:19 by azaher           ###   ########.fr       */
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
	if (filetype[0] == '>' && filetype[1] == '>')
		new_file->type = APND;
	if (filetype[0] == '<' && filetype[1] == '<')
		new_file->type = HERE;
	if (filetype[0] == '>' && filetype[1] == '\0')
		new_file->type = OUT;
	if (filetype[0] == '<' && filetype[1] == '\0')
		new_file->type = IN;
	return (new_file);
}

char	**fill_args(t_queue *args)
{
	int		i;
	char	**ret;

	i = 0;
	ret = malloc((args->len + 1) * sizeof(char *));
	ret[args->len] = NULL;
	while (args->len)
		ret[i++] = ft_strdup(queue_pop(args));
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

t_cmd	*get_cmd(char **splt, t_data *v)
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
			queue_insert(&flqueue, create_file(splt[i + 1], splt[i]));
			i += 2;
			continue ;
		}
		else
			queue_insert(&argqueue, splt[i]);
		i++;
	}
	v->pipedex = i;
	cmd->args = fill_args(&argqueue);
	cmd->files = fill_files(&flqueue);
	return (cmd);
}
