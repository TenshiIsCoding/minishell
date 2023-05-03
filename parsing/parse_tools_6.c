/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools_6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:36:39 by azaher            #+#    #+#             */
/*   Updated: 2023/05/01 15:36:55 by azaher           ###   ########.fr       */
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

t_file	*new_file(char *filename, char *filetype, int inquotes)
{
	t_file	*new_file;

	new_file = malloc(sizeof(t_file));
	new_file->filename = ft_strdup(filename);
	new_file->inqt = 0;
	if (filetype[0] == '!')
		new_file->type = AMBIG;
	else if (filetype[0] == '>' && filetype[1] == '>')
		new_file->type = APND;
	if (filetype[0] == '<' && filetype[1] == '<')
	{
		new_file->type = HERE;
		if (inquotes)
			new_file->inqt = 1;
	}
	else if (filetype[0] == '>' && filetype[1] == '\0')
		new_file->type = OUT;
	else if (filetype[0] == '<' && filetype[1] == '\0')
		new_file->type = IN;
	return (new_file);
}
