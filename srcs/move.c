/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 10:05:08 by ophuong           #+#    #+#             */
/*   Updated: 2020/10/03 21:50:43 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void		set_stream(t_lem *lemin, int stream)
{
	int	stream_ant;
	int	ants;
	int	i;

	i = 0;
	stream_ant = 0;
	ants = lemin->ants;
	while (lemin->ways[i])
	{
		lemin->ways[i]->stream = 0;
		stream_ant = stream - lemin->ways[i]->len + 2;
		if (stream_ant < ants)
			lemin->ways[i]->stream = stream_ant;
		else
			lemin->ways[i]->stream = ants;
		ants -= lemin->ways[i]->stream;
		i++;
	}
	i = -1;
	while (lemin->ways[++i])
		lemin->ways[i]->s_t = lemin->ways[i]->stream;
}

static t_node	*ant_next(t_lem *lemin, t_node *ants)
{
	t_node *temp;

	if (ants->id == lemin->final)
		return (ants);
	temp = lemin->links->neighbor[ants->id];
	while (temp)
	{
		if (temp->vol == 0)
		{
			ants = temp;
			ants->ant = 1;
			break ;
		}
		temp = temp->next;
	}
	return (ants);
}

static void		let_start(t_lem *lemin, t_node **ants)
{
	t_node	*start;
	int		i;
	int		o;

	i = -1;
	while (lemin->ways[++i])
	{
		if (lemin->ways[i]->stream > 0)
		{
			o = -1;
			start = lemin->links->neighbor[lemin->start];
			while (lemin->ways[i]->node[1]->id != start->id)
				start = start->next;
			while (++o < lemin->ants)
				if (!ants[o] && (!start->ant || start->id == lemin->final))
				{
					ants[o] = start;
					ants[o]->ant = 1;
					lemin->ways[i]->stream--;
					if (start->id != lemin->final)
						break ;
				}
		}
	}
}

void			l_move(t_lem *lemin)
{
	t_node	*ants[lemin->ants + 1];
	int		final[lemin->ants];
	int		i;

	ft_bzero(final, sizeof(int) * lemin->ants);
	ft_bzero(ants, sizeof(t_node *) * (lemin->ants + 1));
	set_stream(lemin, chk_stream(lemin->ways, lemin->ants));
	while (lemin->size)
	{
		i = -1;
		let_start(lemin, ants);
		while (ants[++i])
		{
			if (ants[i]->ant && !final[i])
			{
				ft_printf("L%d-%s ", i + 1, ants[i]->name);
				ants[i]->id != lemin->final ? (ants[i]->ant = 0) : 0;
				ants[i]->id == lemin->final ? (final[i] = 1) : 0;
				ants[i]->id == lemin->final ? lemin->size-- : 0;
				ants[i] = ant_next(lemin, ants[i]);
			}
		}
		lemin->c++;
		ft_printf("\n");
	}
}
