/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 12:25:08 by ophuong           #+#    #+#             */
/*   Updated: 2020/10/03 21:55:19 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int		size_way(t_lem *lemin)
{
	t_node	*temp;
	int		l;

	l = 0;
	temp = lemin->links->neighbor[lemin->start];
	while (temp)
	{
		temp = temp->next;
		l++;
	}
	return (l);
}

static int		chk_node(t_node **node)
{
	int		i;
	int		o;
	int		n;

	i = -1;
	while (node[++i])
	{
		n = i;
		o = -1;
		while (node[++o])
		{
			if (o != n && !ft_strcmp(node[o]->name, node[n]->name))
				return (DUPROOM);
			if (o != n && (node[o]->x == node[n]->x) && \
					(node[o]->y == node[n]->y))
				return (DUPCOORD);
		}
	}
	return (0);
}

/*
**	creates and returns a new node structure array
*/

static t_node	**new_node(t_rms *room)
{
	t_node	*head;
	t_node	**node;

	if (!room)
		return (NULL);
	head = room->head;
	if (!(node = malloc(sizeof(t_node *) * (room->all + 1))))
		return (NULL);
	while (head)
	{
		node[head->id] = head;
		head = head->next;
	}
	node[room->all] = NULL;
	head = NULL;
	return (node);
}

/*
**	checks for errors and initiates lemin structure from input
*/

void			l_init(t_lem *lemin)
{
	int red;

	if (!(red = read_ants(lemin, lemin->str)))
		ft_error(lemin, ANTSERROR);
	lemin->rooms = read_rooms(lemin, lemin->str);
	if (!(lemin->node = new_node(lemin->rooms)))
		ft_error(lemin, ERR);
	if ((red = chk_node(lemin->node)) > 0)
		ft_error(lemin, red);
	lemin->links = read_links(lemin, lemin->str);
	if (lemin->str[lemin->c])
		ft_error(lemin, LINEERROR);
	if (!lemin->rooms->head)
		ft_error(lemin, NOARG);
	lemin->size = size_way(lemin);
	if (!lemin->rooms->start || !lemin->rooms->end)
		ft_error(lemin, NOTSRCSINK);
	lemin->final = lemin->rooms->end->id;
	lemin->start = lemin->rooms->start->id;
}
