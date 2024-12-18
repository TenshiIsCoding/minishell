/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 06:37:53 by azaher            #+#    #+#             */
/*   Updated: 2023/05/07 22:26:34 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_envalue_ambig(char *name, t_env *env)
{
	t_env	*node;
	char	*ret;
	int		namelen;

	node = env;
	while (node)
	{
		namelen = ft_strlen(name);
		if (!ft_strncmp(node->name, name, namelen))
		{
			ret = ft_strdup(node->value);
			replace_quotes(ret);
			return (ret);
		}
		node = node->next;
	}
	return (ft_strdup(""));
}

char	*expand_ambig(char *line, t_env *env, t_data *v)
{
	int		i;
	char	*ret;

	i = 0;
	v->squote = 0;
	v->dquote = 0;
	ret = ft_strdup("");
	while (line[i])
	{
		if ((line[i] == '$' && !var_len(line + i + 1)) || line[i] != '$')
			ret = ft_strjoin_c(ret, line[i]);
		else if (line[i] == '$')
		{
			v->varname = get_varname(line + i + 1);
			v->expenv = get_envalue_ambig(v->varname, env);
			v->temp = ret;
			ret = ft_strjoin(ret, v->expenv);
			(free(v->varname), free(v->expenv), free(v->temp));
			i += var_len(line + i + 1) + 1;
			continue ;
		}
		i++;
	}
	free(line);
	return (ret);
}

void	replace_quotes(char *varvalue)
{
	int	i;

	i = 0;
	while (varvalue[i])
	{
		if (varvalue[i] == '\'' || varvalue[i] == '\"')
			varvalue[i] = 'a';
		i++;
	}
}

int	hardcases(char *filetoken, t_data *vars)
{
	char	**filesplt;
	char	*mask;

	mask = maskgen_01(filetoken, vars);
	filesplt = ambig_upgraded_split(filetoken, mask);
	remove_quotes(filetoken, vars);
	if (filetoken[0] == '\0')
	{
		(free(mask), ft_free(filesplt));
		return (1);
	}
	else if ((filetoken[0] == ' ' && filetoken[1] == '\0')
		|| is_splitable(filesplt))
	{
		(free(mask), ft_free(filesplt));
		return (1);
	}
	else
	{
		(free(mask), ft_free(filesplt));
		return (0);
	}
}

int	ambig_test(char *file, t_env *env, t_data *v)
{
	char	*filetoken;
	char	**filesplit;
	char	*newmask;

	filetoken = ft_strdup(file);
	filetoken = expand_argument(filetoken, v, env);
	newmask = maskgen_01(filetoken, v);
	filesplit = ambig_upgraded_split(filetoken, newmask);
	if (is_splitable(filesplit))
	{
		(free(filetoken), ft_free(filesplit), free(newmask));
		return (1);
	}
	else if (hardcases(filetoken, v))
	{
		(free(filetoken), ft_free(filesplit), free(newmask));
		return (1);
	}
	else
	{
		(free(filetoken), ft_free(filesplit), free(newmask));
		return (0);
	}
}
