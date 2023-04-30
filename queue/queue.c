/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:59:26 by azaher            #+#    #+#             */
/*   Updated: 2023/04/29 11:42:00 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	queue_init(t_queue *queue)
{
	queue->head = NULL;
	queue->last = NULL;
	queue->len = 0;
}

t_queue_node	*queue_create_node(void	*data)
{
	t_queue_node	*new;

	new = malloc(sizeof(t_queue_node));
	new->ptr = data;
	new->next = NULL;
	return (new);
}

void	queue_insert(t_queue *queue, void *data)
{
	t_queue_node	*new;

	new = queue_create_node(data);
	if (queue->last == NULL)
	{
		queue->head = new;
		queue->last = new;
	}
	else
	{
		queue->last->next = new;
		queue->last = new;
	}
	queue->len++;
}

void	*queue_pop(t_queue *queue)
{
	t_queue_node	*tmp;
	void			*ptr;

	if (queue->head == NULL)
		return (NULL);
	tmp = queue->head;
	ptr = queue->head->ptr;
	queue->head = tmp->next;
	queue->len--;
	if (queue->head == NULL)
		queue->last = NULL;
	free(tmp);
	return (ptr);
}

void	queue_free(t_queue *queue, void (*f)(void *data))
{
	t_queue_node	*node;
	t_queue_node	*tmp;

	node = queue->head;
	while (node)
	{
		tmp = node->next;
		if (f)
			f(node->ptr);
		free(node);
		node = tmp;
	}
	queue->head = NULL;
	queue->last = NULL;
	queue->len = 0;
}
