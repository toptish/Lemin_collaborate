/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 19:25:48 by ophuong           #+#    #+#             */
/*   Updated: 2020/10/03 21:51:59 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int		min_way(t_lem *lemin, t_way **ways)
{
	int	w_a;
	int	w_b;

	if (!ways[0] || !lemin->ways[0])
		return (!ways[0] ? 0 : 1);
	w_a = chk_stream(lemin->ways, lemin->ants);
	w_b = chk_stream(ways, lemin->ants);
	if (w_b < w_a)
		return (1);
	return (0);
}

static t_way	*add_way(t_lem *lemin, t_node *cur)
{
	t_way *way;

	if (!(way = malloc(sizeof(t_way))))
		ft_error(lemin, ERR);
	way->len = 0;
	ft_bzero(way->node, sizeof(t_node *) * 256);
	way->node[way->len++] = lemin->rooms->start;
	if ((way->node[way->len++] = cur)->id == lemin->final)
		return (way);
	cur = lemin->links->neighbor[cur->id];
	while (cur)
	{
		if (cur->vol == 0)
		{
			way->node[way->len++] = cur;
			if (cur->id == lemin->final)
				return (way);
			cur = lemin->links->neighbor[cur->id];
		}
		else
			cur = cur->next;
	}
	free(way);
	return (NULL);
}

static t_way	**look_ways(t_lem *lemin, t_way **ways)
{
	t_node	*start;
	int		i;

	i = 0;
	start = lemin->links->neighbor[lemin->start];
	while (start)
	{
		if ((ways[i] = add_way(lemin, start)))
			i++;
		start = start->next;
	}
	ways[i] = NULL;
	if (min_way(lemin, ways))
	{
		ways_free(lemin->ways);
		return (ways);
	}
	ways_free(ways);
	return (NULL);
}

static void		srch_shortway(t_lem *lemin, t_node *start)
{
	t_way	*ways[lemin->size + 1];
	t_way	*temp;
	int		size;

	rst_graph(lemin);
	size = sizeof(t_way *) * (lemin->size + 1);
	if ((temp = srch_way(lemin, start)))
	{
		regraph(lemin, temp, SET);
		if (look_ways(lemin, ways))
		{
			ft_memcpy(lemin->ways, ways, size);
			set_atr(lemin, lemin->ways);
			free(temp);
		}
		else
		{
			regraph(lemin, temp, DEL);
			free(temp);
			return ;
		}
		srch_shortway(lemin, lemin->rooms->start);
	}
}

void			ways_get(t_lem *lemin)
{
	int		marked[lemin->rooms->all];
	int		parent[lemin->rooms->all];
	t_node	*start;
	t_que	queue;

	ft_bzero(&marked, sizeof(marked));
	ft_bzero(&parent, sizeof(parent));
	lemin->queue = &queue;
	lemin->parent = parent;
	lemin->links->marked = marked;
	if (!(lemin->ways = malloc(sizeof(t_way*) * (lemin->size + 1))))
		ft_error(lemin, ERR);
	ft_bzero(lemin->ways, sizeof(t_way*) * (lemin->size + 1));
	start = lemin->links->neighbor[lemin->start];
	while (start)
	{
		lemin->node[start->id]->start = 1;
		start = start->next;
	}
	srch_shortway(lemin, lemin->rooms->start);
	if (!(*lemin->ways))
		ft_error(lemin, NOWAYS);
	way_sort(lemin->ways);
}
