/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 06:37:53 by azaher            #+#    #+#             */
/*   Updated: 2023/04/16 09:38:02 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_splitable(char *varvalue)
{
	int		size;
	char	**split;

	size = 0;
	split = ft_split(varvalue, ' ');
	while (split[size])
	{
		size++;
	}
	if (size > 1)
	{
		ft_free(split);
		return (1);
	}
	else
	{
		ft_free(split);
		return (0);
	}
}

int	ambig_test(char *file, t_env *env)
{
	char	*varname;
	char	*varvalue;
	int		i;

	i = 0;
	while (file[i])
	{
		if (file[i] == '$')
		{
			varname = get_varname(file + i + 1);
			varvalue = get_envalue(varname, env);
			if (!ft_strlen(varvalue))
				return (1);
			if (is_splitable(varvalue))
				return (1);
		}
		i++;
	}
	return (0);
}

char	*expand_argument(char *line, t_data *v, t_env *env)
{
	int		i;
	char	*ret;

	i = 0;
	v->squote = 0;
	v->dquote = 0;
	ret = ft_strdup("");
	while (line[i])
	{
		if (line[i] == '\'' && !v->dquote)
			v->squote = !v->squote;
		else if (line[i] == '\"' && !v->squote)
			v->dquote = !v->dquote;
		else if (line[i] == '$' && !v->squote)
		{
			v->varname = get_varname(line + i + 1);
			v->expenv = get_envalue(v->varname, env);
			v->freeptr = ret;
			ret = ft_strjoin(ret, v->expenv);
			(free(v->varname), free(v->expenv), free(v->freeptr));
			i += var_len(line + i + 1) + 1;
			continue ;
		}
		else
			ret = ft_strjoin_c(ret, line[i]);
		i++;
	}
	free(line);
	return (ret);
}

// void	insert_file(t_queue flqueue, char **splt, t_env *env, int i)
// {
// 	if (ambig_test(splt[i + 1], env))
// 		queue_insert(&flqueue, create_file(splt[i + 1], "!"));
// 	else
// 	{
// 		remove_quotes(splt[i]);
// 		queue_insert(&flqueue, create_file(splt[i + 1], splt[i]));
// 	}
// }

// void	insert_arg(char **splt, t_queue argqueue, int i)
// {
// 	remove_quotes(splt[i]);
// 	queue_insert(&argqueue, splt[i]);
// }
