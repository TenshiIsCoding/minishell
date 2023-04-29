/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:58:30 by azaher            #+#    #+#             */
/*   Updated: 2023/04/29 11:26:24 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct t_queue_node
{
	void				*ptr;
	struct t_queue_node	*next;	
}	t_queue_node;

typedef struct t_queue
{
	t_queue_node	*head;
	t_queue_node	*last;
	int				len;
}	t_queue;

void			queue_init(t_queue *queue);
t_queue_node	*queue_create_node(void	*data);
void			queue_insert(t_queue *queue, void *data);
void			*queue_pop(t_queue *queue);
void			queue_free(t_queue *queue, void (*f)(void *data));

#endif
