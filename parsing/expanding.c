/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:31:36 by azaher            #+#    #+#             */
/*   Updated: 2023/03/31 02:11:43 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// [a'>$s'"$s"$s, >, $s, echo, >, '$s', >, a"$s"'$s', a]
// cases 1. split args
// case 2. don't expand in single quote
// case 3. ambigous if the array is larger than one
// [a'>$s'"s      t"s     t,  >,  ] => if ambiguous => [NULL]
// else
// []

// char **
// [ls, >, a, |, echo, >, o, p]
// =>
// char ***
// [ls, >, a] => NULL
// [echo, >, o, p]

