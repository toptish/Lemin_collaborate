/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 16:25:08 by ophuong           #+#    #+#             */
/*   Updated: 2020/10/03 21:51:46 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int		check_command(t_rms *rooms, int red)
{
	if ((red == START && rooms->start) || (red == END && rooms->end))
		return (DUPCOMM);
	rooms->r = red;
	return (red);
}

static t_node	*room_set(t_lem *lemin, t_node *room, char *str)
{
	char **temp;

	if (!(temp = ft_strsplit(str, ' ')))
		return (NULL);
	if (!(room->name = ft_strdup(temp[0])))
	{
		ft_clr_sqare((void **)temp);
		free(temp);
		return (NULL);
	}
	room->x = ft_atoi(temp[1]);
	room->y = ft_atoi(temp[2]);
	room->ant = 0;
	room->vol = 1;
	room->start = 0;
	room->in_way = 0;
	room->id = lemin->rid++;
	ft_clr_sqare((void **)temp);
	free(temp);
	temp = NULL;
	return (room);
}

static t_rms	*create_room(t_lem *lemin, t_rms *rooms, char *str)
{
	t_node *temp;

	if (!(temp = malloc(sizeof(t_node))))
		return (NULL);
	if (room_set(lemin, temp, str) == NULL)
	{
		free(temp);
		return (NULL);
	}
	if (rooms->r == START)
		rooms->start = temp;
	else if (rooms->r == END)
		rooms->end = temp;
	temp->next = rooms->head;
	rooms->head = temp;
	rooms->all++;
	rooms->r = 0;
	return (rooms);
}

static void		init_rooms(t_rms *rooms)
{
	rooms->head = NULL;
	rooms->start = NULL;
	rooms->end = NULL;
	rooms->all = 0;
	rooms->r = 0;
}

t_rms			*read_rooms(t_lem *lemin, char **str)
{
	int	red;

	if (!(lemin->rooms = malloc(sizeof(t_rms))))
		ft_error(lemin, ERR);
	init_rooms(lemin->rooms);
	while (str[++lemin->c])
	{
		if ((red = str_iscommand(str[lemin->c])))
		{
			if (check_command(lemin->rooms, red) == DUPCOMM)
				ft_error(lemin, DUPCOMM);
		}
		else if (str_isroom(str[lemin->c]))
		{
			if (!create_room(lemin, lemin->rooms, str[lemin->c]))
				ft_error(lemin, ERR);
		}
		else
			break ;
	}
	return (lemin->rooms);
}
