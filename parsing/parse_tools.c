/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 07:54:09 by azaher            #+#    #+#             */
/*   Updated: 2023/05/09 21:06:00 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**fill_args(t_queue *args)
{
	int		i;
	char	**ret;

	i = 0;
	ret = malloc((args->len + 1) * sizeof(char *));
	ret[args->len] = NULL;
	while (args->len)
		ret[i++] = queue_pop(args);
	return (ret);
}

/*			fills up files qith queue_pop function			*/

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

/*			Handles strings identified as files					*/

void	handle_files(t_data *v, char **splt, t_env *env, int i)
{
	if (ambig_test(splt[i + 1], env, v))
		queue_insert(&v->flqueue, new_file(splt[i + 1], "!", 0));
	else
	{
		splt[i + 1] = expand_argument(splt[i + 1], v, env);
		v->q = remove_quotes(splt[i + 1], v);
		queue_insert(&v->flqueue, new_file(splt[i + 1], splt[i], v->q));
	}
}

/*			Handles strings identified as arguments					*/

void	handle_args(t_data *v, char **splt, t_env *env, int i)
{
	splt[i] = expand_argument(splt[i], v, env);
	v->argmask = maskgen_01(splt[i], v);
	v->spltargs = ambig_upgraded_split(splt[i], v->argmask);
	v->argdex = 0;
	while (v->spltargs[v->argdex])
	{
		remove_quotes(v->spltargs[v->argdex], v);
		queue_insert(&v->argqueue, ft_strdup(v->spltargs[v->argdex++]));
	}
	(free(v->argmask), ft_free(v->spltargs));
}

/*		Fetches arguments and files from the split char**			*/

t_cmd	*get_cmd(char **splt, t_data *v, t_env *env)
{
	int		i;
	t_cmd	*cmd;

	queue_init(&v->argqueue);
	queue_init(&v->flqueue);
	i = v->pipedex;
	cmd = malloc (sizeof(t_cmd));
	while (splt[i] && splt[i][0] != '|')
	{
		if (is_redir(splt[i]))
		{
			handle_files(v, splt, env, i);
			i += 2;
			continue ;
		}
		else
			handle_args(v, splt, env, i);
		i++;
	}
	v->pipedex = i;
	cmd->args = fill_args(&v->argqueue);
	cmd->files = fill_files(&v->flqueue);
	return (cmd);
}
