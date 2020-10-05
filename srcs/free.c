/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 12:25:08 by ophuong           #+#    #+#             */
/*   Updated: 2020/10/03 21:45:21 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

/*
**	free ways (paths)
*/

void	ways_free(t_way **ways)
{
	int i;

	if (ways)
	{
		i = -1;
		while (ways[++i])
			free(ways[i]);
	}
}

/*
**	free links (edges)
*/

void	links_free(t_lnk *links, int size)
{
	t_node	*neib;
	t_node	*temp;
	int		i;

	i = -1;
	temp = NULL;
	neib = NULL;
	while (++i < (size + 1))
	{
		neib = links->neighbor[i];
		while (neib)
		{
			temp = neib;
			neib = neib->next;
			temp->name = NULL;
			free(temp);
		}
		links->neighbor[i] = NULL;
	}
	free(links->neighbor);
	links->marked = NULL;
}

/*
**	free rooms
*/

void	rooms_free(t_rms *rooms)
{
	t_node *temp;

	temp = NULL;
	while (rooms->head)
	{
		temp = rooms->head;
		rooms->head = rooms->head->next;
		free(temp->name);
		temp->name = NULL;
		free(temp);
	}
	rooms->head = NULL;
	rooms->start = NULL;
	rooms->end = NULL;
	temp = NULL;
}

/*
**	free lemin structure
*/

void	lemin_free(t_lem *lemin)
{
	if (lemin->ways)
	{
		ways_free(lemin->ways);
		free(lemin->ways);
	}
	if (lemin->str)
	{
		free((*lemin->str));
		free(lemin->str);
	}
	if (lemin->rooms)
	{
		rooms_free(lemin->rooms);
		free(lemin->rooms);
	}
	if (lemin->links)
	{
		links_free(lemin->links, lemin->rooms->all);
		free(lemin->links);
	}
	if (lemin->node)
		free(lemin->node);
}
