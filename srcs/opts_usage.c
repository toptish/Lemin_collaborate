/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts_usage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 12:25:08 by ophuong           #+#    #+#             */
/*   Updated: 2020/10/03 21:53:38 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void	output_flow(t_way **ways)
{
	int i;
	int o;

	i = -1;
	ft_printf("\n\e[95m-----=== Way[ length ][ ants ] ===-----\e[0m\n");
	while (ways[++i])
	{
		o = -1;
		ft_printf("\e[95mWays[%d][%d]\e[0m", ways[i]->len - 1, ways[i]->s_t);
		while (++o < ways[i]->len)
			ft_printf(" %s", ways[i]->node[o]->name);
		ft_printf("\n");
	}
}

static void	output_ways(t_way **ways)
{
	int i;
	int o;

	i = -1;
	ft_printf("\n\e[93m-------=== Ways[ length ] ===-------\e[0m\n");
	while (ways[++i])
	{
		o = -1;
		ft_printf("\e[93mWays[%d]:\e[0m", ways[i]->len - 1);
		while (++o < ways[i]->len)
			ft_printf(" %s", ways[i]->node[o]->name);
		ft_printf("\n");
	}
}

int			output_usage(char *prg)
{
	ft_printf("\e[1mUsage:\e[0m\n");
	ft_printf("%s [-h] [-l] [-e] [-w] [-f] < maps/file.map\n", prg);
	ft_printf("\e[1mOptions:\e[0m\n");
	ft_printf("   -h : Lem-in manual.\n");
	ft_printf("   -l : Print line counter.\n");
	ft_printf("   -e : Detailed error description.\n");
	ft_printf("   -w : Print ways.\n");
	ft_printf("   -f : Print ant flows.\n");
	return (0);
}

/*
**	prints
**	store options in lemin.opc
*/

void		output_arg(t_lem *lemin)
{
	if (lemin->opc & OPT_L)
	{
		ft_printf("\n\e[92m-------=== Number of lines ===-------\n");
		ft_printf("%20d\e[0m\n", lemin->c);
	}
	if (lemin->opc & OPT_W)
		output_ways(lemin->ways);
	if (lemin->opc & OPT_F)
		output_flow(lemin->ways);
}

/*
**	checks wether the program is ran with options
**	store options in lemin.opc
*/

int			input_arg(t_lem *lemin, char **str)
{
	int i;

	i = 0;
	if (str[1][i] == '-')
	{
		while (str[1][++i])
		{
			if (str[1][i] == 'h')
				lemin->opc |= OHELP;
			else if (str[1][i] == 'l')
				lemin->opc |= OPT_L;
			else if (str[1][i] == 'e')
				lemin->opc |= OPT_E;
			else if (str[1][i] == 'w')
				lemin->opc |= OPT_W;
			else if (str[1][i] == 'f')
				lemin->opc |= OPT_F;
			else
				return (output_usage(str[0]));
		}
	}
	if (lemin->opc > 0)
		return (1);
	return (output_usage(str[0]));
}
