/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:28:26 by ophuong           #+#    #+#             */
/*   Updated: 2020/10/03 21:52:23 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int		chk_id(t_node *head, char *room)
{
	while (head)
	{
		if (!ft_strcmp(room, head->name))
			return (head->id);
		head = head->next;
	}
	return (-1);
}

t_node			*room_cpy(t_node *room)
{
	t_node *temp;

	if (!room)
		return (NULL);
	if (!(temp = malloc(sizeof(t_node))))
		return (NULL);
	temp->name = room->name;
	temp->vol = room->vol;
	temp->ant = room->ant;
	temp->id = room->id;
	temp->x = room->x;
	temp->y = room->y;
	temp->next = NULL;
	return (temp);
}

static t_lnk	*plus_links(t_lnk *links, t_node **node, int src, int dst)
{
	t_node *newroom;

	if ((newroom = room_cpy(node[dst])) == NULL)
		return (NULL);
	newroom->next = links->neighbor[src];
	links->neighbor[src] = newroom;
	if ((newroom = room_cpy(node[src])) == NULL)
		return (NULL);
	newroom->next = links->neighbor[dst];
	links->neighbor[dst] = newroom;
	return (links);
}

static t_lnk	*new_links(t_lem *lemin, char *str)
{
	int		id_room[2];
	char	**room;

	if ((room = ft_strsplit(str, '-')) == NULL)
		return (NULL);
	id_room[0] = chk_id(lemin->rooms->head, room[0]);
	id_room[1] = chk_id(lemin->rooms->head, room[1]);
	if (id_room[0] == -1 || id_room[1] == -1)
		ft_error(lemin, LINKERROR);
	if (!(plus_links(lemin->links, lemin->node, id_room[0], id_room[1])))
	{
		ft_clr_sqare((void **)room);
		free(room);
		return (NULL);
	}
	ft_clr_sqare((void **)room);
	free(room);
	return (lemin->links);
}

t_lnk			*read_links(t_lem *lemin, char **str)
{
	int size;

	size = lemin->rooms->all + 1;
	if (!(lemin->links = malloc(sizeof(t_lnk))))
		ft_error(lemin, ERR);
	if (!(lemin->links->neighbor = malloc(sizeof(t_node *) * size)))
		ft_error(lemin, ERR);
	ft_bzero(lemin->links->neighbor, sizeof(t_node *) * size);
	while (str[lemin->c])
	{
		if (str_iscommand(str[lemin->c]) == 1)
			;
		else if (str_islink(str[lemin->c]))
		{
			if (!new_links(lemin, str[lemin->c]))
				ft_error(lemin, ERR);
		}
		else
			break ;
		lemin->c++;
	}
	return (lemin->links);
}
