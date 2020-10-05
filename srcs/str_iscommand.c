/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_iscommand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 21:54:45 by gdorcas           #+#    #+#             */
/*   Updated: 2020/10/03 21:54:52 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

/*
**	reads line and checks for ##start or ##end command
*/

int	str_iscommand(char *str)
{
	if (str[0] == '#')
	{
		if (str[1] == '#')
		{
			if (!ft_strcmp(str, "##start"))
				return (START);
			else if (!ft_strcmp(str, "##end"))
				return (END);
		}
		return (1);
	}
	return (0);
}
