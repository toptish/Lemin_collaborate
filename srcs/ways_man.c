/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways_man.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:28:26 by ophuong           #+#    #+#             */
/*   Updated: 2020/10/03 21:49:23 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	rst_graph(t_lem *lemin)
{
	lemin->queue->front = -1;
	lemin->queue->back = -1;
	ft_bzero(lemin->parent, sizeof(int) * lemin->rooms->all);
	ft_bzero(lemin->links->marked, sizeof(int) * lemin->rooms->all);
}

int		chk_stream(t_way **ways, int ants)
{
	int		len;
	float	stream_a;
	float	stream_b;
	int		c;

	len = 0;
	c = 0;
	stream_a = INT32_MAX;
	stream_b = INT32_MAX;
	while (ways[c])
	{
		len += ways[c++]->len - 1;
		stream_a = ((float)len + ants - 1) / c;
		if (stream_a < stream_b)
			stream_b = stream_a;
		else
			break ;
	}
	return (stream_b);
}

void	set_vol(t_lem *lemin, t_node *src, t_node *dst, int set)
{
	t_node *temp;

	temp = lemin->links->neighbor[src->id];
	while (temp)
	{
		if (temp->id == dst->id)
		{
			temp->vol += set;
			break ;
		}
		temp = temp->next;
	}
}

void	set_atr(t_lem *lemin, t_way **ways)
{
	t_node	**node;
	int		i;
	int		o;

	i = -1;
	node = lemin->node;
	while (lemin->node[++i])
	{
		node[i]->in_way = 0;
		node[i]->prev = -1;
	}
	i = -1;
	while (ways[++i])
	{
		o = 0;
		while (ways[i]->node[o])
		{
			node[ways[i]->node[o++]->id]->in_way = 1;
			if (ways[i]->node[o])
				node[ways[i]->node[o]->id]->prev = \
									ways[i]->node[o - 1]->id;
		}
	}
}

void	regraph(t_lem *lemin, t_way *way, int set)
{
	t_node	**node;
	int		len;

	len = way->len;
	node = way->node;
	while (len--)
	{
		if (set == SET && (len - 1) >= 0)
		{
			set_vol(lemin, node[len], node[len - 1], DECREASE);
			set_vol(lemin, node[len - 1], node[len], INCREASE);
		}
		else if (set == DEL && (len - 1) >= 0)
		{
			set_vol(lemin, node[len], node[len - 1], INCREASE);
			set_vol(lemin, node[len - 1], node[len], DECREASE);
		}
	}
}
