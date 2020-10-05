/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 02:25:08 by ophuong           #+#    #+#             */
/*   Updated: 2020/10/03 21:47:06 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

/*
**	reads input and checks wether ants num is valid
*/

int	read_ants(t_lem *lemin, char **str)
{
	int red;

	red = 0;
	while (str[lemin->c])
	{
		if (str_iscommand(str[lemin->c]) == 1)
			;
		else if ((red = str_isant(str[lemin->c])))
		{
			lemin->ants = ft_atoi(str[lemin->c]);
			if (lemin->ants > MAX_ANTS)
				ft_error(lemin, ANTOVERFLOW);
			else if (lemin->ants == 0 && red > 1)
				ft_error(lemin, ANTSERROR);
			return (lemin->ants);
		}
		else
			break ;
		lemin->c++;
	}
	return (0);
}
