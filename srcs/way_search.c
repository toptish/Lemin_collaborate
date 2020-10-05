/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 12:25:08 by ophuong           #+#    #+#             */
/*   Updated: 2020/10/03 10:06:14 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void		f_enque(t_que *queue, t_node *y)
{
	if (queue->back == SIZE - 1)
		return ;
	else
	{
		if (queue->front == -1)
			queue->front = 0;
		queue->back++;
		queue->units[queue->back] = y;
	}
}

static t_node	*f_deque(t_que *queue)
{
	t_node *unit;

	if (queue->back == -1)
		unit = NULL;
	else
	{
		unit = queue->units[queue->front];
		queue->front++;
		if (queue->front > queue->back)
		{
			queue->front = -1;
			queue->back = -1;
		}
	}
	return (unit);
}

static t_way	*f_reway(t_lem *lemin)
{
	t_way	*way;
	int		final;

	if (!(way = malloc(sizeof(t_way))))
		return (NULL);
	final = lemin->final;
	way->len = 0;
	way->node[way->len++] = lemin->node[final];
	while (lemin->parent[final] != -1)
	{
		final = lemin->parent[final];
		way->node[way->len++] = lemin->node[final];
	}
	way->node[way->len] = NULL;
	return (way);
}

static void		f_addque(t_lem *lemin, t_node *src, t_node *dst)
{
	t_node **node;

	node = lemin->node;
	if (!node[src->id]->in_way)
	{
		if (node[dst->id]->in_way && !node[dst->id]->start)
		{
			f_enque(lemin->queue, node[node[dst->id]->prev]);
			lemin->links->marked[node[dst->id]->prev] = 1;
			lemin->parent[node[dst->id]->prev] = dst->id;
		}
		else if (!node[dst->id]->in_way)
			f_enque(lemin->queue, node[dst->id]);
		lemin->links->marked[dst->id] = 1;
		lemin->parent[dst->id] = src->id;
	}
	else if ((dst->vol == 2 && dst->id != lemin->start) || \
			(dst->vol == 1 && !node[dst->id]->in_way))
	{
		f_enque(lemin->queue, node[dst->id]);
		lemin->links->marked[dst->id] = 1;
		lemin->parent[dst->id] = src->id;
	}
}

t_way			*srch_way(t_lem *lemin, t_node *src)
{
	t_node *temp;

	f_enque(lemin->queue, src);
	lemin->parent[src->id] = -1;
	while (lemin->queue->back != -1)
	{
		src = f_deque(lemin->queue);
		lemin->links->marked[src->id] = 1;
		temp = lemin->links->neighbor[src->id];
		while (temp)
		{
			if (lemin->links->marked[temp->id] == 0)
			{
				if (temp->id == lemin->final)
				{
					lemin->parent[temp->id] = src->id;
					return (f_reway(lemin));
				}
				f_addque(lemin, src, temp);
			}
			temp = temp->next;
		}
	}
	return (NULL);
}
