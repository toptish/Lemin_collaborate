/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 12:25:08 by ophuong           #+#    #+#             */
/*   Updated: 2020/10/03 09:54:24 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		way_sort(t_way **ways)
{
	t_way	*temp;
	int		i;
	int		o;

	i = -1;
	while (ways[++i])
	{
		o = -1;
		while (ways[++o])
		{
			if (ways[o + 1] && ways[o]->len > ways[o + 1]->len)
			{
				temp = ways[o];
				ways[o] = ways[o + 1];
				ways[o + 1] = temp;
			}
		}
	}
}

static void	print_map(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(STDOUT_FILENO, &str[i][0], ft_strlen(str[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	write(STDOUT_FILENO, "\n", 1);
}

int			main(int argc, char **argv)
{
	t_lem	lem_in;

	ft_bzero(&lem_in, sizeof(t_lem));
	if (argc > 1)
	{
		if (!input_arg(&lem_in, argv))
			return (0);
	}
	if (lem_in.opc & OHELP)
		return (output_usage(argv[0]));
	if (!(lem_in.str = l_read(&lem_in)))
		ft_error(&lem_in, ERR);
	l_init(&lem_in);
	ways_get(&lem_in);
	print_map(lem_in.str);
	lem_in.size = lem_in.ants;
	lem_in.c = 0;
	l_move(&lem_in);
	output_arg(&lem_in);
	lemin_free(&lem_in);
	return (EXIT_SUCCESS);
}
